/**
 * @file SegmentTreewithLazyPropagation.cpp
 * @author your name (you@domain.com)
 * @brief segment tree for sumation query with range update
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
        // for minim
        //take minim
    }
    void updateWithLazy(int low, int high, int index, int l, int r, int val)
    {
        // update the previous remaining updates
        // and propagate downwords
        if(lazy[index]!=0)
        {
            st[index]+= (high-low+1)*lazy[index];
            // for min st[index]+=lazy[index];
            // propagate downwords
            if(low!=high)
            {
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            lazy[index]=0;
        }
        // if no overlap just return;
        if(high<l || low>r)
        {
            return;
        }
        // if full operlap update and lazy propagate
        if(low>=l && high<=r)
        {
            st[index]+= (high-low+1)*val;
            if(low!=high)
            {
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }
            return;
        }
        int mid = low+(high-low)/2;
        updateWithLazy(low,mid,2*index+1,l,r,val);
        updateWithLazy(mid+1,high,2*index+2,l,r,val);
        st[index]= st[2*index+1]+st[2*index+2];
        // return minimum
        
    }
    int query(int low, int high, int index, int l, int r)
    {
        if(lazy[index]!=0)
        {
            st[index]+=(high-low+1)*lazy[index];
            if(high!=low)
            {
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];

            }
        }
        if(low>r || high<l)
        {
            return 0;
        }
        if(low>=l && high<=r)
        {
            return st[index];
        }
        int mid =  low+(high-low)/2;
        int left = query(low,mid,2*index+1,l,r);
        int right = query(mid+1,high,2*index+2,l,r);
        return left+right;

    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
}