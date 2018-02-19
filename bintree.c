#include "bintree.h"
#include "utils.h"
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

BinaryTree* bintree_new(){
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    tree->data = 0;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

BinaryTree* bst_from_arr(Array *arr){
    BinaryTree *root = bintree_new();
    root->data = arr_at(arr, 0);
    uint64_t i = 1;
    while(i < arr_size(arr)){
        BinaryTree *p = root;
        BinaryTree *q = bintree_new();
        q->data = arr_at(arr, i);
        while(1){
            if(q->data <= p->data){
                if(p->left == NULL){
                    p->left = q;
                    break;
                }
                else
                    p = p->left;
            }
            else{
                if(p->right == NULL){
                    p->right = q;
                    break;
                }
                else
                    p = p->right;
            }
        }
        i++;
    }
    return root;
}

void bintree_levelorder(BinaryTree *tree, void (*process)(int64_t value, uint8_t isNewLevel, uint64_t level)){
    Queue *q = queue_new();
    enque(q, tree);
    enque(q, NULL);
    process(0, 1, 1);
    uint64_t level = 1;
    BinaryTree *prev = NULL;
    while(1){
        BinaryTree *p = (BinaryTree *)deque(q);
        if(p == NULL){
            if(prev == NULL)
                break;
            level++;
            process(0, 1, level);
            enque(q, NULL);
        }
        else{
            process(p->data, 0, level);
            if(p->left != NULL)
                enque(q, p->left);
            if(p->right != NULL)
                enque(q, p->right);
        }
        prev = p;
    }
    process(-1, 0, 0);
    queue_free(q);
}

void bintree_preorder(BinaryTree *tree, void (*process)(int64_t value)){
    if(tree != NULL){
        process(tree->data);
        bintree_preorder(tree->left, process);
        bintree_preorder(tree->right, process);
    }
}

void bintree_postorder(BinaryTree *tree, void (*process)(int64_t value)){
    if(tree != NULL){
        bintree_postorder(tree->left, process);
        bintree_postorder(tree->right, process);
        process(tree->data);
    }
}

void bintree_inorder(BinaryTree *tree, void (*process)(int64_t value)){
    if(tree != NULL){
        bintree_inorder(tree->left, process);
        process(tree->data);
        bintree_inorder(tree->right, process);
    }
}

void bintree_bfs(BinaryTree *tree, void (*process)(int64_t value)){
    Queue *q = queue_new();
    enque(q, tree);
    while(!queue_isEmpty(q)){
        BinaryTree *p = (BinaryTree *)deque(q);
        process(p->data);
        if(p->left != NULL)
            enque(q, p->left);
        if(p->right != NULL)
            enque(q, p->right);
    }
    queue_free(q);
}

void bintree_dfs(BinaryTree *tree, void (*process)(int64_t value)){
    if(tree != NULL){
        process(tree->data);
        bintree_dfs(tree->left, process);
        bintree_dfs(tree->right, process);
    }
}
