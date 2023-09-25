#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for( ll i =0;i<n;i++)
       cin>>arr[i];
    stack<pair<ll,ll>> st;
    for(ll i = 0;i<n;i++)
    {
        if(st.empty())
        {
            cout<<"0 ";
            
        }
        else
        {
            auto it = st.top();
            if(arr[i]>it.first)
            {
                cout<<it.second<<" ";
            }
            else
            {
                while(!st.empty() && st.top().first>=arr[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    cout<<"0 ";
                }
                else
                {
                    cout<<st.top().second<<" ";
                }
                
            }
        }
        st.push({arr[i],i+1});
    }
}