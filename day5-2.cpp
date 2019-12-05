#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int n,k=-1,nr,i,a,b;
char c;
int v[10000];
int vect[10000];
string s[10000];
bitset<10000> fr;
int *param[10];
int solve(string s,int poz)
{
    int l=s.size()-1;

    int cod;
    if(s.size()>=2) cod=s[l]-'0'+(s[l-1]-'0')*10;
    else  cod=s[0]-'0';
    if(cod==0)
    cin>>cod;
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
        cout<<*param[1]<<" ";
        i+=2;
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
    else{
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
        else if(c=='-'){
            semn=-1;
        }
    }
    v[++k]=nr;
    for(i=0; i<=k;)
    {
        if(v[i]==99)
            break;
            else
        {
           /// cout<<i<<endl;
           if( solve(s[i],i)==-1)
            return 0;
        }
    }

}
