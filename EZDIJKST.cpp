#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
long int G[5005][5005]={0};
int visited[5005]={0};
long long int dist[5005];
int getMin(int u,int v)
    {
    int mini=INT_MAX,minI=0;
     for(int i=0;i<=v;i++) 
         {
         if(dist[i]<mini&&visited[i]==0)
             {
             mini=dist[i];
             minI=i;
         }
         }
    return minI;
} 
void Dijkstra(int src,int v)
    { 
    dist[src]=0;
    int u;
    for(int i=0;i<v-1;i++)
        {
        u=getMin(u,v);
        visited[u]=1;
        for(int i=0;i<=v;i++)
            if(dist[i]>dist[u]+G[u][i]&&G[u][i])
            dist[i]=dist[u]+G[u][i];
    }
    for(int i=1;i<=v;i++)
        if(i!=src){}
     //   printf("%d ",dist[i]);
}
int main() {
   int t,v,e,s,d,w,src,end;
    cin>>t;
    while(t--)
        {
        cin>>v>>e;
        for(int i=0;i<=v;i++)
            {
            dist[i]=INT_MAX;
            visited[i]=false;
        }
        for(int i=0;i<=v;i++)
            for(int j=0;j<=v;j++)
            G[i][j]=0;
        while(e--)
            {
            cin>>s>>d>>w;
            G[s][d]=w;
           // G[d][s]=w;
        }
        cin>>src>>end;
        Dijkstra(src,v);
        (dist[end]==INT_MAX)?cout<<"NO\n":cout<<dist[end]<<"\n";
    }
    return 0;
}
