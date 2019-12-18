#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
map <int, int> d[90][90];
string s[1001];
deque < pair<int,int> > inputs;
int xstart,ystart,n,i,solmax,dist,sol[4],robot;
deque< pair< pair<int,int>, int> >  R[4];
bitset<100> fr[100];
set<int> chei[4],usi[4];
/// bfs pe stari
int lin[]= {0,1,0,-1};
int col[]= {1,0,-1,0};
void dfs(int x,int y)
{

    fr[x][y]=1;
  //  cout<<x<<" "<<y<<" "<<s[1][13]<<endl;
    if(s[x][y]>='A'&&s[x][y]<='Z')
    {
        usi[robot].insert(s[x][y]);
    }
    if(s[x][y]>='a'&&s[x][y]<='z')
    {
        cout<<s[x][y]<<endl;
        chei[robot].insert(s[x][y]-('a'-'A'));
    }
    for(int D=0; D<4; D++)
    {
        int nx=x+lin[D];
        int ny=y+col[D];
        if(s[nx][ny]=='#'||fr[nx][ny]==1)
            continue;
        dfs(nx,ny);
    }




}
void bfs(int x,int y,int robot)
{
    deque< pair< pair<int,int>, int> > q;
    q.push_back({{x,y},0});
    while(!q.empty())
    {
        x=q.front().first.first;
        y=q.front().first.second;
        int H=q.front().second;
        q.pop_front();
        for(int D=0; D<4; D++)
        {
            int nx=x+lin[D];
            int ny=y+col[D];
            if(s[nx][ny]=='#')
                continue;
                if(usi[robot].find(s[nx][ny])!=usi[robot].end()){
                    s[nx][ny]='.';
                }
            if(s[nx][ny]>='A'&&s[nx][ny]<='Z')
            {
                int bit=s[nx][ny]-'A';


                if(((1<<bit)&H)==0||s[nx][ny]!='.')
                    continue;
            }
            int nH=H;
            if(s[nx][ny]>='a'&&s[nx][ny]<='z')
            {
                int bit=s[nx][ny]-'A';
                nH|=(1<<bit);
            }
            if(d[nx][ny].find(nH)!=d[nx][ny].end())
                continue;
            d[nx][ny][nH]=d[x][y][H]+1;
            int biti=0;
            int nnH=nH;
            while(nH!=0){
                if(nH%2==1)
                    biti++;
                nH/=2;
            }
            if(biti==chei[robot].size())
            {
                sol[robot]=min(d[nx][ny][nnH],sol[robot]);
            }
            q.push_back({{nx,ny},nnH});
        }
    }
}
int main()
{
    while(fin>>s[n++])
    {
        for(i=0; i<s[n-1].size(); i++)
            if(s[n-1][i]=='@')
            {
                s[n-1][i]='.';
                xstart=n-1;
                ystart=i;
                inputs.push_back({xstart,ystart});
            }
    }
    for(int i=0; i<=3; i++)
    {
        /// i=zona
        /// determin cate usi si cate chei am intr o zona
        robot=i; /// variabila globala
        dfs(inputs[i].first,inputs[i].second);
        //cout<<usi[0].size();
        for(auto it:chei[robot]){
            usi[robot].erase(it);
        }
        cout<<usi[robot].size()<<" "<<chei[robot].size()<<endl;
    }
    int H=0;

    for(auto it=0; it<=3; it++)
        sol[it]=INT_MAX;
        for(int it=3; it>=0; it--)
            bfs(inputs[it].first,inputs[it].second,it);
     // for(auto it=0; it<=3; it++)
     //   cout<<sol[it]<<" ";
        cout<<sol[0]+sol[1]+sol[2]+sol[3];
}

