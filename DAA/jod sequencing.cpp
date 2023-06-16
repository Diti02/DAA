// Online C compiler to run C program online
#include <stdio.h>
int job[20],profit[20],deadline[20];
int i,j,p;



void jobsequence(int n, int job[],int profit[],int deadline[]){
    int dmax=0;
    for(i=0;i<n;i++){
        if(deadline[i]>dmax){
            dmax=deadline[i];
        }
    }
    int slot[dmax];
    int result[dmax];
    
    for(i=1;i<=dmax;i++){
        slot[i]=-1;
    }
    
    for(i=0;i<n;i++){
        for(j=deadline[i];j>=1;j--){
            if(slot[j]==-1){
                slot[j]==1;
                result[j]=i;
                break;
            }
        }
    }
    
    printf("Job sequence:\n");
    for(i=0;i<dmax;i++){
        if(slot[i]==1){
            int x=result[i];
            p=p+profit[x];
            printf("Job %d->",job[x]);
        }
    }
}
    



int main() {
    int n,temp;
    printf("Enter no of jobs: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter jobid, profit and deadline: ");
        scanf("%d %d %d",&job[i],&profit[i],&deadline[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;i<n-i-1;j++){
            if(profit[j]<profit[j+1]){
                temp=profit[j+1];
                profit[j+1]=profit[j];
                profit[j]=temp;
                
                temp=job[j+1];
                job[j+1]=job[j];
                job[j]=temp;
                
                temp=deadline[j+1];
                deadline[j+1]=deadline[j];
                deadline[j]=temp;
            }
        }
    }
    printf("job\tprofit\t\tdeadline\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\n",job[i],profit[i],deadline[i]);
    }
    jobsequence(n,job,profit,deadline);
    return 0;
}
