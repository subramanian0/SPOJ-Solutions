#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
int maxi(int a,int b)
{
	return (a>b)? a:b;
}
int a[25000],b[25000],c[25000];
using namespace std;
map<int,int>M;
int main()
{
	int n,m,sum=0,sum1=0,sum2=0;
	scanf("%d",&n);
	while(n)
	{
		memset(a,0,25000);
		memset(b,0,25000);
		memset(c,0,25000);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	M[a[i]]=-1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
	scanf("%d",&b[i]);
	if(M[b[i]]==-1)
	M[b[i]]=-2;
	}
	if(n<m)
	{
		for(int i=n;i<m;i++)
		a[i]=0;
	}
	else
	{
		for(int i=m;i<n;i++)
		b[i]=0;
	}
	int k=0,aptr=0,bptr=0;
	for(int i=0;i<n;i++)
	{
		if(M[a[i]]==-2)
		{
			c[k]=a[i];
			k++;
		}
	
	}
	for(int i=0;i<k;i++)
	{
		while(aptr<maxi(n,m)&&a[aptr]!=c[i])
		{
			sum1+=a[aptr];
			aptr++;
		}
		while(bptr<maxi(n,m)&&b[bptr]!=c[i])
		{
			sum2+=b[bptr];
			bptr++;
		}
	//	printf("%d %d\n",aptr,bptr);
		if(sum1>sum2)
		{
		sum+=(sum1+c[i]);
	//	printf("%d-",sum);
		aptr++;bptr++;
		}
		else
		{
		sum+=(sum2+c[i]);
		bptr++;aptr++;
		//printf("%d-",sum);
		}
		sum1=sum2=0;
	}
sum1=sum2=0;
//printf("%d %d\n",aptr,bptr);
	for(int i=aptr;i<maxi(n,m);i++)
	{
		sum1+=a[i];
		//sum2+=b[i];
	}
	for(int i=bptr;i<maxi(n,m);i++)
	sum2+=b[i];
	if(sum1>sum2)
	sum+=sum1;
	else
	sum+=sum2;
	printf("%d\n",sum);
	sum=sum1=sum2=0;
scanf("%d",&n);
}
	return 0;
}