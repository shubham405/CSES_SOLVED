#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    ll high = 0;
    for(ll i = 0 ; i <n;i++)
    {
          cin>>arr[i];
          high+=arr[i];
    }
     
    ll low = *max_element(arr.begin(),arr.end());
    ll ans = 1e18;
    while(low<=high)
    {
        ll mid = low+ (high-low)/2;
        //cout<<mid<<endl;
        ll sum = 0;
        ll count = 1;
        for(auto it:arr)
        {
            if(sum+it>mid)
            {
                count++;
                sum = it;
            }
            else
            {
                sum+=it;
            }
        }
        if(count<=k)
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