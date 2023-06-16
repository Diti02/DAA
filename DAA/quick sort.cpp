// Online C compiler to run C program online
#include <stdio.h>

int partition(int arr[],int l,int h){
    int temp,temp2;
    int pivot=arr[l];
    int i=l;
    int j=h;
    
    while(i<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    temp2=arr[j];
    arr[j]=arr[l];
    arr[l]=temp2;
    
    return j;
    
    
    
} 





void quicksort(int arr[], int l,int h){
    if(l<h){
        int pivot=partition(arr,l,h);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,h);
    }
    
    
    
}



int main() {
   int n,i;
   printf("Enter no of elements: ");
   scanf("%d", &n);
   int arr[n];
   
   for(i=0;i<n;i++){
       printf("Enter the elements:");
       scanf("%d",&arr[i]);
   }
   printf("Elements before soring:\n");
   for(i=0;i<n;i++){
       
       printf("%d\t",arr[i]);
   }
  
  quicksort(arr,0,n-1);
  
   
   printf("\nElements after soring:\n");
   for(i=0;i<n;i++){
       
       printf("%d\t",arr[i]);
   }

    return 0;
}
