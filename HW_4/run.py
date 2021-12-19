#! /usr/bin/env python

import os
import itertools
import subprocess as sp

from queue import Queue
from threading import Thread
from collections import OrderedDict
from multiprocessing import cpu_count
# from pprint import pprint


# ==============================


def run_hash(parameters):
    tasks_queue = Queue()
    for param in parameters:
        tasks_queue.put(param)

    output_buffer = OrderedDict.fromkeys(list(x for x in parameters), '')

    for i in range(cpus):
        thread = Thread(target=hash_thread, args=(i, tasks_queue, output_buffer))
        thread.daemon = True
        thread.start()
    tasks_queue.join()

    with open('results_hash.md', 'w') as hash_results:
        file = ''
        table = '|function|buckets|time|num_non_empty_buckets|min_in_bucket|max_in_bucket|mean_in_bucket|\n' \
                '|---|---|---|---|---|---|---|'
        for key, value in output_buffer.items():
            if (f := os.path.basename(key[0])) != file:
                file = f
                print(f'\n## {file}\n{table}', file=hash_results)

            print(value, file=hash_results)


def hash_thread(id_, queue, output_buffer):
    while True:
        param = queue.get()
        answer, in_f, out_f, hash_function, hashtable_size = [str(x) for x in param]
        out_f = out_f.replace('.txt', f'_thread_{str(id_)}.txt')
        try:
            out = sp.run([hash_executable, hashtable_size, hash_function, in_f, out_f],
                         timeout=timeout, capture_output=True, text=True)

            if out.returncode:
                print(out)
                raise AssertionError

            if diff_command:
                diff = sp.run([*diff_command, answer, out_f])
                if diff.returncode:
                    print(f'{out}')
                    output_buffer[param] = '|{}|{}|diff| | | | |'.format(function_names[param[3]], param[4])
                    raise AssertionError

            output_buffer[param] = '|{}|{}|{}|{}|{}|{}|{}|'.format(function_names[param[3]], param[4],
                                                                   *out.stdout.split())
        except sp.TimeoutExpired:
            output_buffer[param] = '|{}|{}|{}| | | | |'.format(function_names[param[3]], param[4], '\>' + str(timeout))
        except AssertionError:
            pass
        finally:
            queue.task_done()


def run_tree(files):
    with open('results_tree.md', 'w') as tree_results:
        for answer, in_f, out_f in files:
            print('## {}\n|time|min_depth|max_depth|mean_depth|\n|---|---|---|---|'.format(os.path.basename(in_f)), file=tree_results)
            try:
                out_f = out_f.replace('/hash_output/', '/tree_output/')
                tree = sp.run([tree_executable, in_f, out_f], timeout=timeout, capture_output=True, text=True)
                if tree.returncode:
                    print(tree)
                    continue

                if diff_command:
                    diff = sp.run([*diff_command, answer, out_f])
                    if diff.returncode:
                        print(f'{diff}\n{tree}')
                        continue

                print('|{}|{}|{}|{}|\n'.format(*tree.stdout.split()), file=tree_results)
            except sp.TimeoutExpired:
                print('|{}| | | |\n'.format(os.path.basename(in_f), f'\>{timeout}', file=tree_results))


# ==============================


def remove_punctuation(in_f, out_f):
    with open(in_f, 'r') as f_in, open(out_f, 'w') as f_out:
        for line in f_in:
            print(''.join(filter(lambda x: x.isalnum() or x.isspace(), line)).lower(), end='', file=f_out)


def count_words(in_f, out_f):
    dictionary = {}

    with open(in_f, 'r') as f_in:
        data = f_in.read().split()
        for x in data:
            dictionary[x] = dictionary.get(x, 0) + 1

    with open(out_f, 'w') as f_out:
        for k, v in sorted(dictionary.items(), key=lambda x: x[0]):
            print(k, v, file=f_out)


def texts():
    f = [('./texts/raw/' + f, './texts/alphanumeric/' + f) for f in os.listdir('./texts/raw/') if
         f not in os.listdir('./texts/alphanumeric/')]
    for input_file, output_file in f:
        remove_punctuation(input_file, output_file)

    f = [('./texts/raw/' + f, './texts/py_output/raw/' + f) for f in os.listdir('./texts/raw/') if
         f not in os.listdir('./texts/py_output/raw/')]
    for input_file, output_file in f:
        count_words(input_file, output_file)

    f = [('./texts/alphanumeric/' + f, './texts/py_output/alphanumeric/' + f) for f in
         os.listdir('./texts/alphanumeric/') if
         f not in os.listdir('texts/py_output/alphanumeric/')]
    for input_file, output_file in f:
        count_words(input_file, output_file)


# ==============================


if __name__ == '__main__':
    # texts()

    cpus = cpu_count()
    timeout = 150  # Максимально время выполнения каждого тестового запуска в секундах
    hash_executable = './hash.out'
    tree_executable = './tree.out'
    diff_command = ['diff', '-q']  # Или аналог, возвращающий 0 если файлы одинаковы, заменить на False если не нужно проверять правильность вывода
    source = 'alphanumeric/'  # Подпапка папки texts из которой берутся входные файлы, можно докидывать свои
    # source = 'raw/'
    hashtable_sizes = [1, 10, 100, 1000, 10000]
    hash_functions = [x for x in range(5)]
    function_names = {0: 'CONSTANT', 1: 'FIRST_CHAR', 2: 'WORD_LENGTH', 3: 'CHAR_SUM', 4: 'DJB2'}
    files = [('./texts/py_output/' + source + f, './texts/' + source + f, './texts/hash_output/' + f) for f in
             os.listdir('./texts/' + source)]

    # Константа только с таблицей размера 1, остальные с размером >1
    parameters = list(filter(lambda x: (not x[3] and x[4] == 1) or (x[3] and x[4] > 1),
                             ((*x[0], x[1], x[2]) for x in itertools.product(files, hash_functions, hashtable_sizes))))

    run_hash(parameters)
    run_tree(files)
