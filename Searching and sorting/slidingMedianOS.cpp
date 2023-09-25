#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
template<typename T>
using ordered_set =tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    ordered_set<pp> st;
    ll index = (k-1)/2;
    for(ll i = 0;i<n;i++)
    {
        ll  x;
        cin>>x;
        arr[i]=x;
        st.insert({x,i});
       // cout<<st.size()<<" ";
        if(st.size()==k)
        {

            pair<ll,ll> p =*st.find_by_order(index);
            cout<<p.first<<" ";
            st.erase({arr[i-k+1],i-k+1});
            //cout<<arr[i-k]<<" "<<i-k<<endl;
           // cout<<st.size()<<endl;
  
        }
    }
}