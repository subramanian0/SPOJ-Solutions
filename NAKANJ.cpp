#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
pair<int,int> getCoordsForPosition(string s)
{
	return make_pair(s[1]-'0',s[0]-'a'+1);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{	
		map< pair<int,int>, bool > visited;
		queue< pair< pair<int,int> , int> > Q;
		string s1,s2;
		cin >> s1 >> s2;
		pair<int,int> s = getCoordsForPosition(s1);
		pair<int,int> d = getCoordsForPosition(s2);
		Q.push({s,0});
		int steps = 0;
		while(!Q.empty())
		{
			
			pair< pair<int,int>, int>  top = Q.front();
			if(top.first.first == d.first && top.first.second == d.second)
			{
				cout <<  top.second << endl;
				break;
			}
			Q.pop();
			if(!visited[top.first])
			{
			    steps = top.second;
				if(top.first.first+2<=8 && top.first.second+1<=8)
					Q.push({{top.first.first+2,top.first.second+1},steps+1});
				if(top.first.first+2<=8 && top.first.second-1>=1)
					Q.push({{top.first.first+2,top.first.second-1},steps+1});
				if(top.first.first-2>=1 && top.first.second+1<=8)
					Q.push({{top.first.first-2,top.first.second+1},steps+1});
				if(top.first.first-2>=1 && top.first.second-1>=1)
					Q.push({{top.first.first-2,top.first.second-1},steps+1});
				
				if(top.first.first-1>=1 && top.first.second+2<=8)
					Q.push({{top.first.first-1,top.first.second+2},steps+1});
				if(top.first.first-1>=1 && top.first.second-2>=1)
					Q.push({{top.first.first-1,top.first.second-2},steps+1});
				if(top.first.first+1<=8 && top.first.second-2>=1)
					Q.push({{top.first.first+1,top.first.second-2},steps+1});
				if(top.first.first+1<=8 && top.first.second+2<=8)
					Q.push({{top.first.first+1,top.first.second+2},steps+1});
				
			}
			visited[top.first] = 1;
		}
		visited[s] = 1;
		
	}
	return 0;
}
