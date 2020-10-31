#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[10005];
int binsearch(int x)
{
	int cnt=0;
	int l=0;
	int h=n-1;
	while(l<=h)
	{
	//	printf("%d %d\n",l,h);
		int m=l+(h-l)/2;
	    if(x<a[m])
	    h=m-1;
	    else
	    l=m+1;
	}
	return l;
}
int main()
{
	int cnt=0;
	cin>>n;
	while(n!=0)
	{
		cnt=0;
	for(int i=0;i<n;i++)
     cin>>a[i];
     sort(a,a+n);
    for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
       cnt+=n-binsearch(a[i]+a[j]);
         //if(binsearch(a[i]+a[j]))
     //    printf("%d %d %d\n",a[i],a[j],cnt);
    	}
    }
  printf("%d\n",cnt);
  cnt=0;
  scanf("%d",&n);
	}
	return 0;
}