#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,pair<ll,ll>> pp;
int main()
{
    ll n ;
    cin>>n;
    vector<ll> adj[n+1], deg(n+1,0);
    map<ll,bool> mp;
    for(ll i = 0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        deg[y]++;
    }
    priority_queue<pp,vector<pp>, greater<pp>> pq;
    for(ll i =1;i<=n;i++)
    {
        if(adj[i].size())
        {
            for(auto it:adj[i])
            {
                ll  x  =deg[it];
                pq.push({x,{i,it}});
            }
        }
    }
    ll ans = 0;
    while(!pq.empty())
    {
       auto it = pq.top();
       pq.pop();
       ll  x  =it.second.first, y = it.second.second;
       cout<<x<<" "<<y<<" "<<deg[x]<<" "<<deg[y]<<endl;
       if(mp[x]||mp[y])
          continue;
        ans++;
        mp[x]=1;
        mp[y]=1; 
    }
    cout<<ans;



}
