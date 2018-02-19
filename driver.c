#include "bintree.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void print_val(int64_t value){
    printf(" %" PRId64, value);
}

void level_order_print(int64_t value, uint8_t isNewLevel, uint64_t level){
    if(isNewLevel){
        printf("\nLevel %2" PRIu64 " : ", level);
    }
    else if(value == -1 && isNewLevel == 0 && level == 0)
        printf("\r                                           ");
    else
        printf(" %" PRId64, value);
}

/*
 * args : <size_of_the_array> <random_order_type> <range>
 *
 *
 */
int main(int argc, char *argv[]){
    Array *arr;
    if(argc == 4){
        char *end;
        int64_t size = strtol(argv[1], &end, 10);
        if(size < 0){
            printf("\n[Error] Array size must be positive!\n");
            return 1;
        }
        int64_t type = strtol(argv[2], &end, 10);
        if(type < 1 || type > 3){
            printf("\n[Error] 1 <= type <= 3! [Given %" PRId64 "]\n", type);
            return 2;
        }
        int64_t range = strtol(argv[3], &end, 10);
        arr = arr_new(size);
        arr_gen_rand(arr, type, range);
    }
    else
        arr = arr_create();
    BinaryTree *bt = bst_from_arr(arr);
    printf("\nOriginal Tree : \n");
    bintree_levelorder(bt, &level_order_print);
    printf("\nAfter inorder traversal : ");
    bintree_inorder(bt, &print_val);
    printf("\n");
}
