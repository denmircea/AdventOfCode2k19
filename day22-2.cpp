#include <bits/stdc++.h>
#include "InfInt.h"
/// https://github.com/sercantutar/infint/blob/master/InfInt.h
using namespace std;
ifstream fin ("test.in");
ofstream fout("test.out");
deque<int> q,aux,d;
InfInt a,b,mod=119315717514047;
string cuvant;

InfInt put (InfInt a,InfInt b)
{
        if(b==0)
            return 1;
        else
        if(b==1)
            return a%mod;
    if(b%2==0)
      return put(a*a%mod,b/2);
      else
        return a*put(a*a%mod,(b-1)/2)%mod;

}
InfInt gasestex(InfInt poz,InfInt n){
/// n nr de carti
/// care e pozitia cartii poz la final ?
fin.close();
fin.open("test.in");
InfInt x;

while(fin>>cuvant)
    {
        if(cuvant=="cut")
        {
            /// cut
            fin>>x;
            if(x<0)
                x=n+x;
            poz=(poz+n-x)%n;
            continue;
        }
        fin>> cuvant;
        if(cuvant=="into")
        {
            ///deal into new stack
            fin>>cuvant>>cuvant;
            poz=n-poz-1;
        }
        else if(cuvant=="with")
        {
            ///deal with increment N
            fin>>cuvant>>x;
            poz=poz*x%n;
        }

    }
    return poz;
}
int main()
{
    cout<<gasestex(2019,10007)<<endl;
    /// some reddit tips :))))
    /// ramane de calculat f(f(f(...f(x) ) ) )   ---  de 101741582076661 ori
    /// f(x) = a*x+b;
    /// mod este numar prim deci invers modular inv(x)= x^(mod-2)
    b=gasestex(0,mod);
    a=((gasestex(1,mod)-b)%mod + mod)%mod;

    cout<<a<<" "<<b<<endl;
    InfInt n=101741582076661;
    InfInt x=2020;
   /// ax+b
   /// f(f(x))=(a^2)*x+ ab + b;
   /// f^n(x)= (a^n)*x +      (a^(n-1))*b+(a^(n-2))*b+....+ (a^0)*b
   /// = (a^n)*x +   b*( a^0 + ...+ a^(n-1))
   /// = (a^n)*x + b*( ((a^(n))-1)/(a-1) )
   InfInt a1_inv = put(a-1,mod-2);   /// 1/ (a-1)
   a=put(a,mod-2);       /// a=1/a;
   InfInt a_la_n=put(a,n);   /// 1/(a^n)
   cout<<n<<endl;
   cout<<a_la_n-1<<" "<<a1_inv<<" "<<(a_la_n-1)*(a1_inv)<<endl;
    InfInt rezultat=(a_la_n-1)*a1_inv;
    rezultat%=mod;
    cout<<rezultat<<" "<<b<<" "<<rezultat*b<<endl;
    rezultat*=b;
    rezultat%=mod;
    rezultat+=a_la_n*x%mod;
    rezultat%=mod;
   cout<<"rez: "<<rezultat; 
}

