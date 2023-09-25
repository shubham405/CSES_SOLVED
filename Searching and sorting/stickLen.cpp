#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for( ll i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll  ans = 0, ov;
    sort(arr.begin(),arr.end());
    ov = arr[n/2];
    for(auto it:arr)
    {
        ans +=abs(it - ov);
    }
    cout<<ans<<endl;

}