#include<bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int n;
long long sum;
int main()
{
       while(fin>>n){
           while(n>6){
            n/=3;
            n-=2;
            sum+=n;
           }
       }
       fout<<sum;
}
