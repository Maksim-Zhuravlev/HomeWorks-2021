add_executable(hash.out
        src/hash.c
        src/linked_list.c include/linked_list.h
        src/hash_table.c include/hash_table.h
        src/payload.c include/payload.h
        src/hash_functions.c include/hash_functions.h
        src/utils.c include/utils.h)
add_executable(tree.out
        src/tree.c
        src/payload.c include/payload.h
        src/binary_tree.c include/binary_tree.h
        src/utils.c include/utils.h)

set_target_properties(hash.out PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../HW_4/")
set_target_properties(tree.out PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../HW_4/")



