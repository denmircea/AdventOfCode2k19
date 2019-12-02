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
    memcpy(vect,v,sizeof(v));
    bool ok=0;
    for(int nr1=0;nr1<=99;nr1++)
    for(int nr2=0;nr2<=99&&ok==0;nr2++){
        memcpy(v,vect,sizeof(v));
    v[1]=nr1;
    v[2]=nr2;
    for(i=0; i<=k;)
    {
      //  cout<<i;
        if(v[i]==99)
            break;
        else if(v[i]==1)
        {
            a=v[v[i+1]];
            b=v[v[i+2]];
            v[v[i+3]]=a+b;
            if(a+b==19690720){
                cout<<nr1<<" "<<nr2;
                ok=1;
            }
            i+=4;
        }
        else if(v[i]==2)
        {
            a=v[v[i+1]];
            b=v[v[i+2]];
            v[v[i+3]]=a*b;
            if(a*b==19690720){
                cout<<nr1<<" "<<nr2;
                ok=1;
            }
            i+=4;
        }
    }
    }
    //cout<<v[0];
}
