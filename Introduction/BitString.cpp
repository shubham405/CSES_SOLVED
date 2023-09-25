#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod= 1e9+7;
ll mpow(ll num, ll p)
{
    if(p==0)
    {
        return 1;
    }
    if(p==1)
    {
        return num%mod;
    }
    ll x = mpow(num,p/2);
    if(p%2)
    {
        return (((x%mod)*(x%mod))%mod*num%mod)%mod;
    }
    return (x%mod*x%mod)%mod;

}
int main()
{
    ll n;
    cin>>n;
    //cout<<(1<<n)<<endl;
    ll ans = mpow(2,n);
    cout<<ans<<endl;;
}