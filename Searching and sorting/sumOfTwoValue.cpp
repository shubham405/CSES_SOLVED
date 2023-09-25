#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,x;
    cin>>n>>x;
    map<ll,ll> mp;
    vector<ll> arr;
    for(ll i = 0;i<n;i++)
    {
        ll x;
        cin>>x;
       arr.push_back(x);
    }
    bool t =true;
    ll i =0;
    for(auto it:arr)
    {
        ll req = x-it;
        if(mp.find(req)!=mp.end())
        {
            cout<<i+1<<" "<<mp[req]+1<<endl;
            t=false;
            break;
        }
        mp[it]=i;
        i++;
    }
    if(t)
    {
        cout<<"IMPOSSIBLE";
    }
}