#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int initial_size = 5, new_size = 10;
    
    // Allocate memory for an initial array of 5 integers
    arr = (int *)malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array with some values
    for (int i = 0; i < initial_size; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }
    
    // Resize the array to hold 10 integers
    arr = (int *)realloc(arr, new_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initialize the newly allocated part of the array
    for (int i = initial_size; i < new_size; i++) {
        arr[i] = i * 10;
    }

    // Print the resized array
    printf("\nResized array:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }

    // Free the dynamically allocated memory
    free(arr);
    return 0;
}