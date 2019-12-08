#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
int maxx,i,nr0,nr1,nr2,sol,nr;
int main()
{
    char c;
    maxx=INT_MAX;
    char v[160];
    for(int i=1; i<160; i++)
        v[i]='2';
    while(fin>>c)
    {
        nr++;
        if(nr%150==1)
        {
            nr0=0;
            nr1=0;
            nr2=0;
            nr=1;
        }
        if(c=='0'&&v[nr]=='2')
            v[nr]='0';
        if(c=='1'&&v[nr]=='2')
            v[nr]='1';
    }
    for(i=1;i<=150;i++){
        if(i%25==1)
        cout<<endl;
    if(v[i]=='0')
    cout<<(char)254;
    else if(v[i]=='1')
        cout<<(char)206;
    else cout<<' ';
    }
}
