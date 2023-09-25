#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(vector<ll> &a, vector<ll> &b)
{
    if(a[1]==b[1])
    {
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
int main()
{
   ll n;
   cin>>n;
   vector<vector<ll>> movie;
   for(ll i = 0;i <n;i++)
   {
       ll start,end;
       cin>>start>>end;
       movie.push_back({start,end});
   }
   sort(movie.begin(),movie.end(),cmp);
   ll curEnd = 0,count=0;
   for(auto it: movie)
   {
      ll start = it[0], end = it[1];
      if(start>=curEnd)
      {
        count++;
         curEnd = end;
      }
   }
   cout<<count<<endl;
}