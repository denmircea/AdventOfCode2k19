#include <bits/stdc++.h>

using namespace std;
ifstream fin("test.in");
string s[7];
bitset<(1<<25)> fr;
int a[10][10],i,j,n=-1,m;
int lin[]= {0,1,0,-1};
int col[]= {1,0,-1,0};
int convertnumber()
{
    int p=1,sum=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i][j]==1)
            {
                sum+=p;
            }
            p<<=1;
        }
    return sum;
}
int vecini(int x,int y,int val)
{
    int nr=0;
    for(int d=0; d<4; d++)
    {
        int nx=x+lin[d];
        int ny=y+col[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==val||a[nx][ny]==-val)
        {
            nr++;
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
                a[i+1][j+1]=1;
            else
                a[i+1][j+1]=0;
        }
    m=s[1].size();
    int x = convertnumber();
    fr[x]=1;
    int numar=0;
    while(1)
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==0)
                {
                    int nr=vecini(i,j,1);
                    if(nr<=2&&nr>=1)
                    {
                        a[i][j]=2;
                    }
                }
            }

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==1)
                {
                    int nr=vecini(i,j,1);
                    if(nr==1)
                        continue;
                    else
                        a[i][j]=-1;
                }
            }

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                if(a[i][j]==2)
                {
                    a[i][j]=1;
                }
                if(a[i][j]==-1)
                    a[i][j]=0;
            }
        int x=convertnumber();
        if(fr[x]==1)
        {
        cout<<x;
            return 0;
        }
        fr[x]=1;

    }

            cout<<endl;
            for(i=1; i<=n; i++,cout<<endl)
                for(j=1; j<=m; j++)
                    cout<<a[i][j];
            cout<<x;
}
