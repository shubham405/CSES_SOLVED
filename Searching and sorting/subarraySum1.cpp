#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n , x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
       cin>>arr[i];
    ll prev = 0, curSum = 0,count=0;
    for(ll i = 0 ;i<n;i++)
    {
        curSum+=arr[i];
        if(curSum==x)
        {
            count++;
            curSum-=arr[prev++];
        }
        if(curSum>x)
        {
            while(curSum>=x)
            {
                curSum-=arr[prev++];
                if(curSum==x)
                {
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;

}