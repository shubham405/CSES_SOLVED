#include<bits/stdc++.h>
using namespace std;
class ST
{
    vector<int> st,lazy;
    public:
    ST(int n)
    {
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int low, int high, int index, int arr[])
    {
        if(low==high)
        {
            st[index] = arr[low];
            return;
        }
        int mid = low+(high-low)/2;
        build(low,mid,2*index+1,arr);
        build(mid,high,2*index+2,arr);
        st[index]= st[2*index+1]+st[2*index+2];
    }
    void update(int low, int high, int ind, int l, int r, int val)
    {
        // update the previous remaining updates
    }
};