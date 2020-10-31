#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[102][102],Table[102][102]={0};
int main()
{
	int n,m,t,ans=0;
	scanf("%d",&t);
	while(t--)
	{
	memset(Table,0,sizeof(Table));
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	cin>>a[i][j];
	Table[1][j]=a[1][j];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int k=max(Table[i-1][j],Table[i-1][j-1]);
			Table[i][j]=a[i][j]+max(k,Table[i-1][j+1]);
		}
	}
	ans=0;
	for(int i=1;i<=m;i++)
	ans=max(ans,Table[n][i]);
	printf("%d\n",ans);
	}
	return 0;
}