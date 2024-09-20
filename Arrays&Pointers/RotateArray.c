#include <stdio.h>
#include <stdlib.h>

void scanArray(int *arr, int n);
void printArray(int *arr, int n);
void reverseArray(int *arr, int n);
void rotateArrayByK(int *arr, int n, int k);

int main(){

    int i, n, k;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); 

    if(arr == NULL){
        printf("Memory allocation failed.."); 
        return 1;
    }

    printf("The elements of the array:\n");
    scanArray(arr, n);

    printf("\nThe elements of the array:\n");
    printArray(arr, n);

    printf("Enter the number of rotations: ");
    scanf("%d", &k);

    printf("Rotated array:\n");
    rotateArrayByK(arr, n, k);
    printArray(arr, n);

    free(arr); 
    return 0;
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

void reverseArray(int *arr, int n){
    int i, temp;

    for(i = 0; i < n / 2; i++){
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i- 1] = temp;
    }
}

void rotateArrayByK(int *arr, int n, int k){
    k = k % n;

    reverseArray(arr, n); //reverses the array first {1, 2, 3, 4, 5} -> {5, 4, 3, 2, 1}
    reverseArray(arr, k); //reverses the k elements {5, 4, 3, 2, 1} -> {4, 5, 3, 2, 1}
    reverseArray(arr + k, n - k); //reverses the remaining n elements (n - k) -> {4, 5, 1, 2, 3}
}