#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs1(set<ll> adj[], ll node,ll parent,vector<ll> &in)
{
    

    for(auto it: adj[node])
    {
        if(it!=parent)
        {
            dfs1(adj,it,node,in);
            in[node] = max(in[node],1+in[it]);
        } 
    }
}
void dfs2(ll node,ll par,set<ll> adj[],vector<ll> &out,vector<ll> &in)
{
    int maxi1=-1;
    int maxi2=-1;

    for(ll v:adj[node])
    {
        // if(node==10)
        // {
        //     cout<<v<<" ";
        // }
        if(v!=par)
        {
            if(maxi1<in[v])
            {
                maxi2=maxi1;
                maxi1=in[v];
            }
            else if(maxi2<in[v]){
                maxi2=in[v];
            }
        }
    }
    
    //cout<<node<<" "<<maxi1<<" "<<maxi2<<endl;
    for(ll v:adj[node])
    {
        if(par!=v)
        {
            ll longest=maxi1;
            if(longest==in[v])
            {
                longest=maxi2;
            }
                
            out[v]=max(out[v],1+max(out[node],1+longest));
            dfs2(v,node,adj,out,in);
        }
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
    set<ll> adj[n+1];
    vector<ll>  dis(n+1,0),out(n+1,0), in(n+1,0);
    for(ll i = 0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    dfs1(adj,1,-1,in);
    
    dfs2(1,-1,adj,out,in);
    
//    for(auto it: out)
//      cout<<it<<" ";

    for(ll i = 1;i<=n;i++)
    {
        cout<<max(in[i],out[i])<<" ";
    }
}