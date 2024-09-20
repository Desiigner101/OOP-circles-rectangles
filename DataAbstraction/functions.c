#include <stdio.h>
#include <stdbool.h>
#include "header.h"

void reverseArray(int *arr, int size){
    int i, temp;

    for(i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[size - i -1];
        arr[size - i - 1] = temp;
    }
}

void bubbleSort(int *arr, int size){
    int i, j, temp;

    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findMax(int *arr, int size){
    int i;
    int max = arr[0];

    for(i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

float getAverage(int *arr, int size){
    int i;
    int sum = 0;

    for(i = 0; i < size; i++){
        sum += arr[i];
    }

    float average = (float)sum / size;

    return average;
}

void addElementAt(int *arr, int *size, int newElement, int index){
    int i;

    for(i = *size; i > index; i--){
        arr[i] = arr[i - 1];
    }

    arr[index] = newElement;
    (*size)++;
 }

void deleteElementAt(int *arr, int *size, int index){
    int i;

    for(i = index; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

 float findMedian(int *arr, int size){
    if(size % 2 == 0){
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    }else{
        return arr[size / 2];
    }
 }

 int searchArray(int *arr, int size, int value, bool *found){
    int i;

    for(i = 0; i < size; i++){
        if(arr[i] == value){
            *found = true;
            break;
        }
    }

    return -1;
 }

 //LATEST APPLIED DATA STRUCTURES