#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// <---------------------------->
string s[200];
int k,i,j,n;
int nr[200][200];
int X=14,Y=11;
int viz[200][200];
int x,y;
set<pair<int,int> > diez;
int det(int x1, int y1, int x2, int y2, int x3, int y3) {
 return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}
double dist(int x1,int y1,int x2,int y2){
return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int cmp(const pair<int, int> &a, const pair<int, int> &b) {
 int d = det(X, Y,b.first, b.second, a.first, a.second );
 if (d != 0)
 return d > 0;

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

           )
           {
            return 0;
            }
    }
}
if(x==X&&y==Y){
    viz[x1][y1]=1;
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
            cout<<viz[i][j]<<" ";
            if(nr[i][j]==210)
                fout<<i<<" "<<j<<endl;
            maxx=max(nr[i][j],maxx);
        }
        fout<<maxx;
    /// sunt la pozitia 30 28 sa aflu cate am in stanga
int nr1=0;
    for(i=1;i<X;i++)
        for(j=0;j<Y;j++)
            nr1+=viz[i][j];
            cout<<nr1<<endl;
    /// nr1=171 deco se nr 200 se afla in cadranul 4
    /// 340-171=169 au fost deja parcurse
    /// pana la 200 mai sunt 31


    /// pt ex 80 210-80 = 130 mai sunt 70
    int gas=70;
    fout<<endl;
    vector< pair<int,int> >unu;
    for(i=1;i<X;i++,fout<<endl)
        for(j=0;j<Y;j++)
            if(viz[i][j]==0)
            fout<<" ";
        else{
        unu.push_back({i,j});
        fout<<"1";
        }
        sort(unu.begin(),unu.end(),cmp);
    cout<<endl;
    cout<<unu.size()<<endl;
    for(i=0;i<=X;i++){
            cout<<unu[i].first<<" "<<unu[i].second<<endl;
    }
    cout<<unu[69].first<<" "<<unu[69].second;
    //// TREBUIA Afisat invers....

}
