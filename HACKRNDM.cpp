#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[100005];
int binsearch(int x)
{
	int l=0,h=n-1;
	while(l<=h)
	{
		int m=l+((h-l)/2);
		if(a[m]==x)
			return 1;
		else if(a[m]<x)
		l=m+1;
		else
		h=m-1;
	}
	return 0;
}
int main()
{
	int k,cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
	if(binsearch(a[i]+k))
	cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}