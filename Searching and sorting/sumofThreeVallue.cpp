#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll n,x ;
    cin>>n>>x;
    vector<pair<ll,ll>> arr(n);
    for(ll i = 0;i<n;i++)
    {
        ll num;
        cin>>num;
        arr[i]={num,i};
    }
        
    sort(arr.begin(),arr.end());
    for(ll i =0;i<n-2;i++)
    {
       ll j= i+1, k = n-1;
       ll num1 = arr[i].first;
       while(j<k && j<n)
       {
        //cout<<j<<" "<<k<<endl;
         if(num1+arr[j].first+arr[k].first==x)
         {
            cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1;
            return 0;
         }
         else if(num1+arr[j].first+arr[k].first>x)
         {
            k--;
         }
         else
         {
            j++;
         }
         
       }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}