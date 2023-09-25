#include<bits/stdc++.h>
using namespace std;
#define ll long long
 int main()
 {
    ll n,m;
    cin>>n>>m;
    
    multiset<ll> st;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        st.insert(x);
        
    }
    for(ll i =0;i<m;i++)
    {
        ll x;
        cin>>x;
        auto it = st.upper_bound(x);
        if(it==st.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            it--;
            cout<<*it<<endl;
            st.erase(it);
        }
    }

    }