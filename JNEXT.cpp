#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		string str="";
		string c;
		for(int i=0;i<n;i++){
			cin>>c;
			str+=c;
		}
		bool isNext = next_permutation(str.begin(),str.end());
		if(isNext)
		cout<<str<<endl;
		else
		cout<<"-1"<<endl;
		
	}
	return 0;
}