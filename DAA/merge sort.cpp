// Online C compiler to run C program online
#include <stdio.h>

void merge(int arr[],int lo,int mid,int hi){
    int i=lo;
    int j=mid+1;
    int k=0;
    int temp[hi-lo+1];
    
    while(i<=mid && j<=hi){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    
    while(j<=hi){
        temp[k]=arr[j];
        k++;
        j++;
    }
    
    
    
    for(int m=lo;m<=hi;m++){
        arr[m]=temp[m-lo];
    }
    
    
    
}


void mergesort(int arr[],int lo,int hi){
    if(lo<hi){
    int mid=(lo+hi)/2;
    mergesort(arr,lo,mid);
    mergesort(arr,mid+1,hi);
    merge(arr,lo,mid,hi);
        
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
   mergesort(arr,0,n-1);
  
  
   
   printf("\nElements after soring:\n");
   for(i=0;i<n;i++){
       
       printf("%d\t",arr[i]);
   }

    return 0;
}
