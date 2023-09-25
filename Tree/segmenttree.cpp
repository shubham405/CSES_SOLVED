#include <bits/stdc++.h>
using namespace std;
class Segmenttree
{
private:
    vector<int> seg;

public:
    Segmenttree(int n)
    {

        seg.resize(4 * n + 1);
    }
    void print()
    {
        for (auto it : seg)
        {
            cout << it << " ";
        }
    }
    void build(int index, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
    int query(int index, int low, int high, int l, int r)
    {
        // no overlap

        if (high < l or r < low)
            return INT_MAX;
        // complete overlap
        if (low >= l && high <= r)
        {
            return seg[index];
        }
        int mid = (low + high) / 2;
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);

        return min(left, right);
    }
    void update(int index, int low, int high, int val, int i)
    {
        if (low == high)
        {
            seg[index] = val;
            return;
        }
        int mid = (low + high) / 2;
        
        if (i <= mid)
        {
            update(2 * index + 1, low, mid, val, i);
        }

        else
        {
            update(2 * index + 2, mid + 1, high, val, i);
        }

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    Segmenttree sgTree(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout<<arr[i]<<endl;
    }

    sgTree.build(0, 0, n - 1, arr);

    // sgTree.print();

    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {

        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            // cout << l << " " << r << endl;
            cout << sgTree.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int ind, val;
            cin >> ind >> val;
            sgTree.update(0, 0, n - 1, val, ind);
            cout << "updated\n";
            arr[ind] = val;
        }
    }
}