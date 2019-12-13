#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
long long n,k=-1,nr,i,a,b;
char c;
long long v[100000];
deque<int> inputs;
long long vect[100000];
string s[100000];
int fr[20];
long long *param[10];
long long baza;
long long nrday13;
map< pair<long long,long long> ,long long> block;
long long solve(string s,long long poz)
{
    long long l=s.size()-1;

    long long cod;

    if(s.size()>=2) cod=s[l]-'0'+(s[l-1]-'0')*10;
    else  cod=s[0]-'0';
    if(cod==0)
    cin>>cod;
    for(int i=0;i<=10;i++)
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
        else {
            param[index]=&v[v[poz+index]+baza];
        }
    }
    if(cod==99){
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
    else if(cod==2){
        *param[3]=*param[1]* *param[2];
        i+=4;
    }
    else if(cod==3){
        cin>>*param[1];
        i+=2;
    }
    else if(cod==4){
        inputs.push_back(*param[1]);
       // cout<<*param[1]<<" ";
        i+=2;
        int x,y;
        if(inputs.size()%3!=0)
           return 0;
            x=inputs.front();
        inputs.pop_front();
            y=inputs.front();
         inputs.pop_front();
         if(inputs.front()==2){
          //  block.push_back({x,y});
            nrday13++;
         }
         else if(inputs.front()>4){
            cout<<inputs.front();
         }

          inputs.pop_front();
    }
    else if(cod==5){
        if(*param[1]==0){
           i+=3;
        }
        else
        i=*param[2];
    }
    else if(cod==6){
         if(*param[1]!=0){
           i+=3;
        }
        else
        i=*param[2];
    }
    else if(cod==7){
        if(*param[1]<*param[2]){
            *param[3]=1;
        }
        else *param[3]=0;
        i+=4;
    }
    else if(cod==8){
        if(*param[1]==*param[2]){
            *param[3]=1;
        }
        else *param[3]=0;
        i+=4;
    }
    else if(cod==9){
        baza+=*param[1];
        i+=2;
    }
    else{
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
        else if(c=='-'){
            semn=-1;
        }
    }
    v[++k]=nr;
    for(i=0; i<=k;)
    {
           /// cout<<i<<endl;
           if( solve(s[i],i)==-1)
            break;
    }
      cout<<nrday13<<endl;
}
