#include<stdio.h>


//Swap function
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//For max heap
void max_heap(int arr[],int n, int  i){
    int largest = i;
    int right = 2*i+2;
    int left = 2*i+1;
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right <n && arr[right]>arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(&arr[i],&arr[largest]);
        max_heap(arr,n,largest);
    }
}

void build_max_heap(int arr[], int n){
    for(int i= n/2-1; i>=0; i--){   //All the elements greater than n/2-1 satisfy leap property
        max_heap(arr,n ,i);
    }
}

void min_heap(int arr[], int n, int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]<arr[smallest]){
        smallest = left;
    }
    if (right<n && arr[right]<arr[smallest] ){
        smallest = right;
    }
    if (smallest != i){
        swap(&arr[i], &arr[smallest]);
        min_heap(arr,n,smallest);

    }
}

void build_min_heap(int arr[],int n){
    for(int i = n/2 - 1; i>=0;i--){
        min_heap(arr,n, i);
    }
}

void display(int arr[], int n){
    for(int i =0; i<n; i++){
        printf("%d", arr[i]);

    }
    
}

int main(){
    int n;
    int arr[20];
    int max_heap_arr[n];
    int min_heap_arr[n];
    printf("Enter the size of the array:");
    scanf("%d", &n);
    for (int i = 0; i<n;i++){
        printf("Enter the elements of array:");
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n;i++){
        max_heap_arr[i]= arr[i];
        min_heap_arr[i]= arr[i];
    }
    build_min_heap(min_heap_arr,n);
    build_max_heap(max_heap_arr,n);

    printf("Max Heap: ");
    display(max_heap_arr,n);

    printf("\nMin Heap: ");
    display(min_heap_arr,n);
    return 0;
}