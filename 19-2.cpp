#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[500],V[500],nrsol;
bool output;
long long vect[10000000],vect2[100000000];
string s[500];
int fr[20];
long long *param[10];
long long baza;

long long solve(string s,long long poz)
{
    long long l=s.size()-1;

    long long cod;

    if(s.size()>=2)
        cod=s[l]-'0'+(s[l-1]-'0')*10;
    else
        cod=s[0]-'0';
    if(cod==0)
        cin>>cod;
    for(int i=0; i<=10; i++)
        fr[i]=0;
    l-=2;
    long long parametrii=0;
    while(l>=0)
    {
        fr[++parametrii]=s[l]-'0';
        l--;
    }
    for(long long index=1; index<=4; index++)
    {
        if(fr[index]==0)
        {
            param[index]=&v[v[poz+index]];
        }
        else if(fr[index]==1)
        {
            param[index]=&v[poz+index];
            // cout<<index<<" "<<poz<<" "<<*param[index];
        }
        else
        {
            param[index]=&v[v[poz+index]+baza];
        }
    }
    if(cod==99)
    {
        cout<<"finish";
        return -1;
    }
    if(cod==1)
    {
        //  cout<<param[1]<<" "<<param[2]<<" "<<v[poz+3]<<endl;
        *param[3]=*param[1]+*param[2];
        //  cout<<v[4];
        i+=4;
    }
    else if(cod==2)
    {
        *param[3]=*param[1]* *param[2];
        i+=4;
    }
    else if(cod==3)
    {
        nr++;
        if(nr==1)
        {
            *param[1]=a;
            // cout<<"a"<<a<<" " ;
        }
        else if(nr==2)
        {
            //  cout<<"b"<<b<<" ";
            *param[1]=b;
        }
        else
        {
            cout<<"no inp;";
            return -1;
        }
        i+=2;
    }
    else if(cod==4)
    {
        output=true;
        nrsol+=*param[1];
        if(*param[1]==1)
        fout<<*param[1];
        else fout<<" ";
        i+=2;
        return -1;
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
    else if(cod==9)
    {
        baza+=*param[1];
        i+=2;
    }
}
int main()
{
//    long long semn=1;
//    while(fin>>c)
//    {
//        if(c==',')
//        {
//            V[++k]=nr*semn;
//            semn=1;
//            nr=0;
//        }
//        else if(c>='0'&&c<='9')
//        {
//            s[k+1]+=c;
//            nr*=10LL;
//            nr+=c-'0';
//        }
//        else if(c=='-'){
//            semn=-1;
//        }
//    }
//    V[++k]=nr;

        for( a=600+19; a<600+19+100; a++,fout<<endl)
        {
            nrsol=0;
            for( b=900+30+10+8; b<900+30+10+8+100; b++)
            {
                nr=0;
                k=-1;
                fin.close();
                fin.open("test.in");
                while(fin>>v[++k]);
                k=-1;
                fin.close();
                fin.open("test.in");

                while(fin>>s[++k]);
                output=false;
                for(i=0; i<=k;)
                {
                    if( solve(s[i],i)==-1)
                        break;
                }
            }
        }
}
