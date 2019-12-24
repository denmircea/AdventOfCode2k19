#include <bits/stdc++.h>

using namespace std;
ifstream fin("test.in");
string s[7];
bitset<(1<<25)> fr;
int a[400][7][7],i,j,n=-1,m;
int lin[]= {-1,0,1,0};
int col[]= {0,1,0,-1};
int numara(int nivel){
    int nr=0;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    nr+=a[nivel][i][j];

    return nr;

}
int vecini(int x,int y,int niv)
{
    if(x==3&&y==3)
        return 0;
    int nr=0;
    for(int d=0; d<4; d++)
    {
        int nx=x+lin[d];
        int ny=y+col[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[niv][nx][ny]==1||a[niv][nx][ny]==-1)
        {
            nr++;
        }
        else if(nx==0||nx==n+1||ny==0||ny==m+1){
            /// se duce in nivel -1
            int nnx=3+lin[d];
            int nny=3+col[d];
            if(a[niv-1][nnx][nny]==1||a[niv-1][nnx][nny]==-1)
                nr++;
            }else if(nx==3&&ny==3){
                /// se duce la nivel +1
                if(d==0){
                    for(int j=1;j<=5;j++){
                      if( a[niv+1][5][j]==1||a[niv+1][5][j]==-1)
                        nr++;
                    }
                }
                 if(d==1){
                    for(int j=1;j<=5;j++){
                      if( a[niv+1][j][1]==1||a[niv+1][j][1]==-1)
                        nr++;
                    }
                }
                 if(d==2){
                    for(int j=1;j<=5;j++){
                      if( a[niv+1][1][j]==1||a[niv+1][1][j]==-1)
                        nr++;
                    }
                }
                 if(d==3){
                    for(int j=1;j<=5;j++){
                      if( a[niv+1][j][5]==1||a[niv+1][j][5]==-1)
                        nr++;
                    }
                }


            }
    }
    return nr;
}

int main()
{
    while(fin>>s[++n]);
    for(i=0; i<n; i++)
        for(j=0; j<s[0].size(); j++)
        {
            if(s[i][j]=='#')
                a[100][i+1][j+1]=1;
            else
                a[100][i+1][j+1]=0;
        }
    m=s[1].size();
    int numar=0;
    int st=100,dr=100;
    while(++numar<=200)
    {
        for(int nivel=st-1; nivel<=dr+1; nivel++)
        {
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++)
                {
                    if(a[nivel][i][j]==0)
                    {
                        int nr=vecini(i,j,nivel);
                        if(nr<=2&&nr>=1)
                        {
                            a[nivel][i][j]=2;
                        }
                    }
                }
        }
        for(int nivel=st-1; nivel<=dr+1; nivel++)
        {
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++)
                {
                    if(a[nivel][i][j]==1)
                    {
                        int nr=vecini(i,j,nivel);
                        if(nr==1)
                            continue;
                        else
                            a[nivel][i][j]=-1;
                    }
                }
        }
        for(int nivel=st-1; nivel<=dr+1; nivel++)
        {
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++)
                {
                    if(a[nivel][i][j]==2)
                    {
                        a[nivel][i][j]=1;
                    }
                    if(a[nivel][i][j]==-1)
                        a[nivel][i][j]=0;
                }
        }
        if(numara(st-1))
            st--;
        if(numara(dr+1))
            dr++;
    }
    int x=0;
for(i=st;i<=dr;i++){
    x+=numara(i);
}
cout<<x;
}
