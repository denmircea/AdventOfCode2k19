#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[100000];

long long vect[100000];
string s[100000];
deque <int> inputs;
int fr[20];
int lin[]= {0,-1,1,0,0};
int col[]= {0,0,0,-1,1};
long long *param[10];
long long baza,input,input2;
long long actx,acty;
map< pair<int,int>, char> m;;
bool bfs(int x,int y,int dist)
{
    deque <pair<int,int> > q;
    q.push_back({x,y});
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
       // cout<<x<<" "<<y<<endl;
        q.pop_front();
        if(x==1&&y==0)
            cout<<"distanta:"<< dist;
        for(int d=1; d<=4; d++)
        {
            if(m[ {x+lin[d],y+col[d]}]=='_')
            {

                q.push_back({x+lin[d],y+col[d]});
                dist++;
                break;
            }
        }
        m[ {x,y}]='#';
    }

}
long long solve(string s,long long poz)
{
    long long l=s.size()-1;

    long long cod;

    if(s.size()>=2)
        cod=s[l]-'0'+(s[l-1]-'0')*10;
    else
        cod=s[0]-'0';
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
        if(inputs.size()==0)
        {
            cout<<"nu are input";
        }
        *param[1]=inputs.front();
        inputs.pop_front();
        input2=*param[1];
        i+=2;
    }
    else if(cod==4)
    {
        cout<<*param[1]<<" ";
        if(*param[1]!=0)
        {
            actx+=lin[input2];
            acty+=col[input2];
        }
        cout<<actx<<" "<<acty<<endl;
        i+=2;
        return *param[1];
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
    else
    {
    }
    return -6;
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
    /// primul pas il duc sus stanga
    int anterior=1000;
    for(i=0; i<=k;)
    {
        for(input=4; input>=1; input--)
        {
            if(anterior+input==3||anterior+input==7)
                continue;
            if( m[ {actx+lin[input],acty+col[input]}]=='#')
                continue;
            inputs.push_back(input);
            int x=solve(s[i],i);
            while(x<-1)
                x=solve(s[i],i);
            cout<<x<<endl;
            // cout<<i<<endl;
            if(x==-1)
                return 0;
            if(x==2)
            {
                for(int x=-20; x<=20; x++,cout<<endl)
                    for(int y=-20; y<=20; y++)
                        if(actx==x&&acty==y)
                            cout<<'$';
                        else if(m[ {x,y}])
                            cout<<m[ {x,y}];
                        else
                            cout<<" ";

                bfs(actx,acty,0);
                return 0;
            }
            if(x==1)
            {
                m[ {actx,acty}]='_';
                anterior=input;
                break;
            }
            if(x==0)
            {
                m[ {actx+lin[input],acty+col[input]}]='#';
            }

        }
        if(input==0)
        {
            input=3;
            inputs.push_back(input);
            m[ {actx,acty}]='#';
            int x=solve(s[i],i);
            while(x<-1)
                x=solve(s[i],i);
        }
    }

}
