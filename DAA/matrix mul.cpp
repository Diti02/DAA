//// Online C compiler to run C program online
//#include <stdio.h>
//
//
//int min(int a,int b){
//    if(a<b){
//        return a;
//    }
//    else{
//        return b;
//    }
//}
//
//int matrixmul(int a[],int n){
//    int row,col,k,len;
//    int d[n][n];
//    
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            d[i][j]=0;
//        }
//    }
//    
//    for(len=2; len<n; len++){
//        col=len;
//        for(row=0;row<n-len;row++){
//            d[row][col]=999;
//            for(k=row+1;k<col;k++){
//            	int c= min(d[row][col],
//                (d[row][k]+d[k][col]+ (a[row]*a[col]*a[k])));;
//                d[row][col]= c;
//                
//                
//            }
//            col++;
//        }
//    }
//    
//    return d[0][n-1];
//}
//
//
//
//int main(){
//    int n=5;
//    int a[]={2,3,4,1,3};
//    int ans=matrixmul(a,n);
//    printf("Minimum no of operations: %d",ans);
//    
//}


#include <stdio.h>
#include <limits.h>



void printOptimalParenthesis(int s[][5], int i, int j) {
    if (i == j) {
        printf("%c", 65+i );
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int matrixmul(int a[], int n) {
    int d[n][n];
    int s[n][n]; 
    
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
        s[i][i] = 0;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            d[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = d[i][k] + d[k + 1][j] + (a[i] * a[k + 1] * a[j + 1]);
                if (cost < d[i][j]) {
                    d[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesis Configuration: ");
    printOptimalParenthesis(s, 0, n - 2);
    printf("\n");

    return d[0][n - 2];
}

int main() {
    int n = 5;
    int a[] = {2, 3, 4, 1, 3};
    int ans = matrixmul(a, n);
    printf("Minimum number of operations: %d\n", ans);

    return 0;
}

