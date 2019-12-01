#include<bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int n;
long long sum;
int main()
{
       while(fin>>n){
            n/=3;
            sum+=n-2;
       }
       fout<<sum;
}
