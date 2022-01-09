#include <stdio.h>
#define M 10

int h(int k, int i){
	return (k % M + i) % M;	
}

int push(int* x, int b){
	int i,c;
	for(i=0; i<M; i++)
		if(x[h(b,i)]==-1){
			c=h(b,i);
			x[c]=b;
			return c;
		}
}

void printArray(int *x){
	int i;
	for(i=0; i<M; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}

int main(){
	int a[M];
	int i;
	for(i=0; i<M; i++) a[i]=-1;
	printArray(a);
	push(a,72);
	printArray(a);
	push(a,27);
	printArray(a);
	push(a,36);
	printArray(a);
	push(a,24);
	printArray(a);
	push(a,63);
	printArray(a);
	push(a,81);
	printArray(a);
	push(a,92);
	printArray(a);
	push(a,91);
	printArray(a);
	
	
	return 0;
	
}
