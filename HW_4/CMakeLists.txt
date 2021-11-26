add_executable(hashtable
        main.c
        src/linked_list.c include/linked_list.h
        src/hash_table.c include/hash_table.h
        src/payload.c include/payload.h
        src/hash_functions.c include/hash_functions.h
        src/binary_tree.c include/binary_tree.h src/utils.c include/utils.h)
set_target_properties(hashtable PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../HW_4/")



