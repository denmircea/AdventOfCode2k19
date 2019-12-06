#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// < ------------------------->
char s[200];
map< string,int> m;
bitset <100000> fr;
int n,i,result;
vector<int> L[100000];
int sum[100001];
void dfs(int nod,int tata){
sum[nod]=sum[tata]+1;
result+=sum[nod];
for(int i=0;i<L[nod].size();i++){
    int vecin=L[nod][i];
    if(vecin!=tata){
        dfs(vecin,nod);
    }
}
}
int main()
{
while(fin.getline(s,100)){
    string a;
    a+=s[0];
    a+=s[1];
    a+=s[2];
    string b;
    b+=s[4]; b+= s[5]; b+=s[6];
    if(m[a]==0){
        m[a]=++n;
    }
    if(m[b]==0){
        m[b]=++n;
    }
    L[m[a]].push_back(m[b]);
    fr[m[b]]=1;
  //  if(b[0]=='Y'&&b[1]=='0')
    if(s[3]!=')')
        cout<<1;
}
sum[0]=-1;
for(i=1;i<=n;i++){
    if(fr[i]==0){
        dfs(i,0);
    }
}
cout<<result;
}
