#include<bits/stdc++.h>
using namespace std;
#define ll int
int main()
{
    ll x,n;
    cin>>x>>n;
    set<ll> st;
    st.insert(0);
    st.insert(x);
    map<int,int> mp;
    mp[x]=1;
    while(n--)
    {
        ll p;
        cin>>p;
        st.insert(p);
        auto it = st.find(p);
        ll pv = *prev(it);
        ll nxt = *next(it);
        mp[nxt-pv]--;
        if(mp[nxt-pv]==0)
        {
            mp.erase(nxt-pv);
        }
        mp[p-pv]++;
        mp[nxt-p]++;
        auto itr = mp.rbegin();
        cout<<itr->first<<" ";
    }
}