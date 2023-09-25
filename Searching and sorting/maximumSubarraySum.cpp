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
    ll curSum=arr[0], maxSum = arr[0];
    for(ll  i=1;i<n;i++)
    {
        ll num = arr[i];
       curSum =  max(num,curSum+num);
       maxSum  = max(curSum,maxSum);
    }
    cout<<maxSum<<endl;
}