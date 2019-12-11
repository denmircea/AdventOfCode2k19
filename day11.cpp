#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[100000];

long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
map<pair<int,int>,int > visited,color;
deque<int> inputs;
int lin[]= {-1,0,1,0};
int col[]= {0,1,0,-1};
int X=0,Y=0,dir=0;
int vizitate; /// cate a vizitat
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
        //cout<<color[{X,Y}];
        *param[1]=color[{X,Y}];
        i+=2;
    }
    else if(cod==4)
    {
//cout<<*param[1]<<" ";
        inputs.push_back(*param[1]);
        //if(inputs.size()%2==0)
         //   cout<<endl;
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
    /// dupa ce executa opul

    while(inputs.size()>=2)
    {
       // cout<<inputs.size()<<endl;
        color[ {X,Y}]=inputs.front();
        inputs.pop_front();
        if( visited[ {X,Y}]==0)
            vizitate++;
        visited[ {X,Y}]=1;
        int nextDir=inputs.front();
        inputs.pop_front();
        if(nextDir==0)
            dir+=3;
        if(nextDir==1)
            dir++;
        dir%=4;
        X+=lin[dir];
        Y+=col[dir];
      //  cout<<X<<" "<<Y<<endl;
    }


}
int main()
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
    //color[{0,0}]=1;
    /// randul de mai sus comentat pentru partea 1
    for(i=0; i<=k;)
    {
        /// cout<<i<<endl;
        if( solve(s[i],i)==-1)
            break;
    }
    fout<<"Part1:";
    fout<<vizitate;
    fout<<endl<<"Part2:\n";
    for(int i=-1;i<=50;i++,fout<<endl)
        for(int j=-1;j<=50;j++)
    if(color[{i,j}]==1)
        fout<<"#";
    else fout<<" ";

}
