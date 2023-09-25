#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<ll,ll> mp;
    ll count = 0, unique = 0,j=0;
    for(ll i =0;i<n;i++)
    {
        if(mp.find(arr[i])==mp.end())
        {
            mp[arr[i]]=1;
        }
        else
        {
            mp[arr[i]]++;
        }
        if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[arr[j]]--;
                if(mp[arr[j]]==0)
                {
                    mp.erase(arr[j]);
                }
                j++;
            }
        }
        count+=i-j+1;

    }
    cout<<count;
}