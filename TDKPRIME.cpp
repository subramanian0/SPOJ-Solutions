#include <iostream>
#include <vector>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
bool isPrime[86028125]; //1000000 //15485863
unsigned long long int primevalues[5000005];
int k=0;
int main() {
	isPrime[0] = isPrime[1] = 0;
	isPrime[2] = 1;
	
	for(unsigned long long int i=3;i<=86028125;i+=2)
		isPrime[i] = 1;
//	memset(isPrime,true,86028122);
	for(unsigned long long int i=2;i<=86028122;i++)
	{
		if(isPrime[i])
		{
			for(unsigned long long int j=i*i;j<=(86028122);j=j+(2*i))
			{
						if(isPrime[j])
						isPrime[j] = 0;
			}
		}
	}
	primevalues[0] = 2;
	k++;
	for(unsigned long long int i=3;i<=86028122;i+=2)
	{
		if(isPrime[i]) primevalues[k++] = i;
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,cnt=0;
		cin>>n;
		cout<<primevalues[n-1]<<endl;
	}

	return 0;
}