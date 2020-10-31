#include <iostream>
#include<cstdio>
using namespace std;
long int choose(int n,int x)
{
	long nfact=1,rfact=1,nrfact=1;
	for(int i=2;i<=n;i++)
	nfact*=i;
	for(int i=2;i<=x;i++)
	rfact*=i;
	for(int i=2;i<=n-x;i++)
	nrfact*=i;
	return nfact/(nrfact*rfact);
	
}
int main() {
	long int a,b;
	scanf("%ld%ld",&a,&b);
	while(a!=-1&&b!=-1)
	{
		if(a+b==choose(a+b,min(a,b)))
		printf("%ld+%ld=%ld\n",a,b,a+b);
		else
		printf("%ld+%ld!=%ld\n",a,b,a+b);
		scanf("%d%d",&a,&b);
	}
	return 0;
}