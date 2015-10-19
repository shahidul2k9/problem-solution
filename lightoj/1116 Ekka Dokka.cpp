#include<bits/stdc++.h>
using namespace std;

#define s(x) scanf("%d",&x)
#define s1(x) scanf("%lld",&x)
#define p(x) printf("%d\n",x)
#define p1(x) printf("%lld\n",x)
#define ps(x) printf("%d ",x)
#define p1s(x) printf("%lld ",x)
#define st(x) scanf("%s",x)
#define pt(x) printf("%s",x)
#define Y printf("YES\n")
#define N printf("NO\n")
#define mod 1000000007
#define ll long long

ll power(ll b, ll e)
{
    ll p = 1;
    while (e > 0)
    {
       if(e&1)
        {
          p=(p*b)%mod;
        }
        e=e>>1;
        b=(b*b)%mod;
    }
    return p;
}
int main()
{
ll t,n,a,k=1;
s1(t);
while(t--)
{
  s1(n);
  if(n&1)
  {
    cout<<"Case "<<k++<<": "<<"Impossible"<<endl;
  }
  else
  {
     a=n;
     while(a%2==0)
        a/=2;

     cout<<"Case "<<k++<<": "<<a<<" "<<n/a<<endl;
  }

}
return 0;
}
