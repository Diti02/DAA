
#include <stdio.h>

void knapsack(int n,int capacity,float weight[],float profit[]){
    float x[20],tp;
    int i;
    int u=capacity;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    
    for(i=0;i<n;i++){
        if(weight[i]>u){
            break;
        }
        else{
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
    
    
    if (i < n){
      x[i] = u / weight[i];
      tp = tp + (x[i] * profit[i]);
    }
 
   printf("\nKnapsack solution is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t\n", x[i]);
 
   printf("\nMaximum profit is:- %f", tp);
}
    
     




int main(){
    float weight[20],profit[20],temp;
    float ratio[20];
    int capacity,n,i,j;
    
    printf("Enter no of objects: ");
    scanf("%d",&n);
    
    printf("Enter the weights & profit of each object: ");
    for(i=0;i<n;i++){
        scanf("%f %f", &weight[i], &profit[i]);
    }
    
    printf("Enter the capacity of kanpsack:");
    scanf("%d", &capacity);
    
    for(i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;
                
                temp=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp;
                
                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;
            }
        }
    }
    
    printf("Objects after sorting:\n");
        printf("Weight\t\tprofit\t\tratio\n");
        for(i=0;i<n;i++){
            printf("%f\t%f\t%f\n",weight[i],profit[i],ratio[i]);
        }
    
    knapsack(n,capacity,weight,profit);
    
}
