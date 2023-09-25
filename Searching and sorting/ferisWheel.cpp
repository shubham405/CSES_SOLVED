#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{

}
int main()
{
    ll n ,x;
    cin>>n>>x;
    vector<ll> arr(n);
    map<int,int>mp;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.find(arr[i])==mp.end())
        {
            mp[arr[i]]=1;
        }
        else
        {
            mp[arr[i]]++;
        }
    }
    sort(arr.begin(),arr.end());
   ll count=0;
   stack<ll> st;
   for(ll i = n-1;i>=0;i--)
   {
    ll num = arr[i];
      if(st.empty())
      {
        count++;
        st.push(x-num);
      }
      else
      {
        ll n  = st.top();
        if(n>=num)
        {
            st.pop();
        }
        else
        {
            st.push(x-num);
            count++;
        }
      }
   }

    cout<<count<<endl;
}