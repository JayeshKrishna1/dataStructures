#include<stdio.h>
int partition(int array,int l,int u){
    int temp1,temp2;
    int pivot = array[l];
    int start = l;
    int end = u;
    while(start < end){
        while(array[pivot] >= start){
            start++;
        }
        while(array[pivot] < end){
            end--;
        }
        if(start < end){
            temp1 = array[start];
            array[start] = arr[end];
            array[end] = temp1;           
        }
    }
    temp2 = pivot;
    pivot = array[end];
    array[end] = temp2;
    return end;
}
int quicksort(int a,int lb,int ub){
    int loc = partition(a,lb,ub);
    quicksort(a,lb,loc-1);
    quicksort(a,loc+1,ub);
    return a;
}
void main(){
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lowerbound = 0,upperbound = n-1;
    arr[n] = quicksort(arr,lowerbound,upperbound);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    }