#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int size);

int main(){

    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if(arr == NULL){
        printf("Memory Allocation Failed..");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);
    printf("\nThe reversed elements:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

void reverseArray(int *arr, int size){
    int i, temp;

    for(i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}