#include<stdio.h>
void main(){
    int n,temp,i,flag;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<n-1;j++)
    {
        flag = 0;
    for(i=0;i<n-1-j;i++){
        if(arr[i]>arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("the array is sorted \n");
        break;
    }

    }
    printf("the sorted array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d",&arr[i]);
    }
   
}   
