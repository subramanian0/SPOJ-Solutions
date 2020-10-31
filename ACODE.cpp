#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	unsigned long long int n,cnt=0;
	char a[5005];
	int dp[5005]={0};
	scanf("%s",a);

	while(strcmp(a,"0")!=0)
	{
			dp[0]=1;
	for(int i=1;i<strlen(a);i++)
	{
		int x=(a[i-1]-'0')*10+(a[i]-'0');
		if(a[i]-'0'>0&&a[i]-'0'<=9)
		dp[i]=dp[i-1];
        if(x>=10&&x<=26)
		dp[i]+=(i-2)>=0?dp[i-2]:dp[0];
	}
	printf("%d\n",dp[strlen(a)-1]);
    memset(dp,0,sizeof(dp));
	scanf("%s",a);
	}
	
	return 0;
}