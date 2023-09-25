#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{

}
int main()
{
    ll n;
    cin>>n;
    set<ll> st;
    while (n--)
    {
        ll x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    
}