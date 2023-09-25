#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll a,b;
    cin>>a>>b;
    ll dif = ceil(double(max(a,b))/double(min(a,b)));
    if(dif>2)
    {
        cout<<"NO\n";
    }
    else if(dif==2)
    {
        cout<<"YES\n";
    }
    else
    {
        
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