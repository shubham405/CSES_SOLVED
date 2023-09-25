#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
    }

    else if(n<=3)
    {
        cout<<"NO SOLUTION\n";
    }
    else if(n==4)
    {
        cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;
    }
    else
    {
        int num1 = n,num2 = n-1;
        while(num1>0)
        {
            cout<<num1<<" ";
            num1-=2;
        }
        while(num2>0)
        {
            cout<<num2<<" ";
            num2-=2;
        }
    }
}