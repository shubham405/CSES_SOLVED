#include<bits/stdc++.h>
using namespace std;
#define ll long long
void findDis(ll node, vector<ll> &dis,vector<ll> adj[], ll d,ll &ans, vector<ll>&vis)
{
    if(vis[node])
      return;
    //cout<<node<<" "<<d<<endl;
    vis[node]=1;
    dis[node]=d;
    ans = max(ans,d);
    for(auto it: adj[node])
    {
        findDis(it,dis,adj,d+1,ans,vis);
    }
}
int main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<ll> adj[n+1], dis(n+1,0),vis(n+1,0);
    for(ll i = 0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll node =  1,d = 0,ans = 0 ;
    findDis(1,dis,adj,0,ans,vis);
    for(ll i = 1;i<=n;i++)
    {
        //cout<<dis[i]<<" ";
        if(d<dis[i])
        {
            node = i;
            d = dis[i];
        }
    }
    // cout<<endl<<node<<endl;
    for(ll i = 1;i<=n;i++)
       vis[i]=0;
   // cout<<"hi\n";
    findDis(node,dis,adj,0,ans,vis);
    cout<<ans<<endl;
    
}