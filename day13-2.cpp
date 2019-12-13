#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[100000];
deque<int> outputs,inputs;
long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
long long baza,paddle,ball,maxx;
long long nrday13;
map< pair<long long,long long>,long long> block;
long long solve(string s,long long poz)
{
    long long l=s.size()-1;
    long long cod;
    if(s.size()>=2) cod=s[l]-'0'+(s[l-1]-'0')*10;
    else  cod=s[0]-'0';
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
        }
        else
        {
            param[index]=&v[v[poz+index]+baza];
        }
    }
    if(cod==99)
    {
        //cout<<"finish";
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
        if(inputs.size()==0)
            return -2;
        *param[1]=inputs.front();
        inputs.pop_front();
        i+=2;
    }
    else if(cod==4)
    {
        outputs.push_back(*param[1]);
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
    else if(cod==9)
    {
        baza+=*param[1];
        i+=2;
    }
    return 0;
}
int main()
{
    long long semn=1;
    inputs.push_back(0);
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
            nr*=10LL;
            nr+=c-'0';
        }
        else if(c=='-')
        {
            semn=-1;
        }
    }
    v[++k]=nr;
    for(i=0; i<=k;)
    {
        while(solve(s[i],i)==0);
        long long x,y,id;
        while(outputs.size()!=0)
        {
            x=outputs.front();
                outputs.pop_front();
            y=outputs.front();
                outputs.pop_front();
            id=outputs.front();
                outputs.pop_front();
            if(id==3)
            {
                paddle=x;
            }
            else if(id==4)
            {
                ball=x;
            }
            if (x == -1 && y == 0){
                cout << id << '\n';
            maxx=max(id,maxx);
            }
        }
        if(paddle<ball)
            inputs.push_back(1);
        else if(paddle>ball)
            inputs.push_back(-1);
        else inputs.push_back(0);
    }

}
