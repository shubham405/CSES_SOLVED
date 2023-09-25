#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll ans =1;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    multiset<ll> st;
    st.insert(arr[0]);
    for(ll  i =1;i<n;i++)
    {
        auto it = st.upper_bound(arr[i]);
        if(it==st.end())
        {
            st.insert(arr[i]);
        }
        else
        {
            st.erase(it);
            st.insert(arr[i]);
        }

        ans = max(ans,(ll)st.size());   
    }
    cout<<ans<<endl;
}