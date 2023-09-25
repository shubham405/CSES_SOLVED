#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll num = (n*(n+1))/2;
    if(num%2)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        if(n%2)
        {
            ll x = 1, y = n-1;
            cout<<n/2<<endl;
            for(int i = 1;i<=n/4;i++)
            {
                cout<<x<<" "<<y<<" ";
                x+=2;
                y-=2;
            }
            cout<<n<<endl;

            cout<<n-(n/2)<<endl;

            for(int i = 0;i<=n/4;i++)
            {
                cout<<x<<" "<<y<<" ";
                x+=2;
                y-=2;
            }

            

        }
        else
        {
            ll x = 1, y = n;
            cout<<n/2<<endl;
            for(ll i = 1;i<=n/4;i++)
            {
                cout<<x<<" "<<y<<" ";
                x+=2;
                y-=2;
            }
            cout<<endl;
            cout<<n/2<<endl;
            for(ll i = 1;i<=n/4;i++)
            {
                cout<<x<<" "<<y<<" ";
                x+=2;
                y-=2;
            }

        }
    }
}