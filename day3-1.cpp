#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// <---------------------------------------------------->
map< pair<int,int>,int> a,b;
set< pair<int,int> > s;
int x,y,nr,i;
char cifra,litera;
int main()
{
    a[{x,y}]++;
    while(fin>>litera)
    {
        nr=0;
        while(fin>>cifra)
        {
            if(cifra>='0'&&cifra<='9')
            {
                nr*=10;
                nr+=cifra-'0';
            }
            else
                break;
        }
        cout<<nr<<endl;
        if(litera=='U')
        {
            for(i=1; i<=nr; i++)
            {
                a[ {x-i,y}]=1;
            }
            x-=nr;
        }
        if(litera=='R')
        {
            for(i=1; i<=nr; i++)
            {
                a[ {x,y+i}]=1;
            }
            y+=nr;
        }
        if(litera=='D')
        {
            for(i=1; i<=nr; i++)
            {
                a[{x+i,y}]=1;
            }

            x+=nr;
        }
        if(litera=='L')
        {
            for(i=1; i<=nr; i++)
            {
                a[ {x,y-i}]=1;
            }
            y-=nr;
        }

    }
    fin.close();
    x=0,y=0;
    ifstream fin2("test2.in");
    while(fin2>>litera)
    {
        nr=0;
        while(fin2>>cifra)
        {
            if(cifra>='0'&&cifra<='9')
            {
                nr*=10;
                nr+=cifra-'0';
            }
            else
                break;
        }
        cout<<nr<<endl;
        if(litera=='U')
        {
            for(i=1; i<=nr; i++)
            {
                b[ {x-i,y}]++;
                if(b[ {x-i,y}]>=1&&a[ {x-i,y}]>=1)
                {
                    s.insert({x-i,y});
                }
            }
            x-=nr;
        }
        if(litera=='R')
        {
            for(i=1; i<=nr; i++)
            {
                b[ {x,y+i}]++;
                if(b[ {x,y+i}]>=1&&a[ {x,y+i}]>=1)
                {
                    s.insert({x,y+i});
                }
            }
            y+=nr;
        }
        if(litera=='D')
        {
            for(i=1; i<=nr; i++)
            {
                b[{x+i,y}]++;
                if(b[{x+i,y}]>=1&&a[{x+i,y}]>=1)
                {
                    s.insert({x+i,y});
                }
            }

            x+=nr;
        }
        if(litera=='L')
        {
            for(i=1; i<=nr; i++)
            {
                b[ {x,y-i}]++;
                if(b[ {x,y-i}]>=1&&a[ {x,y-i}]>=1)
                {
                    s.insert({x,y-i});
                }
            }
            y-=nr;
        }

    }

    int sol=INT_MAX;
    for(auto it=s.begin();it!=s.end();it++){
        int a,b;
        a=it->first;
        b=it->second;
        cout<<a<<" "<<b<<endl;
        sol=min(sol,abs(a)+abs(b));
    }
    cout<<sol;
}
