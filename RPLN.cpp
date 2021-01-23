#include<iostream>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
int a[500001],segTree[500001];
void constructSegTree(int l, int r, int pos)
{
 
	if(l == r) {
		segTree[pos] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	int child = (pos<<1)+1;
	constructSegTree(l,mid,child);
	constructSegTree(mid+1,r,child+1);
	segTree[pos] = min(segTree[child],segTree[child+1]);
}
int rmq(int l, int r, int pos, int qL, int qH)
{
	if(l>r) return INT_MAX;
	else if(l>=qL && r<=qH)
		return segTree[pos];
	else if(qL > r || qH < l)
		return INT_MAX;
	int mid = (l+r)>>1;
	int child = (pos<<1)+1;
    return min(rmq(l,mid,child,qL,qH),rmq(mid+1,r,child+1,qL,qH));
 // else return min(rmq(l,(l+r)/2,((pos*2)+1),qL,qH),rmq(((l+r)/2)+1,r,(pos*2)+2,qL,qH));
}
int main()
{
	int t;
	scanf("%d",&t);
	int i = 0;
	memset(segTree,INT_MAX,sizeof(segTree));
	while(t--)
	{
	i++;
	int n, q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	constructSegTree(0,n-1,0);
	printf("Scenario #%d:\n",i);
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		printf("%d\n",rmq(0,n-1,0,l,r) );
	}
}
	return 0;
}
