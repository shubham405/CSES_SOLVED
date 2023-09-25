#include<bits/stdc++.h>
using namespace std;
#define ll long long
int vis[7][7];

void solve(ll &ans, ll row, ll col,string &s, ll index)
{
    //cout<<row<<" "<<col<<endl;
    
    if(row==6 && col==0)
    {
        if(index==48)
        {
            ans++;
        }
        return;
    }

    vis[row][col]=1;

        //up
    if((row==0 || row==6) && col>0 && col<6 && !vis[row][col+1] && !vis[row][col-1])
        {
            vis[row][col]=0;
            return;
        }
     
         if((col==6 || col==0)&& row && row<6 && !vis[row-1][col] && !vis[row+1][col])
        {
            vis[row][col]=0;
            return;
        }

        if(row>0 && row<6 && vis[row+1][col]&& vis[row-1][col]  && col>0 && col<6 && !vis[row][col-1] && !vis[row][col+1])
        {
            vis[row][col]=0;
            return;
        }
       

        if(col>0 && col<6 && vis[row][col+1]&& vis[row][col-1]  && col>0 && col<6 && !vis[row-1][col] && !vis[row+1][col])
        {
            vis[row][col]=0;
            return;
        }
    

        

        if(s[index]=='?'||s[index]=='U')
        {
             if(row-1>=0 && !vis[row-1][col])
                {
                    solve(ans,row-1,col,s,index+1);
                }
        }

    
       
        //down
        if(s[index]=='D'|| s[index]=='?')
        {
             if(row+1<7 && !vis[row+1][col])
                {
                    solve(ans,row+1,col,s,index+1);
                }
        }
       if(s[index]=='L'|| s[index]=='?')
        {
            if(col-1>=0 && !vis[row][col-1])
            {
                solve(ans,row,col-1,s,index+1);
            }
            
        }
        if(s[index]=='R'|| s[index]=='?')
        {
            if(col+1<7 && !vis[row][col+1])
            {
                solve(ans,row,col+1,s,index+1);
            }
        }
    
     vis[row][col]=0;

     return;
    

}
int main()
{
    string s;
    cin>>s;
    memset(vis,0,sizeof(vis));
    ll ans = 0;
    solve(ans,0,0,s,0);
    cout<<ans;
}