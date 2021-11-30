import os
import itertools
import subprocess as sp


# ==============================


def remove_punctuation(input_file, output_file):
    with open(input_file, 'r') as f_in, open(output_file, 'w') as f_out:
        for line in f_in:
            print(''.join(filter(lambda x: x.isalnum() or x.isspace(), line)).lower(), end='', file=f_out)


def count_words(input_file, output_file):
    dictionary = {}

    with open(input_file, 'r') as f_in:
        data = f_in.read().split()
        for x in data:
            dictionary[x] = dictionary.get(x, 0) + 1

    with open(output_file, 'w') as f_out:
        for k, v in sorted(dictionary.items(), key=lambda x: x[0]):
            print(k, v, file=f_out)


files = [('./texts/raw/' + f, './texts/alphanumeric/' + f) for f in os.listdir('./texts/raw/') if
         f not in os.listdir('./texts/alphanumeric/')]
for input_file, output_file in files:
    remove_punctuation(input_file, output_file)

files = [('./texts/raw/' + f, './texts/py_output/raw/' + f) for f in os.listdir('./texts/raw/') if
         f not in os.listdir('./texts/py_output/raw/')]
for input_file, output_file in files:
    count_words(input_file, output_file)

files = [('./texts/alphanumeric/' + f, './texts/py_output/alphanumeric/' + f) for f in os.listdir('./texts/alphanumeric/') if
         f not in os.listdir('texts/py_output/alphanumeric/')]
for input_file, output_file in files:
    count_words(input_file, output_file)


# ==============================


timeout = 60    # Максимально время выполнения каждого тестового запуска в секундах
hash_executable = './hash'
tree_executable = './tree'
diff_command = 'diff'   # Или аналог, возвращающий 0 если файлы одинаковы, заменить на False если не нужно проверять правильность вывода
source = 'alphanumeric/'    # Подпапка папки texts из которой берутся входные файлы, можно докидывать свои
# source = 'raw/'
hashtable_sizes = [1, 10, 100, 1000, 10000]
hash_functions = [x for x in range(5)]
function_names = {0: 'CONSTANT', 1: 'FIRST_CHAR', 2: 'WORD_LENGTH', 3: 'CHAR_SUM', 4: 'DJB2'}
files = [('./texts/py_output/' + source + f, './texts/' + source + f, './texts/hash_output/' + f) for f in
         os.listdir('./texts/' + source)]

# Константа только с таблицей размера 1, остальные с размером >1
parameters = filter(lambda x: (not x[3] and x[4] == 1) or (x[3] and x[4] > 1),
                    ((*x[0], x[1], x[2]) for x in itertools.product(files, hash_functions, hashtable_sizes)))


# ==============================


with open('results_hash.md', 'w') as results:
    file = ''
    table = '| function | buckets | time | num_non_empty_buckets | min_in_bucket | max_in_bucket | mean_in_bucket |\n' \
            '|---|---|---|---|---|---|---|'

    for param in parameters:
        if (f := os.path.basename(param[0])) != file:
            file = f
            print(f'\n## {file}', file=results)
            print(table, file=results)

        try:
            out = sp.run([hash_executable, *[str(param[x]) for x in (4, 3, 1, 2)]],
                         timeout=timeout, capture_output=True, text=True)
            if out.returncode:
                print(out)
                continue

            if diff_command:
                diff = sp.run([diff_command, param[0], param[2]])
                if diff.returncode:
                    print(f'{diff}\n{out}')
                    continue

            print('|{}|{}|{}|{}|{}|{}|{}|'.format(function_names[param[3]], param[4], *out.stdout.split()), file=results)
        except sp.TimeoutExpired:
            print('|{}|{}|{}| | | | |'.format(function_names[param[3]], param[4], '\>' + str(timeout)), file=results)


with open('results_tree.md', 'w') as results:
    for answer, input_file, output_file in files:
        try:
            output_file = output_file.replace('/hash_output/', '/tree_output/')
            tree = sp.run([tree_executable, input_file, output_file], timeout=timeout, capture_output=True, text=True)
            if tree.returncode:
                print(tree)
                continue

            if diff_command:
                diff = sp.run([diff_command, answer, output_file])
                if diff.returncode:
                    print(f'{diff}\n{tree}')
                    continue

            print('## {}\n| time | min_depth | max_depth | mean_depth |\n|---|---|---|---|\n| {} | {} | {} | {} |\n'.format(
                os.path.basename(input_file), *tree.stdout.split()), file=results)
        except sp.TimeoutExpired:
            print(f'{input_file} timeout expired')
