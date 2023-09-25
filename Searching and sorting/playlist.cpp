#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0;i<n;i++)
       cin>>arr[i];
    map<ll,bool> mp;
    ll ans = 1, i=0;
    for(auto it:arr)
    {
        if(mp[it])
        {
            
            //cout<<i<<" ";
            while(i<n && arr[i]!=it)
            {
                mp.erase(arr[i++]);
            }
            mp.erase(arr[i++]);
            //cout<<i<<endl;
        }
        
        mp[it]=1;
        ans = max(ans,(ll)mp.size());
    }
    cout<<ans<<endl;
}