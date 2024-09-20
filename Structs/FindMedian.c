#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *arr;
    int size;
};

float findMedian(struct Array *array);

int main(){
    struct Array array;
    int i;

    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    array.arr = (int *)malloc(array.size * sizeof(int));

    if(array.arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < array.size; i++){
        scanf("%d", &array.arr[i]);
    }

    printf("\n\nThe elements of the array:\n");
    for(i = 0; i < array.size; i++){
        printf("%d ", array.arr[i]);
    }

    float result = findMedian(&array);
    printf("\nThe median is: %.2f", result);
}

float findMedian(struct Array *array){
    if(array->size % 2 == 0){
        return (array->arr[array->size / 2] + array->arr[array->size / 2 - 1]) / 2.0;
    }else{
        return array->arr[array->size / 2];
    }
}