#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pp;
bool cmp(pair<ll,ll>&a1,pair<ll,ll>&a2)
{
   
    return a1.second<a2.second;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    set<pp>st;
    vector<pair<ll,ll>> arr(n);
    for(ll i = 0 ;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(),arr.end(),cmp);
    ll count=0,ans=0;

    for(auto it:arr)
    {
     if(st.size()==0)
     {
        st.insert({it.second*-1,count});
        ans++;
     }
     else
     {
        auto itr  = st.lower_bound({it.first*-1,-1});
        if(itr!=st.end())
        {
            st.erase(itr);
            st.insert({it.second*-1,count});
            ans++;
            
        }
        else if(itr == st.end() && st.size()<k)
        {
            st.insert({it.second*-1,count});
            ans++;
        }
     }
     count++;
      
      
    }

    cout<<ans;

    
}
