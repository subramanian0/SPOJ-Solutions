#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
typedef long long int x64;
int graph[10005][10005],dist[10005],V,c;
bool mstSet[10005];
int minWeight()
{
	int minIndex,min=INT_MAX;
	for(int i=1;i<=V;i++)
	{
		if(dist[i]<min&&mstSet[i]==false)
		{
			min=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}
void printMST()
{
	x64 sum=0;
	for(int i=1;i<=V;i++)
		sum+=dist[i];
	printf("%lld\n",c*sum);
}
void primMST()
{
	for(int i=0;i<10005;i++)
		dist[i]=INT_MAX,mstSet[i]=false;
	dist[1]=0;
	for(int j=1;j<=V;j++)
	{
		int w=minWeight();
		mstSet[w]=true;
		for(int i=1;i<=V;i++)
		{
			if(graph[w][i]&&dist[i]>graph[w][i]&&mstSet[i]==false)
			{
				dist[i]=graph[w][i];
			}
		}
	}
printMST();
}
int main()
{
int n,m,u,v,w,t;
scanf("%d",&t);
while(t--)
{
	scanf("%d",&c);
scanf("%d%d",&n,&m);
V=n;
for(int i=1;i<=m;i++)
{
	scanf("%d%d%d",&u,&v,&w);
	graph[u][v]=w;
	graph[v][u]=w;
}
primMST();
}
	return 0;
}
