#include<stdio.h>
int binarysearch(int a[],int n,int data){
    int l=0,r=n-1,mid;
    while (l>r)
    {
        mid = (l+r)/2;
        if(data == mid){
            return a[mid];
        }
        else if (data < mid)
        {
            r = mid - 1;
        }
        else if(data > mid)
        {
            l = mid + 1;
        }
        else
        {
            return -1;
        }
        
        
    }
    
}
void main(){
    int n,temp,i,data,result;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<n-1;j++)
    {
    for(i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    }
    printf("enter the data to be searched \n");
    scanf("%d",data);
    result = binarysearch(arr,n,data);
    if(result == data)
    {
        printf("The elemnt is found \n");
    }
    else{
        printf("the element is not found \n");
    }
}