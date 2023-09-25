#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     ll n,q;
     cin>>n>>q;
     vector<ll> arr(n), position(n);
     for(ll i = 0 ;i<n;i++)
     {
        cin>>arr[i];
        position[arr[i]]=i;
     }
     ll ans = 0;
     for(ll i = 0 ;i<n-1;i++)
     {
        if(position[i]>position[i+1])
        {
            ans++;
        }
     }
     set<pair<int,int>> st;
     while(q--)
     {
        ll l,r;
        cin>>l>>r;

     }

}