#include<stdio.h>
void main(){
    int n,temp,i,j,min;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;j<n-1;j++){
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min]){
            min = j;
            }
        
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;


        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}