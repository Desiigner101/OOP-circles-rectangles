#include <stdio.h>

void reverseArray(int *array, int size);

int main(){
    int array[5]={1,2,3,4,5};
    int i;
    
    reverseArray(array, 5);
    printf("The reversed array:\n");
    for(i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}

void reverseArray(int *array, int size){
    int i;
    int temp;

    for(i = 0; i  <= size / 2; i++){
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}