#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
bool buff[100005]={false};
int main() {
	int t,n,k,cnt=0,x,it=0;
	scanf("%d",&t);
	while(t--)
	{
		it++;
		scanf("%d%d",&n,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&x);
			if(!buff[x]&&x>0&&x<=n)
			{
				buff[x]=true;
				cnt++;
			}
			if(!buff[x-1]&&x>1&&x-1<=n)
			{
				buff[x-1]=true;
				cnt++;
			}
			if(!buff[x+1]&&x>0&&x+1<=n)
			{
				buff[x+1]=true;
				cnt++;
			}
		//	printf("%d\n",cnt);
		}
		printf("Case %d: %d\n",it,min(cnt,n));
		cnt=0;
		memset(buff,false,sizeof(buff));
	}
	return 0;
}