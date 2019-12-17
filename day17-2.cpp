#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b,pozx,pozy;
char c;
long long v[100000];

long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
long long baza;
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
          //  cout<<"finish";
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
        cin>>*param[1];
        i+=2;
    }
    else if(cod==4)
    {
       fout<<(char)*param[1];
        i+=2;
    }
}
int main()
{
    citire();
    for(i=0; i<=k;)
    {
        int ret=solve(s[i],i);
        if( ret==-1)
            break;
    }
        fout.close();
        fin.close();
    ifstream fin("test.out");
    string mat[1000];
    int sz=0;
    int sum=0;
    while(fin>>mat[sz++]);
    for(i=1;i<sz-1;i++){
        for(int j=1;j<mat[1].size();j++){
            if(
               j<mat[1].size()-1&&
                mat[i][j]=='#'
               &&mat[i-1][j]=='#'
               &&mat[i][j-1]=='#'
               &&mat[i+1][j]=='#'
               &&mat[i][j+1]=='#'){
                sum+=i*j;
               }
            if(mat[i][j]=='^'){
                pozx=i;
                pozy=j;
            }
        }
    }
    cout<<sum<<endl;
    i=pozx;
    int j=pozy;
    j--;
    cout<<i<<" "<<j<<endl;;
    int lin[]={-1,0,1,0};
    int col[]={0,1,0,-1};
   int dir=3+400; // L
   nr=1;
   cout<<endl;
        cout<<"L,";
    while(mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
        while(
              i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&
              (mat[i+lin[dir%4]][j+col[dir%4]]=='#')
              ){
            i=i+lin[dir%4];
            j=j+col[dir%4];
            nr++;
        }
        cout<<nr<<",";
//        cout<<mat[i-1][j-1]<<mat[i-1][j]<<mat[i-1][j+1]<<endl;
//        cout<<mat[i][j-1]<<mat[i][j]<<mat[i][j+1]<<endl;
//        cout<<mat[i+1][j-1]<<mat[i+1][j]<<mat[i+1][j+1]<<endl;
        dir++;
        if(i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
            cout<<"R,";
            nr=0;
            continue;
        }
        dir-=2;
        if(i+lin[dir%4]>=0&&j+col[dir%4]>=0&&i<sz&&j<mat[1].size()&&mat[i+lin[dir%4]][j+col[dir%4]]=='#'){
            cout<<"L,";
            nr=0;
            continue;
        }
    }
}
