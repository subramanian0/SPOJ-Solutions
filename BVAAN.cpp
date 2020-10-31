#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[250][250],ans[250][250][250];
int maxi=0;
int recursum(char*a,char*b,int l1,int l2,string str,int k)
{
int sum=0,ans1=-1,ans2=-1,ans3=-1;
if(k==0)
return 0;
if(l1==-1||l2==-1)
return -1;
if(ans[l1][l2][k]!=-7)
return ans[l1][l2][k];
if(a[l1]==b[l2])
{
	ans1=recursum(a,b,l1-1,l2-1,str,k-1);
	ans1=ans1==-1?-1:ans1+a[l1];

}
	ans2=recursum(a,b,l1-1,l2,str,k);
	ans3=recursum(a,b,l1,l2-1,str,k);
ans[l1][l2][k]=max(ans3,max(ans1,ans2));
return ans[l1][l2][k];
}

int main()
{
	char a[200],b[200],buff[200];
	int t,l,h;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<250;i++)
		for(int j=0;j<250;j++)
		for(int k=0;k<250;k++)
		ans[i][j][k]=-7;
		int k;
	    cin>>a;
	    cin>>b;
	  	int x=strlen(a)-1;
	   	int y=strlen(b)-1;
	    scanf("%d",&k);
        int res=recursum(a,b,x,y,"",k);
        if(res==-1)
        printf("0\n");
        else
        printf("%d\n",res);
	   	memset(dp,0,sizeof(dp));
	   
	 }
return 0;
}
  