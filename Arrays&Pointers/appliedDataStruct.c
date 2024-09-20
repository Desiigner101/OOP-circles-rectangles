#include <stdio.h>
#include <stdbool.h>

void reverseArray(int *arr, int size);
void bubbleSort(int *arr, int size);
int findMax(int *arr, int size);
float getAverage(int *arr, int size);
void addElementAt(int *arr, int *size, int newElement, int index);
void deleteElementAt(int *arr, int *size, int index);
float findMedian(int *arr, int size);
int searchArray(int *arr, int size, int value, bool *found);

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