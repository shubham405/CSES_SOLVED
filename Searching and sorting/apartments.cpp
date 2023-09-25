#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> apl(n),apr(m);
    for(ll i = 0;i<n;i++)
    {
        cin>>apl[i];
    }
    for(ll i = 0;i<n;i++)
    {
        cin>>apr[i];
    }
    sort(apl.begin(),apl.end());
    sort(apr.begin(),apr.end());
    // for(auto it: apr)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    ll i =0, j =0,count=0;
    
    while(i<n && j<m)
    {
        ll aplicant = apl[i];
        ll apart = apr[j];
        if(apart-k<=aplicant && apart+k>=aplicant)
        {
            count++;
            j++;
            i++;
            continue;
        }
        if(aplicant>apart)
        {
            j++;
        }
        else
        {
            i++;
        }
        
    }
    cout<<count<<endl;
}