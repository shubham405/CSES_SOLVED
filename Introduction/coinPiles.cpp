#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll a,b;
    cin>>a>>b;
    ll x = min(a,b);
    ll y = max(a,b);
    if(2*x<y)
    {
        cout<<"NO\n";
        return;
    }
    if((x+y)%3==0)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}