#include<bits/stdc++.h>
using namespace std;
void solve(int col, int &ans,int *left, int *ld,int *ud,vector<string>&board)
{
    if(col==8)
    {
        ans = ans+1;
    }
    for(int row =0 ;row<8;row++)
    {
        if(!left[row] && !ld[row+col] && !ud[7+col-row]&& board[row][col]!='*')
        {
            left[row]=1;
            ld[row+col]=1;
            ud[7-row+col]=1;
            solve(col+1,ans,left,ld,ud,board);
            left[row]=0;
            ld[row+col]=0;
            ud[7-row+col]=0;

        }
    }
}
int main()
{
    
    vector<string> board;
    for(int i = 0;i<8;i++)
    {
        string s;
        cin>>s;
        board.push_back(s);
    }
    int lowerDiagonal[15],upperDiagonal[15], left[8];
     memset(lowerDiagonal,0,sizeof(lowerDiagonal));
     memset(upperDiagonal,0,sizeof(upperDiagonal));
     memset(left,0,sizeof(left));

     int ans = 0;
     solve(0,ans,left,lowerDiagonal,upperDiagonal,board);
     cout<<ans<<endl;
}