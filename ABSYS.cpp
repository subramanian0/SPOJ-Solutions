#include <iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	int t;
 char ch;
	string a,b,c,d,e;
	scanf("%d",&t);
	while(t--)
	{
	    cin>>a>>ch>>b>>ch>>c;
		int f=1;
		for(int i=0;i<a.length()-1;i++)
		{
			if(a[i]=='m'&&a[i+1]=='a')
			{
				f=-1;
				break;
			}
		}
		if(f==-1)
		{
			cout<<atoi(c.c_str())-atoi(b.c_str())<<" + "<<b<<" = "<<c<<endl;
			//printf("%d + %s = %s",atoi(c.c_str())-atoi(b.c_str()),b,c);
			continue;
		}
			for(int i=0;i<b.length()-1;i++)
		{
			if(b[i]=='m'&&b[i+1]=='a')
			{
				f=-1;
				break;
			}
		}
		if(f==-1)
		{
		 cout<<a<<" + "<<atoi(c.c_str())-atoi(a.c_str())<<" = "<<c<<endl;
			continue;
		}
		for(int i=0;i<c.length()-1;i++)
		{
			if(c[i]=='m'&&c[i+1]=='a')
			{
				f=-1;
				break;
			}
		}
		if(f==-1)
		{
		   cout<<a<<" + "<<b<<" = "<<atoi(a.c_str())+atoi(b.c_str())<<endl;
			continue;
		}
		
	}
	return 0;
}