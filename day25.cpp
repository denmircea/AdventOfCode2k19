#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[100000],output;
deque<long long> inputs,outputs;
long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
long long baza;
 void north(string str){
    for(auto it:str)
        inputs.push_back(it);
    inputs.push_back(10);
    }
void drop(string str1,string str){
    for(auto it:str1)
        inputs.push_back(it);
    inputs.push_back(' ');
    for(auto it:str){
        if(it=='_')
            inputs.push_back(' ');
        else inputs.push_back(it);
    }
    inputs.push_back(10);
}
void citire()
{
    long long semn=1;
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
            param[index]=&v[v[poz+index]];
        else if(fr[index]==1)
            param[index]=&v[poz+index];
        else
            param[index]=&v[v[poz+index]+baza];
    }
    { /// colapsabil
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
        if(inputs.empty()){
        string dir;
        cin>>dir;
        if(dir=="drop"||dir=="take"){
            string dir2;
            cin>>dir2;
            drop(dir,dir2);
        }else {
            north(dir);
        }
        }
     //   cin>>*param[1];
     //cout<<inputs.size();
        *param[1]=inputs.front();
        inputs.pop_front();
        i+=2;
    }
    else if(cod==4)
    {
        cout<<(char)*param[1];
        output=*param[1];
        i+=2;
    }
   return 0;
}

int main()
{
    citire();
    for(i=0; i<=k;)
    {
        if( solve(s[i],i)==-1)
            break;
    }
    cout<<endl;
    cout<<output;
}
