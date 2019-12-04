#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
/// <-------------------------------->
int a[8],x,i,nr,sol;
bool solve(int a[]){
    bool ok=0;
for(int i=2;i<=6;i++){
    if(a[i]<a[i-1])
        return 0;
    if(a[i]==a[i-1])
        ok=1;
}
return ok;
}
int main()
{
    for(i=245318;i<=765747;i++){
        x=i;
        nr=6;
        while(x){
           a[nr]=x%10;
           x/=10;
           nr--;
        }
        if(solve(a)==1)
            sol++;
    }
    cout<<sol;
}
