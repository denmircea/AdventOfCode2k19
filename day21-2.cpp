#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b,citiri,nrsol;
char c;
long long v[100000];
long long vect[100000000];
string s[100000];
deque<long long> inputs,outputs;
int fr[20];
long long *param[10];
long long baza;
void citire()
{
    citiri++;
    k=-1;
    fin.close();
    fin.open("test.in");
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
            if(citiri==1)
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
        if(inputs.size()==0)
        {
            cout<<"no input";
            return -2;
        }
        *param[1]=inputs.front();
        inputs.pop_front();
        i+=2;
    }
    else if(cod==4)
    {
        cout<<(char)*param[1]<<" ";
         outputs.push_back(*param[1]);
        i+=2;
    }
}
void NOT(char a,char b){
 inputs.push_back('N');
    inputs.push_back('O');
    inputs.push_back('T');
    inputs.push_back(' ');
    inputs.push_back(a);
    inputs.push_back(' ');
    inputs.push_back(b);
    inputs.push_back(10);

}
void AND(char a,char b){
 inputs.push_back('A');
    inputs.push_back('N');
    inputs.push_back('D');
    inputs.push_back(' ');
    inputs.push_back(a);
    inputs.push_back(' ');
    inputs.push_back(b);
    inputs.push_back(10);

}
void OR(char a,char b){
    inputs.push_back('O');
    inputs.push_back('R');
    inputs.push_back(' ');
    inputs.push_back(a);
    inputs.push_back(' ');
    inputs.push_back(b);
    inputs.push_back(10);
}
int main()
{
    /// citire() reseteaza vectorul v
    citire();
    //OR('D','J');
//    NOT('A','T');
//    OR('T','J');
//    NOT('B','T');
//    OR('T','J');
//    NOT('C','T');
//    OR('T','J');
//    NOT('J','T');
//    OR('D','T');
//    AND('T','J');

NOT('A','T');
OR('T','J');
NOT('B','T');
OR('T','J');
NOT('C','T');
OR('T','J');
AND('D','J');    /// daca a sau b sau c sunt 0
OR('J','T');
AND('H','T');
OR('E','T');
AND('T','J');  /// si d=1 si e=1||h==1
    inputs.push_back('R');
    inputs.push_back('U');
    inputs.push_back('N');
    inputs.push_back(10);


    for(i=0; i<=k;)
    {
        if( solve(s[i],i)==-1)
            break;
    }
    cout<<endl<<outputs.back();
}
