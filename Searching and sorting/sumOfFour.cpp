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
    for(ll i =0;i<n;i++)
    {
        for(ll j = i+1;j<n-2;j++)
        {
             ll k= j+1, l = n-1;
         ll num1 = arr[i].first;
         ll num2 = arr[j].first;
        while(k<l && k<n)
       {
            //cout<<j<<" "<<k<<endl;
            if(num1+arr[k].first+arr[l].first+num2==x)
            {
                cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[k].second+1<<" "<<arr[l].second+1;
                return 0;
            }
            else if(num1+arr[l].first+arr[k].first+num2>x)
            {
                l--;
            }
            else
            {
                k++;
            }
            
         }
        }
      
    }
    cout<<"IMPOSSIBLE";
    return 0;
}