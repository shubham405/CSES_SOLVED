#include<bits/stdc++.h>
using namespace std;
#define ll long long
void TOH(int n , int l, int r, int m)
{
    if(n==0)
    {
        return;
    }
    TOH(n-1,l,m,r);
    cout<<l<<" "<<r<<endl;
    TOH(n-1,m,r,l);
}
int main()
{
    ll n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    TOH(n,1,3,2);
}