#include<bits/stdc++.h>
using namespace std;
#define ll int
int arr[21];
int up[200001][20];
void dfs(vector<ll> adj[], ll node,ll parent,vector<ll> &level, ll l)
{
    level[node]=l;
    for(auto it:adj[node])
    {
        if(it!=parent)
        dfs(adj,it,node,level,l+1);
    }
}
void binary_lifting(ll src, ll parent, vector<ll> adj[])
{
   
    up[src][0]=parent;
    for(ll i =1;i<20;i++)
    {
        
        if(up[src][i-1]!=-1)
        {
            
            up[src][i]= up[up[src][i-1]][i-1];
            
        }
        else
        {
            up[src][i]=-1;
        }
    }
    //cout<<"\n";

    for(auto child:adj[src])
    {
        if(child!=parent)
         binary_lifting(child,src,adj);
    }
}
void lca(ll u ,ll v, ll jump )
{
    ll ans = jump;
    if(jump == 0)
    {
        if(u==v)
        {
            cout<<ans<<endl;
        }
        else
        {
            
            for(ll  i =19;i>=0;i--)
            {
                if(up[u][i]!=up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                    ans+=arr[i+1];
                }
            }
            cout<<ans+2<<endl;
        }
        return;
    }
    else
    {
        ll i = -1;
        ll x = jump;
        while(jump)
        {
            i++;
            jump>>=1;
        }
        while(i>=0)
        {
            ll next  =1<<i;
            if(x&next)
            {
                v = up[v][i];
            }
            i--;
        }
        if(u==v)
        {
            cout<<ans<<endl;
            return;
        }

        for(ll  i =19;i>=0;i--)
            {
                if(up[u][i]!=up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                   ans+=arr[i+1];
                }
            }
           cout<<ans+2<<endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<ll> adj[n], level(n);
    arr[0]=1;
    for(ll i  =1;i<21;i++)
    {
        arr[i] = 2*arr[i-1];
    }
    for(ll i =0;i<n-1;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(adj,0,-1,level,0);

    
    binary_lifting(0,-1,adj);
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        if(level[x]>=level[y])
        {
            lca(y,x, abs(level[x]-level[y]));
        }
        else
        {
             lca(x,y, abs(level[x]-level[y]));
        }
    }
}