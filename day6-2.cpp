#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// < ------------------------->
char s[200];
map< string,int> m;
bitset <100000> fr;
int n,i,result,start,finish;
vector<int> L[100000];
int sum[100001];
void dfs(int nod,int tata)
{
    sum[nod]=sum[tata]+1;
    result+=sum[nod];
    for(int i=0; i<L[nod].size(); i++)
    {
        int vecin=L[nod][i];
        if(vecin!=tata)
        {
            dfs(vecin,nod);
        }
    }
}
int bfs(int nod)
{
    deque<int> q;
    q.push_back(nod);
    bitset<100000> IQ;
    IQ[nod]=1;
    fr[nod]=1;
    cout<<start<<" "<<finish<<endl;
    while(!q.empty())
    {
        nod=q.front();
        q.pop_front();
        //cout<<nod<<" ";
        for(int i=0; i<L[nod].size(); i++)
        {
            int vecin=L[nod][i];
           // cout<<vecin<<" ";
            if(fr[vecin]==0)
            {
                fr[vecin]=1;
                sum[vecin]=sum[nod]+1;
                if(vecin==finish)
                {
                    return sum[vecin];
                }
                q.push_back(vecin);
            }
        }
    }

}
int main()
{
    while(fin.getline(s,100))
    {
        string a;
        a+=s[0];
        a+=s[1];
        a+=s[2];
        string b;
        b+=s[4];
        b+= s[5];
        b+=s[6];
        if(m[a]==0)
        {
            m[a]=++n;
        }
        if(m[b]==0)
        {
            m[b]=++n;
        }
        L[m[a]].push_back(m[b]);
        L[m[b]].push_back(m[a]);
        if(b[0]=='Y'&&b[1]=='O'&&b[2]=='U')
        {
            start=m[b];
        }
        if(b[0]=='S'&&b[1]=='A'&&b[2]=='N')
        {
            finish=m[a];
        }
    }
    sum[0]=-1;
//for(i=1;i<=n;i++){
//    if(fr[i]==0){
//        dfs(i,0);
//    }
//}
//cout<<start<<" "<<finish;
    cout<<bfs(start);
}
