#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	int t;
	t = 1;
	while(t--)
	{
		int n;
		cin>>n;
		while(n!=0)
		{
			int a[n];
			stack<int> streetStack;
			for(int j=0;j<n;j++)
				cin>>a[j];
			int k = 1;
			int i = 0;
			while((i<n || !streetStack.empty()) && streetStack.size()!=n)
			{
					if(a[i] == k || (streetStack.size() > 0 && streetStack.top() == k))
					{
						if(a[i] == k)
						{
							k++;
							i++;
						}
						else if(streetStack.size()  > 0)
						{
							streetStack.pop();
							k++;
						}
					}
					else {
					streetStack.push(a[i]);
					i++;
					}
			}
			if(k==n+1) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
			cin>>n;
		}
		
	}
	return 0;
}