#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
map <int , int> d[90][90];
string s[1001];
int xstart,ystart,n,i,solmax,dist,sol=INT_MAX;

deque< pair< pair<int,int>, int> >  q;
int notnull(int x,int y,int z){
return d[x][y][z];


}
/// bfs pe stari
int lin[]={0,1,0,-1};
int col[]={1,0,-1,0};
void bfs(int x,int y){
q.push_back({{x,y},0});
d[x][y][0];
while(!q.empty()){
    x=q.front().first.first;
    y=q.front().first.second;
   int H=q.front().second;
   q.pop_front();
    for(int D=0;D<4;D++){
        int nx=x+lin[D];
        int ny=y+col[D];
        if(s[nx][ny]=='#')
            continue;
        if(s[nx][ny]>='A'&&s[nx][ny]<='Z'){
            int bit=s[nx][ny]-'A';
            if(((1<<bit)&H)==0)
                continue;
        }
        int nH=H;
        if(s[nx][ny]>='a'&&s[nx][ny]<='z'){
            int bit=s[nx][ny]-'A';
            nH|=(1<<bit);
        }
        if(d[nx][ny].find(nH)!=d[nx][ny].end())
            continue;
            d[nx][ny][nH]=d[x][y][H]+1;
            if(nH==((1<<26)-1)){
                sol=min(d[nx][ny][nH],sol);
            }
            q.push_back({{nx,ny},nH});

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

            }
    }
    bfs(xstart,ystart);
    cout<<sol;
}
