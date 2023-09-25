#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tree(vector<ll>adj[], int node, vector<ll> &ans)
{
    if(adj[node].size()==0)
    {
        ans[node]=0;
        return 1;
    }
    ll x = 0;
    for(auto it: adj[node])
    {
        x+=tree(adj,it,ans);
    }
     ans[node]=x;
     return x+1;

}
int main()
{
    ll n;
    cin>>n;
    vector<ll>adj[n+1], ans(n+1,0);
    for(ll i =2;i<=n;i++)
    {
      ll x;
      cin>>x;
      adj[x].push_back(i); 
    }
   
    for(ll i =1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            tree(adj,i,ans);
        }
    }
    for(ll i = 1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}