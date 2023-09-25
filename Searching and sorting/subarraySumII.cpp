#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, x;
    cin>>n>>x;
    vector<ll> arr(n),subSum;
    for(ll i = 0;i<n;i++) 
     cin>>arr[i];
    map<ll,ll> mp;
    ll sum= 0,ans=0;
    for(auto it:arr)
    {
        sum+=it;
        subSum.push_back(sum);
        if(sum==x)
          ans++;
    }
    for(auto it:subSum)
    {
        if(mp.find(it-x)!=mp.end())
        {
            ans+=mp[it-x];
        }
        mp[it]++;
    }
    cout<<ans<<endl;
}