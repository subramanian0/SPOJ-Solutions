#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include<cstring>
using namespace std;
int main() {
    int test;
    cin>>test;
    while(test--)
        {
    int a[301]={0};
    a[0]=1;
   int ans,carry=0,digits=1; 
   int i,n;
   cin>>n;
   for(i=2;i<=n;i++)
      {
      for(int j=0;j<digits;j++)
          {
          ans=a[j]*i+carry;
          a[j]=(ans%10);
          carry=ans/10;
      }
      //count bits
      while(carry!=0)
          {
          a[digits]=carry%10;
          carry/=10;
          digits++;
      }
  }
    for(i=digits-1;i>=0;i--)
        cout<<a[i];
        cout<<endl;
        }
        return (0);
}
 