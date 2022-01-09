#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int* create_max_heap(int size)
{
	
	int* temp = (int*)malloc((size+1)*sizeof(int));
	temp[0] = 0;
	return temp;
	
}
int* insert(int *h,int val)
{
	int i,pos = h[0]+1,par;
	h[pos] = val;
	h[0]++;
	if(h[0]>1)
	{	
		par = pos/2;
		while(pos>1 && h[pos]>=h[par])
		{
			int temp = h[par];
			h[par] = h[pos];
			h[pos] = temp;
			pos = par;
			par = pos/2;
		}	
	}
	return h;
}
int* delete(int *h,int *val)
{
	if(h[0]>0)
	{
		*val = h[1];
		int n = h[0],p,l,r;
		int last = h[n];
		n=--h[0];
		if(n>0)
		{
			p=1,l=2,r=3;
			h[p] = last;
			while(l<=n && (h[p]<h[l] || h[p]<h[r]))
			{
				if(h[r]<h[l])
				{
					int temp = h[l];
					h[l] = h[p];
					h[p] = temp;
					p=l;
				}
				else
				{
					int temp = h[r];
					h[r] = h[p];
					h[p] = temp;
					p=r;	
				}
				l=2*p;
				r=l+1;
			}
		}
	}
	return h;
}
void display(int *h)
{
	int i;
	for(i=1;i<=h[0];i++)
	{
		printf("%d ",h[i]);
	}
	printf("\n");	
}
int main()
{
	int res;
	int *h = create_max_heap(MAX_SIZE);
	h=insert(h,45);
	display(h);
	h=insert(h,36);
	display(h);
	h=insert(h,54);
	display(h);
	h=insert(h,27);
	display(h);
	h=insert(h,63);
	display(h);
	h=insert(h,72);
	display(h);
	h=insert(h,61);
	display(h);
	h=insert(h,18);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);
	h=delete(h,&res);
	printf("deleted:%d\n",res);
	display(h);

}
