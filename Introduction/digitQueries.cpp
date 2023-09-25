#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll len[18];
void cal()
{
    for(int i =1;i<=17;i++)
    {
        len[i] = (9*i*pow(10,i-1));
    }
}

int main()
{
    memset(len,0,sizeof(len));
    cal();
    ll q;
    cin>>q;
    while (q--)
    {
        ll k;
        cin>>k;
        ll sum = 0, lenOfNumber=0;
       for(int i = 0;i<18;i++)
       {

        sum+=len[i];
        if(sum<=k)
        {
            lenOfNumber = i+1;
        }
        else
        {
            break;
        }
       }
       sum-=len[lenOfNumber];
       ll diff = k-sum;
       ll startNumber  = pow(10,lenOfNumber-1);
       ll distanceFromStart = diff/lenOfNumber;
       ll actual = startNumber+distanceFromStart-1; 
       ll reminder = diff%lenOfNumber;
       if(reminder==0)
       {
        cout<<actual%10<<endl;
       }
       else
       {
        actual++;
        reminder = lenOfNumber-reminder;
        while(reminder--)
        {
            actual/=10;
        }
        cout<<actual%10<<endl;

       }


    }
    
}