#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void quicksort(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);

int main() {
    // Take input from the user
    char choice;
    printf("Enter 'q' for Quicksort or 'm' for Mergesort: ");
    scanf(" %c", &choice);

    // Take the size of the array from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Take the elements of the array from the user
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform sorting based on user's choice
    if (choice == 'q' || choice == 'Q') {
        quicksort(arr, 0, n - 1);
        printf("Sorted array using Quicksort: ");
    } else if (choice == 'm' || choice == 'M') {
        merge_sort(arr, 0, n - 1);
        printf("Sorted array using Mergesort: ");
    } else {
        printf("Invalid choice\n");
        free(arr);
        return 1;
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);

    return 0;
}


void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
            
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

 
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursively sort the partitions
        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

// Mergesort implementation
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

       
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    free(left);
    free(right);
}
