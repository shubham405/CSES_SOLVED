#include<bits/stdc++.h>
using namespace std;
#define ll long long
//int up[50000][17];
//vector<int> tree[50000];
void dfs(vector<ll> adj[], ll node,vector<ll> &level, ll l)
{
    level[node]=l;
    for(auto it:adj[node])
    {
        dfs(adj,it,level,l+1);
    }
}
void binary_lifting(ll src, ll parent, vector<ll> adj[],vector<vector<ll>> &up)
{
    //cout<<src<<" "<<parent<<endl;
    up[src][0]=parent;
    //cout<<src<<" ->";
    for(ll i =1;i<20;i++)
    {
        
        if(up[src][i-1]!=-1)
        {
            //cout<<up[src][i-1]<<" ";
            
            up[src][i]= up[up[src][i-1]][i-1];
            //cout<<up[src][i]<<" ";
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
        binary_lifting(child,src,adj,up);
    }
}
void lca(ll u ,ll v, ll jump, vector<vector<ll>>& up )
{
    if(jump == 0)
    {
        if(u==v)
        {
            cout<<u+1<<endl;
        }
        else
        {
            for(ll  i =19;i>=0;i--)
            {
                if(up[u][i]!=up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                }
            }
            cout<<up[u][0]+1<<endl;
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
            cout<<u+1<<endl;
            return;
        }

        for(ll  i =19;i>=0;i--)
            {
                if(up[u][i]!=up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                }
            }
           cout<<up[u][0]+1<<endl;

    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> adj[n],level(n);
    for(ll i = 1;i<n;i++)
    {
        ll x;
        cin>>x;
        adj[x-1].push_back(i);
        //adj[x].push_back(i);
    }
    dfs(adj,0,level,1);
    vector<vector<ll>> up(n+10,vector<ll>(20));
    binary_lifting(0,-1,adj,up);
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        int i =-1;
        //y--;
        if(level[x]>=level[y])
        {
            lca(y,x, abs(level[x]-level[y]),up);
        }
        else
        {
             lca(x,y, abs(level[x]-level[y]),up);
        }

    }

    
}