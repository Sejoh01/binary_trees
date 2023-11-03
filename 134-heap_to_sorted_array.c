#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array-integer.
 *
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: Sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size) {
    int *sorted_array;
    size_t array_size = 0, i;

    if (!heap || !size) return (NULL);
    array_size = heap_size(heap);
    sorted_array = malloc(sizeof(int) * array_size);
    if (!sorted_array) return (NULL);

    for (i = 0; i < array_size; i++) {
        sorted_array[i] = heap->n;
        heap_extract(&heap);
    }
    *size = array_size;
    return (sorted_array);
}
