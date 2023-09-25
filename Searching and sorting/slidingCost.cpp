#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pp pair<ll,ll>
template<typename T>
using ordered_set =tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>;
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    ordered_set<pp> os;
    vector<ll>temp;
    for(ll i= 0;i<k;i++)
    {
        os.insert({arr[i],i});
        temp.push_back(arr[i]);
    }
    sort(temp.begin(),temp.end());
    ll x=0,y=0;
    ll median  = os.find_by_order(k/2)->first;
    if(k%2)
    {
        for(ll i = 0;i<k/2;i++)
        {
            y+=temp[i];
        }
        for(ll i = (k+1)/2;i<k;i++)
        {
            x+=temp[i];
        }
        cout<<x-y<<" ";
        for(ll i = k;i<n;i++)
        {
            ll re =  arr[i-k];
            os.erase({arr[i-k],i-k});
            os.insert({arr[i],i});
          ll curMedian = os.find_by_order(k/2)->first;
            if(re>median)
            {
                x-=re;
            }
            else if(re<median)
            {
                y-=re;
                if(curMedian==arr[i])
                {
                    y+=median;
                }
               else if(curMedian<arr[i])
                {
                    
                }
            }
            else
            {
                if(curMedian == arr[i])
                {
                    cout<<x-y<<" ";
                }
                else if(curMedian>arr[i])
                {
                   y +=arr[i]-curMedian;
                   cout<<x-y<<" ";
                }
                else
                {
                   x+=arr[i]-curMedian;
                   cout<<x-y<<" ";
                }
            }
            
        }
    }
    else
    {

    }
    
    
    
    
    }
