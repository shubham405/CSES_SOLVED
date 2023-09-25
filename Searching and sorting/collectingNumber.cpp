#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n ;
    cin>>n;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    set<ll> st;
    ll ans = 0;
    st.insert(arr[0]);
    for(ll i =0;i<n;i++)
    {
       ll num = arr[i]-1;
       if(st.find(num)==st.end())
       {
        st.insert(arr[i]);
       }
       else
       {
        auto it = st.find(num);
         st.erase(it);
         st.insert(arr[i]);
       }

        ans = max(ans,(ll)st.size());
    }
    cout<<ans<<endl;
}