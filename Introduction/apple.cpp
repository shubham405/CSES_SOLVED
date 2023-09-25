#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll find(ll index, ll curSum, ll totalSum,vector<ll>&arr, ll n)
{
    if(index>=n)
    {
        ll s1 = curSum;
        ll s2 = totalSum-curSum;
        return abs(s1-s2);
    }
    

    return min(find(index+1,curSum,totalSum,arr,n),find(index+1,curSum+arr[index],totalSum,arr,n));
    

    
    
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll sum=0;
    for(ll i =0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
   ll ans = sum;
   //vector<vector<ll>> dp(n,vector<ll>(sum+1,-1));
   cout<<find(0,0,sum,arr,n);
   

}