#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[10005];
bool comp(int i,int j)
{
	return i>j;
}
int main()
{
	int t,x,n;
	scanf("%d",&t);
	int k=-1;
	while(t--)
	{k++;
		scanf("%d%d",&x,&n);
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n,comp);
		printf("Scenario #%d:\n",k+1);
		for(int i=0;i<n;i++)
		{
			x-=a[i];
			if(x<=0)
			{
				printf("%d\n",i+1);
				goto x;
			}
		}
		printf("impossible\n");
		x:{}
	}
	return 0;
}