#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *arr;
    int size;
};

void reverseArray(struct Array *array);

int main(){
    struct Array array;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    array.arr = (int *)malloc(array.size * sizeof(int));

    if(array.arr == NULL){
        printf("The memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < array.size; i++){
        scanf("%d", &array.arr[i]);
    }

    printf("\nThe elements of the array:\n");
    for(i = 0; i < array.size; i++){
        printf("%d ", array.arr[i]);
    }

    reverseArray(&array);
    printf("\n\nThe reversed array:\n");
    for(i = 0; i < array.size; i++){
        printf("%d ", array.arr[i]);
    }

    free(array.arr);
    return 0;
}

void reverseArray(struct Array *array){
    int i, temp;

    for(i = 0; i < array->size / 2; i++){
        temp = array->arr[i];
        array->arr[i] = array->arr[array->size - i - 1];
        array->arr[array->size - i - 1] = temp;
    }
}