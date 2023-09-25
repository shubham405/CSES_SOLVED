#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    set<pair<ll,ll>> leftSt,rightSt;
    vector<ll> arr(n);
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(k == 1)
    {
        for(auto it:arr)
           cout<<it<<" ";   
    }
    else if(k==2)
    {
        for(ll i =1;i<n;i++)
        {
            cout<<min(arr[i],arr[i-1])<<" ";
        }
    }
    else
    {
        vector<pair<ll,ll>> temp;
        for(ll i =0;i<k;i++)
        {
           temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        for(ll i = 0;i<k/2+(k%2);i++)
        {
            leftSt.insert(temp[i]);
        }
        for(ll i = k/2+(k%2);i<k;i++)
        {
            rightSt.insert(temp[i]);
        }
        //extracting mininum from left set
        auto it = leftSt.rbegin();
        cout<<it->first<<" ";
        for(ll i =1;i<n-k+1;i++)
        {
            if(leftSt.count({arr[i-1],i-1}))
            {
                leftSt.erase({arr[i-1],i-1});
            }
            else
            {
                rightSt.erase({arr[i-1],i-1});
            }

            // if maximum element from left set is smaller than current element then insert it into right set
            if(*leftSt.rbegin()<make_pair(arr[i+k-1],i+k-1))
            {
                rightSt.insert({arr[i+k-1],i+k-1});
            }
            else
            {
                leftSt.insert({arr[i+k-1],i+k-1});
            }
            while(leftSt.size()<k/2+(k%2))
            {
                pair<ll,ll> p =  *rightSt.begin();
                leftSt.insert(p);
                rightSt.erase(p);
            }
            while(leftSt.size()>k/2+(k%2))
            {
                pair<ll,ll> p =  *leftSt.rbegin();
                rightSt.insert(p);
                leftSt.erase(p);
            }
            cout<<leftSt.rbegin()->first<<" ";

        }
    }
}