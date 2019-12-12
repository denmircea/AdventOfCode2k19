#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
pair<int,pair<int,int> > p[5],v[5];
int i,j,k,n;
int main()
{
    /*
    <x=-13, y=14, z=-7>
    <x=-18, y=9, z=0>
    <x=0, y=-3, z=-3>
    <x=-15, y=3, z=-13>


    <x=-1, y=0, z=2>
    <x=2, y=-10, z=-7>
    <x=4, y=-8, z=8>
    <x=3, y=5, z=-1>
    */
//    p[1].x=-1;
//    p[1].y=0;
//    p[1].z=2;
////
//    p[2].x=2;
//    p[2].y=-10;
//    p[2].z=-7;
////
//    p[3].x=4;
//    p[3].y=-8;
//    p[3].z=8;
////
//    p[4].x=3;
//    p[4].y=5;
//    p[4].z=-1;

    p[1].x=-13;
    p[1].y=14;
    p[1].z=-7;
    //
    p[2].x=-18;
    p[2].y=9;
    p[2].z=0;
    //
    p[3].x=0;
    p[3].y=-3;
    p[3].z=-3;
    //
    p[4].x=-15;
    p[4].y=3;
    p[4].z=-13;

    for(i=1; i<=1000; i++)
    {
        for(j=1; j<=4; j++)
            for(k=1; k<=4; k++)
            {
                if(j==k)
                    continue;
                if(p[j].x<p[k].x)
                {
                    v[j].x++;
                }
                else if(p[j].x>p[k].x)
                {
                    v[j].x--;
                }
                if(p[j].y<p[k].y)
                {
                    v[j].y++;
                }
                else if(p[j].y>p[k].y)
                {
                    v[j].y--;
                }
                if(p[j].z<p[k].z)
                {
                    v[j].z++;
                }
                else if(p[j].z>p[k].z)
                {
                    v[j].z--;
                }
            }
        for(j=1; j<=4; j++)
        {
            p[j].x+=v[j].x;
            p[j].y+=v[j].y;
            p[j].z+=v[j].z;
        }
        cout<<p[1].x<<" "<<p[1].y<<" "<<p[1].z<<endl;
        cout<<v[1].x<<" "<<v[1].y<<" "<<v[1].z<<endl;
    }
    int sum=0;
    for(j=1; j<=4; j++)
    {
        int sum1=abs(p[j].x)+abs(p[j].y)+abs(p[j].z);
        int sum2=abs(v[j].x)+abs(v[j].y)+abs(v[j].z);
        sum+=sum1*sum2;
    }
    cout<<sum;
}
