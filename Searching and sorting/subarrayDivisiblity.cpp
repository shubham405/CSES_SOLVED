#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll n;
    cin>>n;
    map<ll,ll> mp;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    mp[0]=1;
    ll curSum = 0,ans = 0;
    for(auto it:arr)
    {
        curSum+=it;
        ll r = (curSum%n+n)%n;
        ans+=mp[r];
        mp[r]++;

        
    }
    cout<<ans<<endl;
}