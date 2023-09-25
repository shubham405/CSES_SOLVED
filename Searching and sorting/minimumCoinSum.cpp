#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll sum =0;
    for(auto it:arr)
    {
        if(sum+1<it)
        {
            break;
         }
         sum+=it;
        
    }
    cout<<sum+1<<endl;
}