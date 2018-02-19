#pragma once

#include <stdint.h>
#include "arr.h"

typedef struct BinaryTree{
    int64_t data;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;

BinaryTree* bintree_new();
BinaryTree* bintree_from_arr(Array *arr);
BinaryTree* bst_from_arr(Array *arr);

Array* bintree_to_arr(BinaryTree *tree);

void bst_insert(BinaryTree *tree, int64_t val);
void bst_delete(BinaryTree *tree, int64_t val);

/*
 * process() is a callback with the following signature :
 * 
 * void process(int64_t value);
 *
 * which will be called each time various traversals
 * reach an item. One should use this method to perform
 * any operation on the item that is presently traversed,
 * i. e. printing the item to stdout.
 *
 */

void bintree_inorder(BinaryTree *tree, void (*process)(int64_t value));
void bintree_preorder(BinaryTree *tree, void (*process)(int64_t value));
void bintree_postorder(BinaryTree *tree, void (*process)(int64_t value));
void bintree_bfs(BinaryTree *tree, void (*process)(int64_t value));
void bintree_dfs(BinaryTree *tree, void (*process)(int64_t value));

/*
 * levelProcess will be passed (0, 1, <level>) for each new level
 *                             (<item>, 0, <level>) for each item
 *                             (-1, 0, 0) for end of traversal
 *
 * By checking the combination of the value of the arguments,
 * one can perform appropiate actions : for example, can print
 * "\nLevel %d" whenever a new level is occurred.
 * It is necessary to pass the end of traversal flag since
 * a "false" new level will be raised before the end of traversal,
 * as the end depends on getting two consecutive NULLs. One
 * can undo any preparation the program had made by seeing the
 * possibility of another level whenever the end of traversal
 * is flagged, for example one can print "\r      " to overwrite
 * the last "\nLevel %d" message in stdout.
 *
 */
void bintree_levelorder(BinaryTree *tree, void (*levelProcess)(int64_t value, uint8_t isNewLevel, uint64_t level));
