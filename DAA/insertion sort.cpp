#include <stdio.h>

int main() {
   int n;
   printf("Enter no of elements: ");
   scanf("%d", &n);
   int arr[n];
   
   for(int i=0;i<n;i++){
       printf("Enter the elements:");
       scanf("%d",&arr[i]);
   }
   printf("Elements before soring:\n");
   for(int i=0;i<n;i++){
       
       printf("%d\t",arr[i]);
   }
   int i,j;
   
   for(i=1;i<n;i++){
       j=i-1;
       int x=arr[i];
       while(arr[j]>x && j>=0){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=x;
   }
   
   printf("\nElements after soring:\n");
   for(i=0;i<n;i++){
       
       printf("%d\t",arr[i]);
   }

    return 0;
}
