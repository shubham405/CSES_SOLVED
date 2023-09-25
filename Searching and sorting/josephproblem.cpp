#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i =1;i<=n;i++)
    {
        arr.push_back(i);
    }
   while(arr.size()>1)
   {
    vector<int> temp;
    for(int i=0;i<arr.size();i++)
    {
        if(i%2)
        {
            cout<<arr[i]<<" ";
        }
        else
        {
            temp.push_back(arr[i]);
        }
    }
    if(arr.size()%2)
    {
        arr.clear();
        arr.push_back(temp[temp.size()-1]);
        temp.pop_back();
        for(auto it:temp)
        {
            arr.push_back(it);
        }
    }
    else
    {
        arr = temp;
    }

   }
   cout<<arr[0]<<endl;


}