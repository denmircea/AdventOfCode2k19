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
int x,y,nr,i,pasi;
char cifra,litera;
int main()
{
    pasi=0;
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
        if(litera=='U')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(a[{x-i,y}]==0)
                    a[{x-i,y}]=pasi;
                 else{
                   a[{x-i,y}]=min(a[{x-i,y}],pasi);
                 }

            }
            x-=nr;
        }
        if(litera=='R')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(a[{x,y+i}]==0)
                    a[{x,y+i}]=pasi;
                 else{
                   a[{x,y+i}]=min(a[{x,y+i}],pasi);
                 }

            }
            y+=nr;
        }
        if(litera=='D')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(a[{x+i,y}]==0)
                    a[{x+i,y}]=pasi;
                 else{
                   a[{x+i,y}]=min(a[{x-i,y}],pasi);
                 }

            }

            x+=nr;
        }
        if(litera=='L')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(a[{x,y-i}]==0)
                    a[{x,y-i}]=pasi;
                 else{
                   a[{x,y-i}]=min(a[{x,y-i}],pasi);
                 }

            }
            y-=nr;
        }

    }
    fin.close();
    x=0,y=0;
    pasi=0;
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
                pasi++;
                if(b[{x-i,y}]==0)
                    b[{x-i,y}]=pasi;
                 else{
                   b[{x-i,y}]=min(b[{x-i,y}],pasi);
                 }
                  if(b[ {x-i,y}]>=1&&a[ {x-i,y}]>=1)
                {
                    s.insert({a[ {x-i,y}],b[ {x-i,y}]});
                }

            }
            x-=nr;
        }
        if(litera=='R')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(b[{x,y+i}]==0)
                    b[{x,y+i}]=pasi;
                 else{
                   b[{x,y+i}]=min(b[{x,y+i}],pasi);
                 }
                  if(b[ {x,y+i}]>=1&&a[ {x,y+i}]>=1)
                {
                    s.insert({a[ {x,y+i}],b[ {x,y+i}]});
                }

            }
            y+=nr;
        }
        if(litera=='D')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(b[{x+i,y}]==0)
                    b[{x+i,y}]=pasi;
                 else{
                   b[{x+i,y}]=min(b[{x-i,y}],pasi);
                 }
                  if(b[{x+i,y}]>=1&&a[{x+i,y}]>=1)
                {
                    s.insert({b[{x+i,y}],a[{x+i,y}]});
                }

            }

            x+=nr;
        }
        if(litera=='L')
        {
            for(i=1; i<=nr; i++)
            {
                pasi++;
                if(b[{x,y-i}]==0)
                    b[{x,y-i}]=pasi;
                 else{
                   b[{x,y-i}]=min(b[{x,y-i}],pasi);
                 }
                  if(b[ {x,y-i}]>=1&&a[ {x,y-i}]>=1)
                {
                    s.insert({b[ {x,y-i}],a[ {x,y-i}]});
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
        sol=min(sol,abs(a)+abs(b));
    }
    cout<<sol;
}
