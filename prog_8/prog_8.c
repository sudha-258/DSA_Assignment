#include<stdio.h>
#include<stdlib.h>
int comparision_count = 0, swap_count = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size){
    for(int i=0; i<size-1;i++){
        for (int j = 0; j<size-i-1;j++){
            comparision_count++;
            if (arr[j]>arr[j+1]){
                swap_count++;
                swap(&arr[j],&arr[j+1]);
            }
        }

    }
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            comparision_count++;
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            swap_count++;
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparision_count++;
            if (arr[j] > key) {
                swap_count++;
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right) {
    int a = middle - left + 1;
    int b = right - middle;

    int L[a], R[b];

    for (int i = 0; i < a; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < b; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < a && j <b) {
        comparision_count++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < a)
        arr[k++] = L[i++];

    while (j < b)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}



void display_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void random_array(int arr[],int size){
    for(int i = 0; i<size; i++){
        arr[i]= rand() % 1000+1;
    }
}

int  main(){
    int size;
    int choice;

    printf("Enter the number of elements:");
    scanf("%d",&size);

    int arr[size];

    printf("Random array of size: %d ", size);
    random_array(arr,size);
    printf("Array: ");
    display_array(arr,size);
    

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\nBefore Sorting:\n");
    display_array(arr, size);

    comparision_count = swap_count = 0;

    switch (choice) {
        case 1:
            bubble_sort(arr, size);
            break;
        case 2:
            selection_sort(arr, size);
            break;
        case 3:
            insertion_sort(arr, size);
            break;
        case 4:
            merge_sort(arr, 0, size - 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nAfter Sorting:\n");
    display_array(arr, size);

    printf("\nTotal Comparisons: %lld\n", comparision_count);
    if (choice != 4)
        printf("Total Swaps: %lld\n", swap_count);
    else
        printf("Swaps: Not applicable for Merge Sort\n");

    return 0;
}