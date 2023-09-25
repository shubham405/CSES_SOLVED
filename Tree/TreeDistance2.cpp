#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(ll node,ll parent,vector<ll> adj[],vector<ll>&subAns,vector<ll> &nodeCount )
{
   ll ans=0;
   ll count =0;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            dfs(it,node,adj,subAns,nodeCount);
            
            count+=nodeCount[it]+1;
            ans+=subAns[it];
        }
       
    }
    nodeCount[node]=count;
    subAns[node]=ans+count;
     
}

void dfs1(ll node,ll parent,vector<ll> adj[],vector<ll>&subAns,vector<ll> &nodeCount, vector<ll> &dp,ll &n)
{
    for(auto it: adj[node])
    {
        if(it != parent)
        {
            dp[it] = subAns[it]+n-1-nodeCount[it]+(dp[node]-(subAns[it]+nodeCount[it]+1));
            
            dfs1(it,node,adj,subAns,nodeCount,dp,n);  
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> adj[n+1], subAns(n+1,0),nodeCount(n+1,0), dp(n+1);
    for(ll i =0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,adj,subAns,nodeCount);
     dp[1]=subAns[1];
    dfs1(1,-1,adj,subAns,nodeCount,dp,n);
   
    for(ll i =0;i<n;i++)
    {
        cout<<dp[i+1]<<" ";
    }
    

}