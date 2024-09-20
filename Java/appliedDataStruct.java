package Java;
import java.util.Scanner;

public class appliedDataStruct {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int size;

        System.out.print("Enter the size of the array: ");
        size = scan.nextInt();

        int arr[] = new int[size];

        System.out.println("\nEnter the elements of the array:");
        scanArray(arr, size, scan);

        System.out.println("The elements of the array:");
        printArray(arr, size);

        System.out.println("\n\nThe reversed array:");
        reverseArray(arr, size);
        printArray(arr, size);

        int newElement, index;

        System.out.println("\nEnter an element to be added in the array: ");
        newElement = scan.nextInt();

        System.out.println("Enter a specific index (0 to " + (size - 1) + "): ");
        index = scan.nextInt();

        size++;
        System.out.println("\nThe updated array:");
        arr = addElementAt(arr, size, newElement, index);
        printArray(arr, size);

        System.out.println("\nThe sorted array:");
        sort(arr, size);
        printArray(arr, size);
    }

    public static void scanArray(int arr[], int size, Scanner scan){
        int i;

        for(i = 0; i < size; i++){
            arr[i] = scan.nextInt();
        }
    }

    public static void printArray(int arr[], int size){
        int i;

        for(i = 0; i < size; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void reverseArray(int arr[], int size){
        int i;
        int temp;

        for(i = 0; i < size/ 2; i++){
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    public static int[] addElementAt(int arr[], int size, int newElement, int index){
        // Create a new array with size increased by 1
        int newArr[] = new int[size];
        
        // Copy elements before the index
        for(int i = 0; i < index; i++){
            newArr[i] = arr[i];
        }

        // Insert new element
        newArr[index] = newElement;

        // Copy the rest of the elements after the inserted element
        for(int i = index + 1; i < size; i++){
            newArr[i] = arr[i - 1];
        }

        return newArr;
    }

    public static void sort(int arr[], int size){
        int i, j;

        for(i = 0; i < size - 1; i++){
            for(j = 0; j < size - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
