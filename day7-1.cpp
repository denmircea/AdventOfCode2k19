#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int n,k=-1,nr,i,a,b;
char c;
int v[10000],toate;
int vect[10000],iesire,total,citite,iesireant,R;
int V[10000];
int bt[100];
string s[10000];
bitset<10000> fr;
int *param[10];
void copiere(int a[],int b[])
{
    for(int i=0; i<=k; i++)
    {
        a[i]=b[i];
    }
    return ;
}
int solve(string s,int poz);
int solutie()
{
    total=0;
    iesireant=0;
    iesire=0;
    for(toate=1; toate<=5; toate++)
    {
        copiere(v,V);
        citite=0;
        for(i=0; i<=k;)
        {
            if(v[i]==99)
                break;
            else
            {
                if( solve(s[i],i)==-1)
                    break;
            }
        }
      //  cout<<"iesirea totala: ";
   // cout<<iesireant<<" ";
    iesire=iesireant;
    }
   total=iesireant;
   return total;
}

void backtr(int pas)
{
    if(pas>5)
    {
        int x=solutie();
        R=max(R,x);
         return ;
    }
    for(int i=0; i<=4; i++)
    {
        bool ok=1;
        for(int j=1;j<pas;j++)
        if(bt[j]==i){
            ok=0;
            break;
        }
        if(ok==1){
        bt[pas]=i;
        backtr(pas+1);
        }
    }
}
int solve(string s,int poz)
{
    int l=s.size()-1;

    int cod;
    if(s.size()>=2)
        cod=s[l]-'0'+(s[l-1]-'0')*10;
    else
        cod=s[0]-'0';
    if(cod==0)
    {
       // cin>>cod;

    }
    fr.reset();
    l-=2;
    int parametrii=0;
    while(l>=0)
    {
        fr[++parametrii]=s[l]-'0';
        l--;
    }
    for(int index=1; index<=4; index++)
    {
        if(fr[index]==0)
        {
            param[index]=&v[v[poz+index]];
        }
        else
        {
            param[index]=&v[poz+index];
        }
    }
    if(cod==99)
    {
        cout<<"finish";
        return -1;
    }
    if(cod==1)
    {
        *param[3]=*param[1]+*param[2];
        i+=4;
    }
    else if(cod==2)
    {
        *param[3]=*param[1]* *param[2];
        i+=4;
    }
    else if(cod==3)
    {
        if(citite==0){
            citite++;
            *param[1]=bt[toate];
        }
        else {
            citite++;
            *param[1]=iesireant;
        }
        i+=2;
    }
    else if(cod==4)
    {
        iesireant=*param[1];
       // cout<<*param[1]<<" ";
        i+=2;
    }
    else if(cod==5)
    {
        if(*param[1]==0)
        {
            i+=3;
        }
        else
            i=*param[2];
    }
    else if(cod==6)
    {
        if(*param[1]!=0)
        {
            i+=3;
        }
        else
            i=*param[2];
    }
    else if(cod==7)
    {
        if(*param[1]<*param[2])
        {
            *param[3]=1;
        }
        else *param[3]=0;
        i+=4;
    }
    else if(cod==8)
    {
        if(*param[1]==*param[2])
        {
            *param[3]=1;
        }
        else *param[3]=0;
        i+=4;
    }
    else
    {
    }
}

int main()
{
    int semn=1;
    while(fin>>c)
    {
        if(c==',')
        {
            v[++k]=nr*semn;
            semn=1;
            nr=0;
        }
        else if(c>='0'&&c<='9')
        {
            s[k+1]+=c;
            nr*=10;
            nr+=c-'0';
        }
        else if(c=='-')
        {
            semn=-1;
        }
    }
    v[++k]=nr;
    copiere(V,v);
    backtr(1);
    cout<<endl;
    cout<<R;
}
