#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
int cost[1005];
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)
		{
		scanf("%d",&cost[i]);
		if(cost[i]==-1)
		cost[i]=5001;
		//printf("%d ",cost[i]);
		}
	//	printf("\n");
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cost[i]=min(cost[i],cost[j]+cost[i-j]);
			}
		}
		if(cost[k]!=5001)
		printf("%d\n",cost[k]);
		else printf("%d\n",-1);
		memset(cost,0,k);
	}
	return 0;
}ABA12C