#include <stdio.h>
int n,g[10][10];
int visit[20]={0};
int stack[20],top=-1;

void push(int v){
    stack[++top]=v;
}

int pop(){
    return stack[top--];
}

void dfs(int s){
    visit[s]=1;
    for(int i=0;i<n;i++){
        if(g[s][i]==1 && visit[i]==0){
            dfs(i);
        }
    }
    push(s);
   
}

void topologicalsort(){
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            dfs(i);
        }
    }
    
    printf("Topological Sort: ");
    while(top!=-1){
        int v=pop();
        printf("%d->",v);
    }
    
    
    printf("\n");
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
    
    topologicalsort();
    
    
}
