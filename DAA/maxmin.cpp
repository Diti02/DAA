// Online C compiler to run C program online
#include <stdio.h>
int max,min;

void maxmin(int arr[],int i,int j){
    if(i==j){
        max=arr[i];
        min=arr[i];
    }
    else if(i==j-1){
        if(arr[i]>arr[j]){
            max=arr[i];
            min=arr[j];
        }
        else{
            min=arr[i];
            max=arr[j];
        }
    }
    
    else{
        int mid=(i+j)/2;
        maxmin(arr,i,mid);
        int max1=max;
        int min1=min;
        maxmin(arr,mid+1,j);
        if(max1>max){
            max=max1;
        }
        if(min1<min){
            min=min1;
        }
    }
}



int main(){
   int n,i;
   printf("Enter no of elements: ");
   scanf("%d", &n);
   int arr[n];
   
   for(i=0;i<n;i++){
       printf("Enter the elements:");
       scanf("%d",&arr[i]);
   }
   
   maxmin(arr,0,n-1);
   
   printf("\n Maximum: %d",max);
   printf("\n Minimum: %d",min);
   
}
