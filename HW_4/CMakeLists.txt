add_executable(hashtable
        main.c
        linked_list.c linked_list.h
        hash_table.c hash_table.h
        payload.c payload.h
        hash_functions.c hash_functions.h
)

add_executable(test test.c)