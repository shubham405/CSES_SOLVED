#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll n;
  cin>>n;
  vector<string> arr;
  arr.push_back("0");
  arr.push_back("1");
  for(ll i =2;i<1<<n;i<<=1)
  {
    for(ll j=i-1;j>=0;j--)
    {
        arr.push_back(arr[j]);
    }
    for(ll x = 0;x<arr.size()/2;x++)
    {
        arr[x] = "0"+arr[x];
    }
    for(ll x=arr.size()/2;x<arr.size();x++)
    {
        arr[x] = "1"+arr[x];
    }
  }
  for(auto it:arr)
  {
    cout<<it<<endl;
  }
}