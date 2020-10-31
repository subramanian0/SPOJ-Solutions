#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
int Table[105][105],a[105][105]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	Table[i][j]=INT_MAX;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	scanf("%d",&a[i][j]);
	Table[1][j]=a[1][j];
	}
	for(int i=2;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
	{
	     
	     	for(int k=1;k<=m;k++)
	     	{
	     		if(abs(k-j)==0||abs(k-j)==1)
	     		{
	     			Table[i][j]=min(Table[i][j],Table[i-1][k]+a[i][j]);
	     		}
	     	}
	     
	}
	}
	int ans=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		ans=min(ans,Table[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}