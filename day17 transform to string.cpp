#include <iostream>

using namespace std;
int main()
{
    string inp="A,C,A,B,B,A,C,B,C,C";
    for(int i=0; i<inp.size(); i++)
        cout<<int(inp[i])<<" ";
    cout<<10<<"\n";
    string a="L,8,R,10,L,8,R,8";
    for(int i=0; i<a.size(); i++)
        cout<<int(a[i])<<" ";
    cout<<10<<"\n";
    string b="L,8,R,6,R,6,R,10,L,8";
    for(int i=0; i<b.size(); i++)
        cout<<int(b[i])<<" ";
    cout<<10<<"\n";
    string c="L,12,R,8,R,8";
    for(int i=0; i<c.size(); i++)
        cout<<int(c[i])<<" ";
    cout<<10<<"\n";
}
