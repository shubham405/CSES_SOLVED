#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,t;
    cin>>n>>t;
    vector<ll> arr(n);
    for(ll i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans = arr[0]*t;
    ll low = 0, high = ans;
    while(low<=high)
    {
        ll mid = low+ (high-low)/2;
        ll count = 0;
        for(auto it:arr)
        {
            count+=mid/it;
        }
        if(count>=t)
        {
            ans = min(ans,mid);
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }

    }
    cout<<ans<<endl;
}          