#include <stdio.h>
#include <stdlib.h>


void rotateArray(int *arr, int n, int k);
void printArray(int *arr, int n);
void scanArray(int *arr, int n);

int main(){

    int i, k, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("\nEnter the elements of the array:\n");
    scanArray(arr, n);

    printf("\nThe elements of the array: ");
    printArray(arr, n);
    
    printf("Enter the number of rotations: ");
    scanf("%d", &k);

    rotateArray(arr, n, k);
    printf("The rotated array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}

void rotateArray(int *arr, int n, int k){

    k = k % n;

    int temp[k];
    int i;

    for(i = 0; i < k; i++){
        temp[i] = arr[n - k + i];
    }

    for(i = n -1; i >= k; i--){
        arr[i] = arr[i - k];
    }

    for(i = 0; i < k; i++){
        arr[i] = temp[i];
    }
}

void scanArray(int *arr, int n){
    int i;

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    } //for scanning rani 
}

void printArray(int *arr, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    } //for printing the array

    printf("\n");
}