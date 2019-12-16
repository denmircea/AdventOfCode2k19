#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
int inm[]={1,0,-1,0};
int k,s[10000],v[10000];
int solve(int start,int lun){
    int poz=0;
    int s=0;
for(int i=start;i<=k;i+=lun){
       // cout<<start<<" "<<i<<" "<<k<<" "<<lun<<endl;
    for (int j=i;j<i+lun;j++){

        s+=v[j]*inm[poz%4];
    }
    poz++;
}

return abs(s)%10;
}
int main()
{
    char c;
    while(fin>>c){
        v[k++]=c-'0';
    };
    k--;
    for(int phase=1;phase<=100;phase++){
        for(int start=0;start<=k;start++){
           s[start]=solve(start,start+1);
        }

        for(int i=0;i<=k;i++)
            v[i]=s[i];
//        for(int i=0;i<=k;i++)
//            cout<<v[i];
//        cout<<endl;
    }
for(int i=0;i<=7;i++)
            cout<<v[i];
        cout<<endl;
}
