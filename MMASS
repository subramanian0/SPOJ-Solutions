#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<int> s;
	cin >> str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '(')
			s.push(str[i]);
		else if(isalpha(str[i]))
		{
			if(str[i] == 'C')
				s.push(12);
			else if(str[i] == 'H')
				s.push(1);
			else if(str[i] == 'O')
				s.push(16);
		}
		else if(str[i] == ')')
		{
			int x = s.top();
			int sum = 0;
			while(s.top()!='(')
			{
				sum += s.top();
				s.pop();
			}
			s.pop();
			s.push(sum);
		}
		else if(isdigit(str[i]))
		{
			int val = s.top();
			int mul = str[i] - '0';
			s.pop();
			s.push(val*mul);
		}
	}
	int res = 0;
	while(!s.empty())
	{
		res +=s.top();
		s.pop();
	}
	
	cout << res << endl;
	
	
	return 0;
}