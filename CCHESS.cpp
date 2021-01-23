#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
using namespace std;

int main() {
		queue< pair<int,int>> Q;
		int cost[100][100];
		
		int s1,s2;
		int d1,d2;
		 while(scanf("%d%d%d%d", &s1, &s2, &d1, &d2) != EOF)
		{
			for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			cost[i][j] = INT_MAX;
		}
		pair<int,int> s = {s1,s2};
		pair<int,int> d = {d1,d2};
		Q.push({s1,s2});
		cost[s1][s2] = 0;
		int res = INT_MAX;
		int steps = 0;
		while(!Q.empty())
		{
			 pair<int,int>  top = Q.front();
			if(top.first == d.first && top.second == d.second)
			{
			//	cout << top.first << " " << top.second << " " << top.second << endl;
				res = min(res,top.second);
			}
			
			Q.pop();
		
			    int first = top.first;
			    int second = top.second;
				if(top.first+2<8 && top.second+1<8)
				{
					if((cost[first][second] +  first*(first+2) + second*(second+1))<cost[first+2][second+1])
					{
						Q.push({top.first+2,top.second+1});
						cost[first+2][second+1] = cost[first][second] + (first*(first+2) + second*(second+1));
					}
				}
				if(top.first+2<8 && top.second-1>=0)
				{
					if(cost[first][second] +  first*(first+2) + second*(second-1) < cost[first+2][second-1])
					{
						Q.push({top.first+2,top.second-1});
						cost[first+2][second-1] = cost[first][second] +  first*(first+2) + second*(second-1);
					}
				}
				if(top.first-2>=0 && top.second+1<8)
				{
					if(cost[first][second] +  first*(first-2) + second*(second+1) < cost[first-2][second+1])
					{
						Q.push({top.first-2,top.second+1});
						cost[first-2][second+1] = cost[first][second] +  first*(first-2) + second*(second+1) ;
					}
				}
				
				if(top.first-2>=0 && top.second-1>=0)
				{
					if(cost[first][second] +  first*(first-2) + second * (second-1) < cost[first-2][second-1])
					{
						Q.push({top.first-2,top.second-1});
						cost[first-2][second-1] = cost[first][second] +  first*(first-2) + second * (second-1) ;
					}
				}
				
				if(top.first-1>=0 && top.second+2<8)
				{
					if(cost[first][second] +  first * (first-1) + second * (second+2) < cost[first-1][second+2])
					{
						Q.push({top.first-1,top.second+2});
						cost[first-1][second+2] = cost[first][second] +  first * (first-1) + second * (second+2) ;
					}
				}
				if(top.first-1>=0 && top.second-2>=0)
				{
					if(cost[first][second] +  first * (first-1) + second * (second-2) < cost[first-1][second-2])
					{
						Q.push({top.first-1,top.second-2});
						cost[first-1][second-2] = cost[first][second] +  first * (first-1) + second * (second-2) ;
					}
				}
				if(top.first+1<8 && top.second-2>=0)
				{
					if(cost[first][second] +  first*(first+1) + second*(second-2)  < cost[first+1][second-2])
					{
						Q.push({top.first+1,top.second-2});
						cost[first+1][second-2] = cost[first][second] +  first*(first+1) + second*(second-2);
					}
				}
				if(top.first+1<8 && top.second+2<8)
				{
					if(cost[first][second] +  first*(first+1) + (second)*(second+2) < cost[first+1][second+2])
					{
						Q.push({top.first+1,top.second+2});
						cost[first+1][second+2] =cost[first][second] +   first*(first+1) + second * (second+2);
					}
				}
				
			
		}
		cout << cost[d1][d2] << endl;
		}
		
	return 0;
}
