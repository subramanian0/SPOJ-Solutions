#include <iostream>
#include<climits>
using namespace std;
int a[500005],segTree[500005];
void constructSegTree(int pos,int l, int h)
{
	if(l == h)
		segTree[pos] = a[l];
	else
	{
		int mid = (l+h)/2;
		constructSegTree((pos*2)+1,l,mid);
		constructSegTree((pos*2)+2,mid+1,h);
		segTree[pos] = min(segTree[(pos*2)+1],segTree[(pos*2)+2]);
	}
}
int rmq(int l, int h, int pos,int qL, int qR)
{
	if(qL > h || qR <l || l > h) return INT_MAX;
	if(l>=qL && h <=qR) return segTree[pos];
	int mid = (l+h)/2;
	return min(rmq(l,mid,(pos*2)+1,qL,qR),
	rmq(mid+1,h,(pos*2)+2,qL,qR));
}
int main() {
	int n, k;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cin >> k;
	constructSegTree(0,0,n);
	while(k--)
	{
		int l, h;
		cin >> l >> h;
		cout << rmq(0,n,0,l,h) << endl;
	}
	
	return 0;
}
