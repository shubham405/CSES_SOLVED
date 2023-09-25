#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i = 0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(),arr.end());
    ll curSum = 0, ans = 0;
   for(auto it:arr)
   {
    curSum+=it.first;
    ans+=-curSum+it.second;
   }
   cout<<ans;
}