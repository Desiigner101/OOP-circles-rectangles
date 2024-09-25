#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *arr;
    int size;
    float sum;
    float average;
};

void scanArray(struct Array *array);
void printArray(struct Array *array);
float findAverage(struct Array *array);

int main(){

    struct Array array;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    array.arr = (int *)malloc(array.size * sizeof(int));

    printf("Enter the elements of the array:\n");
    scanArray(&array);

    printf("\nThe elements of the array:\n");
    printArray(&array);

    float getAverage = findAverage(&array);
    printf("\n\nThe average value of the array: %.2f", getAverage);

    free(array.arr);
    return 0;
}

void scanArray(struct Array *array){
    int i;

    for(i = 0; i < array->size; i++){
        scanf("%d", &array->arr[i]);
    }
}

void printArray(struct Array *array){
    int i;

    for(i = 0; i < array->size; i++){
        printf("%d ", array->arr[i]);
    }
}

float findAverage(struct Array *array){
    int i;
    array->sum = 0;

    for(i = 0; i < array->size; i++){
        array->sum += array->arr[i];
    }
    array->average = array->sum / array->size;

    return array->average;
}