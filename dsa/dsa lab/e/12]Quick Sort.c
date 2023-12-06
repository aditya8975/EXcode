#include <stdio.h>

// Function to partition the array into two halves and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = (low - 1);       // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Return the pivot index
}

// Function to perform quicksort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivot = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    print_array(arr, arr_size);

    quick_sort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    print_array(arr, arr_size);

    return 0;
}
