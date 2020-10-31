#include<stdio.h>
int main()
{
 long  long int t,i;
  scanf("%lld",&t);
 while(t--)
 {
   scanf("%lld",&i);
   printf("%lld\n",192+(i-1)*250);
 }
  return 0;
}