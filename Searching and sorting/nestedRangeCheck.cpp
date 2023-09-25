#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, pair<ll,ll>> pp;
bool cmp(pp &a1, pp &a2)
{
    if(a1.second.first == a2.second.first)
       return a1.second.second>a2.second.second;
    return a1.second.first<a2.second.first;
}
bool ccmp(pp &a1,pp &a2)
{
    if(a1.second.first == a2.second.first)
       return a1.second.second<a2.second.second;
    return a1.second.first<a2.second.first;
}
int main()
{
    ll  n;
    cin>>n;
    vector<pp>arr(n);
    vector<ll> contained(n),contains(n);
    for( ll i = 0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        arr[i]={i,{x,y}};
    }
    sort(arr.begin(),arr.end(),cmp);
    ll maxEnd = 0;
    for( auto it:arr)
    {
        if(it.second.second<=maxEnd)
        {
            contained[it.first]=1;
        }
        maxEnd = max(maxEnd,it.second.second);
    }
    ll prevr = INT_MAX;
   //sort(arr.begin(),arr.end(),ccmp);
   for(ll i = n-1;i>=0;i--)
   {
     pp it = arr[i];
     if(it.second.second>=prevr)
     {
        contains[it.first]=1;
     }
     prevr =min(prevr,it.second.second);
   }
   for(auto it:contains)
   {
    cout<<it<<" ";
   }
   cout<<endl;
   for(auto it:contained)
   {
    cout<<it<<" ";
   }
    

}