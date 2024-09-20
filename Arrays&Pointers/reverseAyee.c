#include <stdio.h>

void reverse(int *arr, int size);

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int i;

    reverse(arr, 5);

    for(i = 0; i < 5; i++){
        printf("%d", arr[i]);
    }

    return 0;
}

void reverse(int *arr, int size){

    int i; 
    int temp;

    for(i = 0; i < size /2; i++){
        temp = arr[i];
        arr[i] = arr[size - i -1];
        arr[size - i -1] = temp;
    }
}
