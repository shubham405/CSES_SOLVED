#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector<ll> adj[],ll node, ll parent,vector<ll> &flatten)
{
    flatten.push_back(node);
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            dfs(adj,it,node,flatten);
        }
    }
    flatten.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> adj[n], flatten, value(n,0);
    for(ll i =0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
  
   

}