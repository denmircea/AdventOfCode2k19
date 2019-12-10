#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// <---------------------------->
string s[200];
int k,i,j,n;
int nr[200][200];
int x,y;
set<pair<int,int> > diez;
int det(int x1, int y1, int x2, int y2, int x3, int y3) {
 return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}

double dist(int x1,int y1,int x2,int y2){
return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool verif(int x,int y,int x1,int y1){
for(int i=1;i<=k;i++)
for(int j=0;j<s[i].size();j++){
    if(i==x&&j==y)
        continue;
    if(i==x1&&j==y1)
        continue;
    if(s[i][j]=='#'){
        /// problema
       // cout<<x1<<" "<<x<<" "<<y1<<" "<<y;
       double D=det(x,y,x1,y1,i,j);
        if(D==0 && dist(x,y,x1,y1)>dist(x,y,i,j)&&
                    dist(x1,y1,i,j)<dist(x,y,x1,y1)

           ){
             if(x==3&&y==1&&x1==3&&y1==2){
                  cout<<i<<" "<<j<<endl;
             }
            return 0;
        }
    }
}
return 1;
}
int main()
{
    while(fin>>s[++k]);
    for(i=1; i<=k; i++)
        for(j=0; j<=s[i].size(); j++)
        {
            if(s[i][j]=='#')
            {
                diez.insert({i,j});
            }
        }
    for(auto it=diez.begin(); it!=diez.end(); it++)
    {
        x=it->first;
        y=it->second;
        for(i=1; i<=k; i++)
            for(j=0; j<=s[i].size(); j++)
            {
                if(x==i&&y==j)
                continue;
                if(s[i][j]=='#')
                {
                   /// am gasit punct la i,j si asteroid curent la x y
                   if(verif(x,y,i,j)==1)
                    nr[x][y]++;
                }
            }


    }
    int maxx=0;
    for(i=1; i<=k; i++,cout<<endl)
        for(j=0; j<s[i].size(); j++)
        {
            cout<<nr[i][j]<<" ";
            maxx=max(nr[i][j],maxx);
        }
        fout<<maxx;
}
