#pragma once

#include <stdint.h>

// Core array structure
typedef struct{
    int64_t *values; // Actual array
    uint64_t count; // Size of the array
} Array;

// Create an array solely by users choice of size and elements
Array* arr_create();

// Fill up an array with random items following the given
// order and range
// arr : Array to load
// type : Random input type
//      => 1 : Best Case (The array is pre-sorted in ascending order)
//      => 2 : Average Case (Elements are in random order)
//      => 3 : Worst Case (The array is pre-sorted in descending order)
// range : The maximum possible random number to generate
void arr_gen_rand(Array *arr, uint8_t type, int64_t range);

// Create an array with the specified size, with no inputs from the user
Array* arr_new(uint64_t count);

// Free a created array
void arr_free(Array *arr);

// Print an array
void arr_print(Array *arr);

// Swap two arrays
void arr_swap(Array *arr1, Array *arr2);

// Copy one array to the other
Array* arr_copy(Array *orig);

// Access an element of the array 'a' at 'i'th index
#define arr_at(a, i) a->values[i]

// Get the size of the array
#define arr_size(a) a->count

// Get the collection itself
#define arr_elements(a) a->values
