#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *arr;
    int size;
    int newElement;
    int index;
};

void addElementAt(struct Array *array);

int main(){
    struct Array array;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    array.arr = (int *)malloc(array.size * sizeof(int));

    if((array.arr == NULL)){
        printf("Memory allocation failed...");
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

    printf("\n\nEnter and element: ");
    scanf("%d", &array.newElement);
    printf("Enter an index (0 to %d): ", array.size);
    scanf("%d", &array.index);

    addElementAt(&array);
    printf("\n\nThe updated array:\n");
    for(i = 0; i < array.size; i++){
        printf("%d ", array.arr[i]);
    }

    free(array.arr);
    return 0;
}


void addElementAt(struct Array *array){
    int i;

    for(i = array->size; i > array->index; i--){
        array->arr[i] = array->arr[i - 1];
    }

    array->arr[array->index] = array->newElement;
    array->size++;
}