#include <bits/stdc++.h>
#define dim 200010
using namespace std;
ifstream fin("lca.in");
ofstream fout("lca.out");
int prim[dim],E[dim],N[dim],k,nivel=1,n,m,i,x,lun,lungime,j,y;
short Log[dim];
vector <int> L[dim];
int rmq[18][dim],rmqrez[18][dim];
void dfs(int nod,int tata)
{
    prim[nod]=++k;
    E[k]=nod;
    N[k]=nivel;
    for(int i=0; i<L[nod].size(); i++)
    {
        if(L[nod][i]==tata)
            continue;
        nivel++;
        dfs(L[nod][i],nod);
        nivel--;
        E[++k]=nod;
        N[k]=nivel;
    }
}
void query(int x,int y)
{
    if(x>y)
        swap(x,y);
    int put=Log[y-x+1];
    if(rmq[put][x]<=rmq[put][y-(1<<put)+1])
    {
        fout<<rmqrez[put][x]<<"\n";
    }
    else
        fout<<rmqrez[put][y-(1<<put)+1]<<"\n";
}
int main()
{
    fin>>n>>m;
    for(i=2; i<=n; i++)
    {
        fin>>x;
        L[x].push_back(i);
        L[i].push_back(x);
    }
    dfs(1,0);
    /// fac rmq si rezultatul de la rmq
    for(i=1; i<=k; i++)
    {
        rmq[0][i]=N[i];
        rmqrez[0][i]=E[i];
    }

    for(lun=1; lun<=17; lun++)
    {
        lungime=(1<<lun);
        lungime/=2;
        for(j=1; j<=k; j++)
        {
            // rmq[lun][j]=min(rmq[lun-1][j],rmq[lun-1][j+lungime]);
            if(rmq[lun-1][j]<rmq[lun-1][j+lungime])
            {
                rmq[lun][j]=rmq[lun-1][j];
                rmqrez[lun][j]=rmqrez[lun-1][j];
            }
            else
            {
                rmq[lun][j]=rmq[lun-1][j+lungime];
                rmqrez[lun][j]=rmqrez[lun-1][j+lungime];
            }
        }
    }
    Log[1]=0;
    for(i=2; i<=k; i++)
        Log[i]=1+Log[i/2];
    for(i=1; i<=m; i++)
    {
        fin>>x>>y;
        //cout<<prim[x]<<" "<<prim[y]<<" --\n";
        query(prim[x],prim[y]);
    }
}
