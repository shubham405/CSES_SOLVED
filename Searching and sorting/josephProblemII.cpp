#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
template<typename T>
using ordered_set= tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    ll n,k;
    cin>>n>>k;
    ordered_set<ll> st;
    for(ll i = 1;i<=n;i++)
    {
        st.insert(i);
    }

    ll i = 0;
    while(st.size()>1)
    {
        i = (i%st.size()+k%st.size())%st.size();
        auto it = st.find_by_order(i);
        cout<<*it<<" ";
        st.erase(it);
    }
    cout<<*st.begin();



   
}