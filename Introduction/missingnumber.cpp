#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n-1);
    ll sum = 0;
    for(int i= 0;i<n-1;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll maxi =  (n*(n+1))/2;
    ll ans =  maxi -sum;
    cout<<ans;
}