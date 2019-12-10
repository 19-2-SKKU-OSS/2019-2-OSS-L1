
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMid(int a,int b){
	return (a+b)/2;
}

int getSum(int *st,int ss,int se,int qs,int qe,int si){
	if(qs<=ss && qe>=se)
		return st[si];
	if(qs>se || qe<ss)
		return 0;
	int mid = getMid(ss,se);
	return getSum(st,ss,mid,qs,qe,2*si+1)+getSum(st,mid+1,se,qs,qe,2*si+2);
}

void updateValueUtil(int *st,int ss,int se,int ind,int diff,int si){
	if(ind>se || ind<ss)
		return ;
	st[si]=st[si]+diff;
	if(se!=ss){
		int mid=getMid(ss,se);
		updateValueUtil(st,ss,mid,ind,diff,2*si+1);
		updateValueUtil(st,mid+1,se,ind,diff,2*si+2);
	}
}

void updateValue(int arr[],int *st,int n,int ind,int num){
	int diff = num-arr[ind];
	arr[ind]=num;
	updateValueUtil(st,0,n-1,ind,diff,0);
}

int constructUtil(int arr[],int ss,int se,int *st,int si){
	if(ss==se){
		st[si]=arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss,se);
	st[si]=constructUtil(arr,ss,mid,st,2*si+1)+constructUtil(arr,mid+1,se,st,2*si+2);
	return st[si];
}

int *construct(int arr[],int n){
	int x = (int)ceil(log2(n));
	//double pow = pow(2.0,x);
	int max_size = 2*(int)pow(2,x)-1;
	int* st = (int*)malloc(sizeof(int)*max_size);
	constructUtil(arr,0,n-1,st,0);
	/*
	 * for(int i=0;i<max_size;i++)
		printf("%d ".st[i]);
	printf("\n");
	*/
	return st;

}

int main()
{
	int n;
	scanf("%d",&n);
	
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	int *st = construct(a,n);
	printf("%d\n",getSum(st,0,n-1,2,4,0));
	updateValue(a,st,n,2,10);

	printf("%d\n",getSum(st,0,n-1,1,3,0));
	return 0;
}

