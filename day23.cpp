#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b,citiri,nrsol,j,actx,acty,sentx,senty;
char c;
long long *v;
string *s;
long long vmasina[60][100000];
string smasina[60][100000];
long long imasina[100];
deque<long long> inputs[300],outputs[300];
long long fr[20];
long long *param[10];
long long baza;
void citire(long long vect[],string sa[])
{
    k=-1;
    fin.close();
    fin.open("test.in");
    long long semn=1;
    while(fin>>c)
    {
        if(c==',')
        {
            vect[++k]=nr*semn;
            semn=1;
            nr=0;
        }
        else if(c>='0'&&c<='9')
        {

            sa[k+1]+=c;
            nr*=10LL;
            nr+=c-'0';
        }
        else if(c=='-')
        {
            semn=-1;
        }
    }
    vect[++k]=nr;
}
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
    for(long long i=0; i<=10; i++)
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
            param[index]=&v[v[poz+index]];
        else if(fr[index]==1)
            param[index]=&v[poz+index];
        else
            param[index]=&v[v[poz+index]+baza];
    }
    {
        /// colapsabil
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
        if(cod==2)
        {
            *param[3]=*param[1]* *param[2];
            i+=4;
        }
        if(cod==5)
        {
            if(*param[1]==0)
            {
                i+=3;
            }
            else
                i=*param[2];
        }
        if(cod==6)
        {
            if(*param[1]!=0)
            {
                i+=3;
            }
            else
                i=*param[2];
        }
        if(cod==7)
        {
            if(*param[1]<*param[2])
            {
                *param[3]=1;
            }
            else *param[3]=0;
            i+=4;
        }
        if(cod==8)
        {
            if(*param[1]==*param[2])
            {
                *param[3]=1;
            }
            else *param[3]=0;
            i+=4;
        }
        if(cod==9)
        {
            baza+=*param[1];
            i+=2;
        }
    } /// colapsat
    /**
     *
     *
     *
     *
     *
     */

    if(cod==3)
    {
        // cin>>*param[1];
        if(inputs[j].size()==0)
        {
            return -1;
        }
        *param[1]=inputs[j].front();
        inputs[j].pop_front();
        i+=2;
    }
    else if(cod==4)
    {
         // cout<<*param[1]<<" ";

        outputs[j].push_back(*param[1]);
        i+=2;
    }
    //cout<<cod<<endl;
}
int main()
{
    /// citire() reseteaza vectorul v
    for(j=49; j>=0; j--)
    {
        inputs[j].push_back(j);
        inputs[j].push_back(-1);
    }
    for(j=0; j<=49; j++)
    {
        imasina[j]=0;
        citire(vmasina[j],smasina[j]);
    }
    while(1)
    {
         for(j=49; j>=0; j--)
        {
            v=vmasina[j];
            s=smasina[j];
            for(i=imasina[j]; i<=k;)
                if( solve(s[i],i)==-1)
                    break;
            imasina[j]=i;
        }
         for(j=49; j>=0; j--)
        {
            while(!outputs[j].empty())
            {
                long long id,x,y;
                id=outputs[j].front();
                outputs[j].pop_front();
                x=outputs[j].front();
                outputs[j].pop_front();
                y=outputs[j].front();
                outputs[j].pop_front();
                 inputs[id].push_back(x);
                inputs[id].push_back(y);
               // cout<<id<<" "<<x<<" "<<y<<endl;
                if (id == 255)
                {
                    if(inputs[255].size()==2)
                    cout<<inputs[255][1]<<" part1\n";
                   actx=x;
                   acty=y;
                }
            }
        }
         for(j=49; j>=0; j--){
            if(inputs[j].empty())
                inputs[j].push_back(-1);
        }
        for(j=49; j>=0; j--)
        if(inputs[j].size()!=1){
            break;
        }
        if(j==-1){
            /// idle
            if(sentx==actx&&senty==acty){
                    //cout<<sentx<<" "<<senty<<endl;
                cout<<senty<<" part2\n";
            return 0;
            }
            inputs[0].pop_front();
            inputs[0].push_back(actx);
            inputs[0].push_back(acty);

            sentx=actx;
            senty=acty;
        }
    }

}
