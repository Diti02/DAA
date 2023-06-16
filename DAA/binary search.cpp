#include <stdio.h>

int binarysearch(int arr[],int l, int h,int x){
    if(h<l){
        return -1;
    }
    int mid=(l+h)/2;
    if(arr[mid]==x){
        return 1;
    }
    if(x<arr[mid]){
        binarysearch(arr,l,mid-1,x);
    }
    if(x>arr[mid]){
        binarysearch(arr,mid+1,h,x);
    }
    
    
}

int main(){
   int n,i,s,m=0;
   printf("Enter no of elements: ");
   scanf("%d", &n);
   int arr[n];
   
   for(i=0;i<n;i++){
       printf("Enter the elements:");
       scanf("%d",&arr[i]);
   }
   printf("Enter the element you want to search: ");
   scanf("%d",&s);
   m=binarysearch(arr,0,n-1,s);
   if(m==1){
       printf("found");
   }
   else{
       printf("Not Found");
   }
}
