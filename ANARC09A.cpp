#include<cstring>
#include<cmath>
#include<cstdlib>
#include <iostream>
#include<cstdio>
using namespace std;
int main() {
	char a[2500];
	int cnt=0,ans=0,open=0,close=0;
	scanf("%s",a);
	int x=0;
	while(a[0]!='-')
	{
		x++;
		for(int i=0;i<strlen(a);i++)
		{
		if(a[i]=='}')
		close++;
		else if(a[i]=='{')
		open++;
		if(close>open)
		{
		ans++;
		open++;
		close--;
		}
		else
		{
			open--;
			close--;
		}
		}
		int t=abs(open-close);
		printf("%d. %ld\n",x,ans+t/2);
		ans=0;
		cnt=0;
		open=0;
		close=0;
		scanf("%s",a);
	}
	return 0;
}