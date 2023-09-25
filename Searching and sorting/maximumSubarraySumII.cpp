#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    
    vector<ll> prefixSum(n+1);
    set<pair<ll,ll>> st;
    for(ll i = 1;i<=n;i++)
    {
        cin>>prefixSum[i];
    }
    prefixSum[0]=0;
    for(ll i =1;i<=n;i++)
    {
        prefixSum[i]+=prefixSum[i-1];
    }
    for(ll i =a;i<=b;i++)
    {
        st.insert({prefixSum[i],i});
    }
    ll ans =-1e18;
    for(ll i=1;i<=n-a+1;i++)
    {
        auto it = *st.rbegin();
        ll x = it.first-prefixSum[i-1];
        ans = max(ans,x);
        if(i+b<=n)
        {
            st.insert({prefixSum[i+b],i+b});
        }
        st.erase({prefixSum[i+a-1],i+a-1});

    }
    cout<<ans<<endl;
   
    
}