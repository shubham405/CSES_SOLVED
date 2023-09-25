#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(ll node, ll parent, vector<ll> adj[], vector<ll>&sa,ll d)
{

}
void cummulativeSum(ll node, ll parent, vector<ll> adj[], vector<ll> &val,vector<ll>&cs)
{
    ll sum = 0;
    for(auto it: adj[node])
    {
        if(it!=parent)
        {
            cummulativeSum(it,node,adj,val,cs);
            sum+=val[it-1]+cs[it];
        }
    }
    cs[node]=sum;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> adj[n+1],val(n), cs(n+1,0);
    unordered_map<ll,ll>mp;
    for(ll i  = 0;i<n;i++)
    {
        cin>>val[i];
    }
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cummulativeSum(1,-1,adj,val,cs);
    for(ll i =1;i<=n;i++)
    {
        cout<<cs[i]<<" ";
    }
}