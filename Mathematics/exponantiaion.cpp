#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll pow(ll num,ll x)
{
    if(x==0)
    {
        return 1;
    }
    if(x==1)
    {
        return num%mod;
    }
    ll p = pow(num,x/2)%mod;
    if(x%2)
    {
       return   (((p%mod)*(p%mod))%mod * (num%mod))%mod;
    }
    return ((p%mod)*(p%mod))%mod;

}
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<pow(a,b)%mod<<endl;
    }
}