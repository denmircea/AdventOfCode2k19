#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
int maxx,i,nr0,nr1,nr2,sol,nr;
int main()
{
    char c;
    maxx=INT_MAX;
    while(fin>>c)
    {
        nr++;
        if(nr%150==1){
            nr1=0;
            nr2=0;
            nr0=0;
        }
        if(c=='0')
            nr0++;
        if(c=='1')
            nr1++;
        if(c=='2')
            nr2++;
        if(nr%150==0){
            if(maxx>=nr0){
                sol=nr1*nr2;
                maxx=nr0;
            }
        }
    }
cout<<sol;

}
