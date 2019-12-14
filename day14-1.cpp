#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
vector< pair<long long,long long> > L[100000];
long long nrelem,i;
map<string,long long> m;
pair<long long,long long> v[10000];
string s;
long long nr,k,sum;
long long reactie[100000],intra[10000];
long long nivel[10000],nev[10000],fr[10000];
long long a[1000];
long long c[10000][10000];
deque<long long> output;
bitset <100000> FR;
bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    return nivel[a.first]>nivel[b.first];
}
detNivel(long long nod)
{
    for(long long i=0; i<L[nod].size(); i++)
    {
        long long vecin=L[nod][i].first;
        nivel[vecin]=max(nivel[vecin],nivel[nod]+1);
        detNivel(vecin);
    }
}
void dfs(long long nod,long long nevoie)
{
    if(FR[nod]==1)
        return;
    FR[nod]=1;
    if(nod==1){
       // cout<<endl<<nev[1];
        return;
    }
     if(nev[nod]<reactie[nod])
                    nev[nod]=reactie[nod];
        long long nr=1;
        if(nev[nod]>reactie[nod]){
            while(reactie[nod]*nr<nev[nod])
                nr++;
        }
        nev[nod]=reactie[nod]*nr;
        cout<<nr<<endl;
        cout<<nod<<" "<<nev[nod]<<"\n";
    for(long long i=0; i<L[nod].size(); i++)
    {
        long long vecin=L[nod][i].first;
        long long cost=L[nod][i].second;
        if(vecin==1){
            sum+=cost*nr;
        }
        nev[vecin]+=cost*nr;
        fr[vecin]++;
        if(fr[vecin]==intra[vecin]){
        dfs(vecin,0);
        }
    }
}
void muchie (long long cost,long long x,long long y)
{
    L[x].push_back({y,cost});
    intra[y]++;
    //cout<<x<<" "<<y<<endl;
    if(y==1){
        output.push_back(x);
    }
    c[x][y]=cost;
}
int main()
{
    string s="ORE";
    m[s]=1;
    s="FUEL";
    m[s]=2;
    nrelem=2;
    while(fin>>nr)
    {
        k=0;
        while(1)
        {
            if(k!=0)
                fin>>nr;
            if(nr==-1)
                break;
            fin>>s;

            if(m[s]==0)
                m[s]=++nrelem;
            v[++k]= {nr,m[s]};
        }
        fin>>nr>>s;
        if(m[s]==0)
            m[s]=++nrelem;
        reactie[m[s]]=nr;
        for(long long j=1;j<=k;j++){
            muchie(v[j].first,m[s],v[j].second);
        }
    }
    nivel[1]=1;
    detNivel(2);
    for(long long i=1;i<=nrelem;i++) a[i]=i;
    for(long long i=1;i<=nrelem;i++)
        for(long long j=i+1;j<=nrelem;j++)
            if(nivel[a[i]]>nivel[a[j]])
            swap(a[i],a[j]);
   // for(long long i=1;i<=)
   nev[2]=1;
    dfs(2,1);
   // cout<<nev[3]<<" "<<nev[4]<<" ";

    sum=0;
    while(output.size()>0){
        long long nod=output.front();
    cout<<nod<<" => "<<nev[nod]<<endl;
        long long nr=1;
        while(reactie[nod]*nr<nev[nod])
            nr++;
        sum+=nr*c[nod][1];
        cout<<nr*c[nod][1]<<endl;
        output.pop_front();
    }
       cout<<endl<<sum;
}
