#include <stdio.h>
int n,g[10][10];
int visit[20]={0};

void dfs(int s){
    printf("%d->",s);
    visit[s]=1;
    for(int i=0;i<n;i++){
        if(g[i][s]==1 && visit[i]==0){
            dfs(i);
        }
    }
}



int main(){
    FILE *fp;
    int i,j,s;
    fp=fopen("input.txt","r");
    if(fp ==NULL){
        printf("File cannot be opened");
    }
    else{
        printf("File opened\n");
    }
    fscanf(fp,"%d",&n);
   
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(fp,"%d",&g[i][j]);
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",g[i][j]);
           
        }
         printf("\n");
    }
    printf("\nEnter source vertex: ");
    scanf("%d",&s);
    
    dfs(s);
    
    
}
