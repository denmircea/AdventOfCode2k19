#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int inm[]={1,0,-1,0};
int k,s[2000000],v[20000000];
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
    int exit=0;
    for(int i=0;i<7;i++)
        exit=exit*10+v[i];
        cout<<exit<<endl;
        cout<<(k+1)*10000;
    int lungime=k;
    for(int rep=1;rep<=9999;rep++)
    for(int i=0;i<=lungime;i++)
        v[++k]=v[i];
        cout<<endl;
        /// cand esti la jumate 00000001111111
    for(int phase=1;phase<=100;phase++){
        int sum=0;
        for(int i=k;i>=k/2-2;i--){
            sum+=v[i];
            v[i]=sum%10;
        }
    }
for(int i=5970221;i<=5970221+7;i++)
            cout<<v[i];
        cout<<endl;
}
