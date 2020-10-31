#include <iostream>
using namespace std;
string str;
int dp[6200][6200];
int recur(int i,int j){
	if(dp[i][j] !=-1) return dp[i][j];
	if(i>j || j<0) return 0;
	if(str[i] == str[j]) {
		if(i!=j)
		return 2+recur(i+1,j-1);
		else return 1+recur(i+1,j-1);
	}
	return (dp[i][j] = max(recur(i+1,j),recur(i,j-1)));
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		for(int i=0;i<6200;i++)
			for(int j=0;j<6200;j++)
				dp[i][j] = -1;
		cout<<(str.length() - recur(0,str.length()-1))<<endl;
	}
	return 0;
}