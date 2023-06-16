#include <stdio.h>

void toH(int n,char roda, char rodc, char rodb){
	if(n==1){
		printf("\n Move disk 1 from rod %c to rod %c",roda,rodc);
		return;
	}
	toH(n-1,roda,rodb,rodc);
	printf("\n Move disk %d from rod %c to rod %c",n,roda,rodc);
	toH(n-1,rodb,rodc,roda);
}

int main(){
	int nd;
	printf("Enter number of disks: ");
	scanf("%d",&nd);
	toH(nd,'A','C','B');
	return 0;
}
