#include <stdio.h>
void MergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
void merge(int arr[],int lb,int mid,int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;
    int arr1[ub+1];
    while(i<=mid && j<=ub){
        if(arr[i]<arr[j]){
            arr1[k] = arr[i];
            i++; 
        }
        else{
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    else if(j>mid){
        while (i<=mid){
            arr1[k] = arr[j];
            i++;
            k++;
        }
    }
    for(int i = lb;i<=ub;i++){
        arr[i] = arr1[i];
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
}
void main(){
    int n;
    printf("emter the size of array \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    MergeSort(arr,0,n-1);
    print(arr,n);
}