#include <stdio.h>
int n,g[10][10];
int visit[10]={0};
int q[10],f=-1,r=-1;

void insert(int a){
    if(f==-1){
        f++;
    }
    q[++r]=a;
}

int del(){
    
    return q[f++];
}

void bfs(int s){
    insert(s);
    visit[s]=1;
    
    
    
    while(f<=r){
        int u=del();
        printf("\t%c->",u+65);
        for(int i=0;i<n;i++){
            
            if(g[i][u]==1 && visit[i]==0){
                
                insert(i);
                visit[i]=1;
               
            }
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
    
    bfs(s);    
}
