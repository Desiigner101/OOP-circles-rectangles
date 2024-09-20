#include <stdio.h>
#include <stdbool.h>
#include "header.h"

int main(){

    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements of the array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    

    int newElement, index, choice;

    printf("\nEnter an element to be added to the array: ");
    scanf("%d", &newElement);

    printf("Enter an index in where you want to insert (0 to %d): ", size);
    scanf("%d", &index);

    if(index < 0 || index > size){
        printf("Size is full..");
        return 1;
    }

    addElementAt(arr, &size, newElement, index);
    printf("\nThe updated array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    //APPLIED DATA STRUCT FUNCTIONS
    reverseArray(arr, size);
    printf("\n\nThe reversed array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);
    printf("\nThe sorted array:\n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter 1 to delete an element in the array and 0 to continue: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter a specific index (0 to %d): ", size - 1);
        scanf("%d", &index);

        deleteElementAt(arr, &size, index);
        printf("\nArray after deletion: ");
        for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
    }
    
    int getMax = findMax(arr, size);
    printf("\n\nThe maximum value is: %d", getMax);

    float average = getAverage(arr, size);
    printf("\nThe average value is: %.2f", average);

    float median = findMedian(arr, size);
    printf("\nThe median of the array is: %.2f", median);

    int value;
    bool found = false;
    printf("\nSearch an element in the array: ");
    scanf("%d", &value);

    int find = searchArray(arr, size, value, &found);

    if(found){
        printf("%d exists in the array!", value);
    }else{
        printf("%d does not exists in the array...", value);
    }
    
    return 0;
}