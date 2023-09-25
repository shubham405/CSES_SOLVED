#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int arr[26];
    memset(arr,0,sizeof(arr));
    string s;
    cin>>s;
    ll n =s.size();
    vector<char> ans(n);
    for(auto it:s)
    {
        arr[it-'A']++;
    }
    ll count= 0;

    for(int i = 0;i<26;i++)
    {
        if(arr[i]%2)
        {
            ans[n/2]=i+'A';
            arr[i]-=1;
            count++;
        }
    }
    if(count>1)
    {
        cout<<"NO SOLUTION\n";
    }
    else
    {
        ll x =0,y=n-1;
        for(int i = 0;i<26;i++)
        {
            while(arr[i])
            {
                ans[x]=i+'A';
                ans[y]=i+'A';
                x++;
                y--;
                arr[i]-=2;
            }
        }
    }
    for(auto it:ans)
    {
        cout<<it;
    }
}