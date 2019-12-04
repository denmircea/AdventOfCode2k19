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
}
 int num=1;
for(int i=2;i<=6;i++){
    if(a[i]==a[i-1])
        num++;
    else{
        if(num==2)
           return 1;
        num=1;
    }
}
if(num==2)
    return 1;
return 0;
}
int main()
{
    for(int i=245318;i<=765747;i++){
     int  x=i;
     int   nr=6;
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
