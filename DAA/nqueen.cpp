#include <stdio.h>
#include<stdbool.h>
int n,i,j,sol=0;

bool isSafe(int b[n][n],int row,int col){
     int i, j;
    for (i = 0; i < col; i++)
        if (b[row][i])
            return false;
            
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;
 
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (b[i][j])
            return false;
 
    return true;
    
}

void printqueen(int b[n][n]){
    printf("\nSolution: %d\n",sol);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(b[i][j]==1){
                printf("Q\t");
            }
            else{
                printf("*\t");
            }
        }
        printf("\n");
    }
}


bool nQueen(int b[n][n], int col){
    if(col==n){
        sol++;
    	printqueen(b);
    	printf("\n");
        return true;
        
    }
    
    for(int row=0;row<n;row++){
        
        if(isSafe(b,row,col)){
            b[row][col]=1;
            nQueen(b,col+1);
            b[row][col]=0;
            
        
    }
        
    }
    return false;
}


int main(){
    printf("Enter no of rows/columns in chessboard: ");
    scanf("%d",&n);
    int b[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    nQueen(b,0);
    
}
