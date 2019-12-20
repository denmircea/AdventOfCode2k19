#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
string s[128];
map<string,int> mapa;
int n=-1,m,i,j,a[200][200],nretichete,start,finish,nivel,act;
int lin[]={0,-1,0,1};
int col[]={-1,0,1,0};
bitset<200>fr[200][200];
long long nextAdancime(long long x,long long y)
{
    if(a[x][y]==start||a[x][y]==finish)
        return 0;
    if(x>=5&&x<=100&&y>=5&&y<=100)
        return 1;
    return -1;
}
pair<int,int> gaseste(int num,int x,int y){
for(int i=0;i<=n;i++)
for(int j=0;j<=m;j++){
    if(i==x&&j==y)
        continue;
    if(a[i][j]==num)
    return  {i,j};
}
return {0,0};
}
void bfs(pair<int,int> pereche){
deque<pair<pair<int,int>,pair<int,int> > > q,qp;
int x=pereche.first;
int y=pereche.second;
q.push_back({{x,y},{0,0}});
fr[x][y][0]=1;
while(!q.empty()){

    x=q.front().first.first;
    y=q.front().first.second;
    int dist=q.front().second.first;
    int act=q.front().second.second;
    fr[act][x][y]=1;
    q.pop_front();
    if(a[x][y]==finish&&act==0){
        cout<<dist<<endl;
        continue;
    }
    for(int d=0;d<4;d++){
        int nx=x+lin[d];
        int ny=y+col[d];
        if(fr[act][nx][ny]==0&&a[nx][ny]!=-1){
             q.push_back({{nx,ny},{dist+1,act}});
             fr[act][nx][ny]=1;
        }
    }
    if(a[x][y]>0){
        int nx=gaseste(a[x][y],x,y).first;
        int ny=gaseste(a[x][y],x,y).second;
        int na=nextAdancime(x,y);
        if(fr[act+na][nx][ny]==0&&a[nx][ny]>=0&&act+na>=0&&act+na<=25){
                q.push_back({{nx,ny},{dist+1,act+na}});
                fr[act+na][nx][ny]=1;
        }
    }

}
}
int main()
{
while(getline(fin,s[++n]));
m=122;
n--;
for(i=0;i<=n;i++)
    fout<<s[i]<<"\n";
for(i=0;i<=n;i++){
    for(j=0;j<=m;j++){
        if(s[i][j]=='.')
            a[i][j]=0;
        else if(s[i][j]=='#')
            a[i][j]=-1;
        else a[i][j]=-1;
    }

}
/// gasesc etichete in picioare;
i=0;
for(i=0;i<=90;i+=90)
for(j=0;j<=m;j++)
    if(s[i][j]>='A'&&s[i][j]<='Z'){
        string st;
        st+=s[i][j];
        st+=s[i+1][j];
        //cout<<st<<endl;
        if(mapa[st]==0){
            mapa[st]=++nretichete;
        }
        a[i+2][j]=mapa[st];
    }
    i=n-1;
    for(i=35;i<=n-1;i+=n-1-35)
for(j=0;j<s[i].size();j++){
    if(s[i][j]>='A'&&s[i][j]<='Z'){
        string st;
        st+=s[i][j];
        st+=s[i+1][j];
        //cout<<st<<endl;
        if(mapa[st]==0){
            mapa[st]=++nretichete;
        }
        a[i-1][j]=mapa[st];
    }
}

for(i=2;i<=n-2;i++){
    for(j=0;j<=86;j+=86){
        if(s[i][j]>='A'&&s[i][j]<='Z'){
            string st;
            st+=s[i][j];
            st+=s[i][j+1];
            //cout<<st<<endl;
            if(mapa[st]==0){
            mapa[st]=++nretichete;
        }
        a[i][j+2]=mapa[st];
        }
    }


}
for(i=2;i<=n-2;i++){
    for(j=35;j<=121;j+=86){
        if(s[i][j]>='A'&&s[i][j]<='Z'){
            string st;
            st+=s[i][j];
            st+=s[i][j+1];
            //cout<<st<<endl;
            if(mapa[st]==0){
            mapa[st]=++nretichete;
        }
        a[i][j-1]=mapa[st];
        }
    }


}
start=mapa["AA"];
finish=mapa["ZZ"];
bfs(gaseste(start,0,0));
}
