#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bubbleSort(int arr[], int n) {
    int temp;
    int swapped;

    for(int i = 0; i < n - 1; i++) {
        swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0) break;
    }
}

void selectionSort(int arr[], int n) {
    int minIndex, temp;

    for(int i = 0; i < n - 1; i++) {
        minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;

    printf("Oryginalna tablica:\n");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("Po Bubble Sort:\n");
    printArray(arr, n);

    int arr2[] = {5, 2, 9, 1, 3};
    selectionSort(arr2, n);
    printf("Po Selection Sort:\n");
    printArray(arr2, n);

    int target = 3;
    int index = linearSearch(arr2, n, target);
    printf("Linear Search: element %d na indeksie %d\n", target, index);

    int index2 = binarySearch(arr2, 0, n - 1, target);
    printf("Binary Search: element %d na indeksie %d\n", target, index2);

    return 0;
}