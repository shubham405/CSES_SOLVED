#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    int count = 1,ans=1, n=s.size();
    for(int i = 1;i<n;i++)
    {
        if(s[i]==s[i-1])
            count++;
        else
         count=1;
        ans= max(ans,count);
    }
    cout<<ans;
}