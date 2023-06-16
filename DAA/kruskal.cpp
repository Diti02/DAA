#include <stdio.h>
#include <stdlib.h>
int nov,noe;
typedef struct edge{
    int v1,v2,wt;
}edge;

edge e[10];
int mst[10][3];
int parent[10];
int treeedge=1;


int find(int i)
{
    if(parent[i]==i){
        return i;
    }
    return(find(parent[i]));
}

void Union(int i, int j){
    if(i!=j)
        parent[j]=i;
}

void printmst(){
    int i;
    for(i=1;i<treeedge;i++){
        printf("Edge(%c %c)-> %d\n",mst[i][1]+64,mst[i][2]+64,mst[i][3]);
    }
    
}

void kruskal(){
    int i;
    for(i=0;i<nov;i++)
        parent[i]=i;
    for(i=0;i<noe;i++)
    {
        if(find(e[i].v1)!=find(e[i].v2))
        {
            mst[treeedge][1]=e[i].v1;
            mst[treeedge][2]=e[i].v2;
            mst[treeedge++][3]=e[i].wt;
            Union(find(e[i].v1),find(e[i].v2));
        }
    }
}
    
     




int main(){
    edge temp;
    FILE *fp;
    int i,j;
    fp=fopen("a.txt","r");
    if(fp==NULL){
        printf("File not found");
    }
    fscanf(fp,"%d",&nov);
    fscanf(fp,"%d",&noe);
    
    for(i=0;i<noe;i++){
        fscanf(fp,"%d %d %d",&e[i].v1, &e[i].v2, &e[i].wt);
    }
    printf("Entered graph: \n");
    for(i=0;i<noe;i++){
        printf("%d %d %d\n",e[i].v1, e[i].v2, e[i].wt);
    }
    
    for(i=0;i<noe-1;i++){
        for(j=0;j<noe-i-1;j++){
            if(e[j].wt>e[j+1].wt){
                temp=e[j+1];
                e[j+1]=e[j];
                e[j]=temp;
            }
        }
    }
    
    printf("Entered graph after sorting: \n");
    for(i=0;i<noe;i++){
        printf("%d %d %d\n",e[i].v1, e[i].v2, e[i].wt);
        
    }
    kruskal();
    printf("Solution: \n");
    printmst();
    
   
    
}
