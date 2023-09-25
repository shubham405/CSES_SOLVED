#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,pair<ll,ll>> pp;
bool cmp(pp &a1,pp &a2)
{
    if(a1.second.first == a2.second.first)
    {
        return a1.second.second<a2.second.second;
    }
    return a1.second.first<a2.second.first;
}
int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> arr(n);
    set<pair<ll,ll>> st;
    vector<ll> ans(n);
    for(ll i = 0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={i,{x,y}};
    }
    sort(arr.begin(),arr.end(),cmp);
    st.insert({arr[0].second.second,1});
    //vector<ll> ans(n);
    //cout<<1<<" ";
    ans[arr[0].first]=1;
    ll count = 1;
    for( ll i = 1;i<n;i++)
    {
        auto it = *st.begin();
        if(arr[i].second.first>it.first)
        {
            //cout<<it.second<<" ";
            ans[arr[i].first]=it.second;
            st.insert({arr[i].second.second,it.second});
            st.erase(it);
        }
        else
        {
            count++;
            //cout<<count<<" ";
            ans[arr[i].first] = count;
            st.insert({arr[i].second.second,count});
        }
    }
    cout<<count<<endl;
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
}