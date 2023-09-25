#include<bits/stdc++.h>
using namespace std;
void find(string s, int index, set<string>&ans)
{
    if(index>=s.size())
    {
        ans.insert(s);
    }
    for(int i =index;i<s.size();i++)
    {
        swap(s[i],s[index]);
        find(s,index+1,ans);
        swap(s[i],s[index]);
    }
}
int main()
{
    string s;
    cin>>s;
    set<string> ans;

    find(s,0,ans);
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        cout<<it<<endl;
    }

}