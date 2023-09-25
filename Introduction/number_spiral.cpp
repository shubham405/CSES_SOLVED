#include<bits/stdc++.h>
using namespace std;
#define ll unsigned  long long 
void solve()
{
    ll x,y;
    cin>>x>>y;
    ll r=max(x,y);
    ll num = pow(r,2)-r+1;
    // cout<<num<<endl;
    ll dif = max(x,y)-min(x,y);
    // cout<<dif<<endl;
    if(x==y)
    {
        cout<<num<<endl;
    }
    else if(x>y)
    {
        if(x%2)
        {
            cout<<num-dif<<endl;
        }
        else
        {
            cout<<num+dif<<endl;
        }
    }
    else
    {
        if(y%2)
        {
            cout<<num+dif<<endl;
        }
        else
        {
            cout<<num-dif<<endl;
        }
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