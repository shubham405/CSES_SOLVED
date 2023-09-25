#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(vector<ll> &a, vector<ll> &b)
{
    if(a[1]==b[1])
    {
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
int main()
{
   ll n;
   cin>>n;
   vector<pair<ll,ll>> cust;
   for(ll i = 0;i <n;i++)
   {
       ll start,end;
       cin>>start>>end;
       cust.push_back({start,+1});
       cust.push_back({end,-1});

   }
   sort(cust.begin(),cust.end());
   ll cur=0, ans = 0;
   for(auto it:cust)
   {
     cur+=it.second;
     ans = max(ans,cur);
   }
   cout<<ans<<endl;
   
}