#include <iostream>
#include<cstdio>
#include<climits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int x,sum=0;
	long c=0;
	scanf("%d",&x);
	while(x!=1)
	{
		while(x)
		{
			sum=sum+((x%10)*(x%10));
			x/=10;
		}
		x=sum;
		sum=0;
		c++;
		if(c==999999)
		break;
	}
	if(x==1)
	printf("%ld\n",c);
	else
	printf("-1\n");
	return 0;
}