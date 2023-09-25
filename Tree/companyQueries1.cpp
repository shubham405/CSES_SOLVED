#include<bits/stdc++.h>
using namespace std;
#define ll long long
//int up[50000][17];
//vector<int> tree[50000];
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
void findDepth(vector<ll> adj[], ll node, ll &d,ll dd )
{
    d = max(d,dd);
    
    for(auto it: adj[node])
    {
       
        findDepth(adj,it,d,dd+1);
    }
    
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> adj[n];
    for(ll i = 1;i<n;i++)
    {
        ll x;
        cin>>x;
        adj[x-1].push_back(i);
        //adj[x].push_back(i);
    }
    ll d = 0;
    findDepth(adj,0,d,0);
   
    vector<vector<ll>> up(n+10,vector<ll>(20));
    binary_lifting(0,-1,adj,up);
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        int i =-1;
        //y--;
        int jump = y;
        if(y==0)
        {
           cout<<x+1<<endl;
           continue;
        }
        while(y)
        {
            i++;
            y>>=1;
        }
        while(i>=0)
        {
            int next = 1<<i;
            if(jump & next)
            {
                 x = up[x][i];
                 //cout<<x<<" "<<i<<endl;
            }
            if(x ==-1)
            {
                break;
            }
            i--;
        }
        if(x!=-1)
        {
             cout<<x+1<<"\n";
        }
       
        else 
        cout<<-1<<endl;
    }
    // for(ll i = 0;i<n;i++)
    // {
    //     cout<<i<<" ->";
    //     for(auto it:up[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    
}