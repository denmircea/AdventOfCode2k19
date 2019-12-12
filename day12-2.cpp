#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
pair<long long,pair<long long,long long> > p[5],v[5],p2[5],nul;
long long i,j,k,n;
long long cmmmc(long long X,long long Y){
    long long a=X,b=Y;
    while(b){
        long long r=a%b;
        a=b;
        b=r;
    }
    return 1LL*X*Y/a;

}
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
    memcpy(p2,p,sizeof(p));/// pozitiile initiale
    for(i=1;;i++)
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
        int ok=0;
            for(j=1;j<=4;j++){
                if(p[j].z==p2[j].z&&v[j].z==0){
                   ok++;
                }
            }
            if(ok==4){
                cout<<i;
                ;return 0;
            }
            /// 231614
            /// 193052
            /// 102356
            long long r=cmmmc(231614LL,193052LL);
            r=cmmmc(r,102356LL);
           cout<<r<<endl;

        }




   // cout<<sum;
}
