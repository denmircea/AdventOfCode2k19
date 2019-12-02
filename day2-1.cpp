#include <bits/stdc++.h>
using namespace std;
ifstream fin("text.in");
ofstream fout("text.out");
int n,k=-1,nr,i,a,b;
char c;
int v[10000];
int vect[10000];
int main()
{
    while(fin>>c)
    {
        if(c==',')
        {
            v[++k]=nr;
            nr=0;
        }
        else if(c>='0'&&c<='9')
        {
            nr*=10;
            nr+=c-'0';
        }
    }
    v[++k]=nr;
    v[1]=12;
    v[2]=2;
    for(i=0; i<=k;)
    {
        if(v[i]==99)
            break;
        else if(v[i]==1)
        {
            a=v[v[i+1]];
            b=v[v[i+2]];
            v[v[i+3]]=a+b;
            i+=4;
        }
        else if(v[i]==2)
        {
            a=v[v[i+1]];
            b=v[v[i+2]];
            v[v[i+3]]=a*b;
            i+=4;
        }
    }
    
    cout<<v[0];
}
