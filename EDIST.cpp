#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
int dp[2005][2005];
using namespace std;
int editDist(char* a,char* b)
{
	int l1=strlen(a);
	int l2=strlen(b);
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0)
			dp[i][j]=j;
			else if(j==0)
			dp[i][j]=i;
			else if(a[i-1]==b[j-1])
			dp[i][j]=dp[i-1][j-1];
			else
			{
				dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
			}
		}
	}
	
	return dp[l1][l2];
}
int main()
{
	int t;
	char a[2005],b[2005];
	cin>>t;
	while(t--)
	{
		scanf("%s%s",a,b);
		printf("%d\n",editDist(a,b));
		
	}
	return 0;
}