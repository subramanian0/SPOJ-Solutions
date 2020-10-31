#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[1200][1200];
int main() {
    // your code goes here
    int t=1;
    char a[1200],b[1200];
  //  cin>>t;
    while(t--)
    {
        scanf("%s%s",a,b);
        memset(dp,0,sizeof(int)*strlen(a)*strlen(b));
        for(int i=0;i<=strlen(a);i++)
        {
            for(int j=0;j<=strlen(b);j++)
            {
                if(i==0||j==0)
                dp[i][j]=0;
                else if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[strlen(a)][strlen(b)];
       
    return 0;
}