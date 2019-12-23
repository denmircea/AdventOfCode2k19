#include <bits/stdc++.h>
using namespace std;
ifstream fin ("test.in");
ofstream fout("test.out");
deque<int> q,aux,d;
int n;
string cuvant;
void afis(deque<int> q){
for(auto it:q)
    cout<<it<<" ";
}
int main()
{
    for(int i=0;i<10007;i++)
        d.push_back(i);
   while(fin>>cuvant){

        if(cuvant=="cut"){
            fin>>n;
                if(n>=0){
                   aux.clear();
                   while(n--){
                    aux.push_back(d.front());
                    d.pop_front();
                   }
                   while(!aux.empty()){
                    d.push_back(aux.front());
                    aux.pop_front();
                   }
                }
                else{
                    n=abs(n);
                    aux.clear();
                   while(n--){
                    aux.push_front(d.back());
                    d.pop_back();
                   }
                   while(!aux.empty()){
                    d.push_front(aux.back());
                    aux.pop_back();
                   }
                }




            continue;
        }
        fin>> cuvant;
        if(cuvant=="into"){
            fin>>cuvant>> cuvant;
            aux.clear();
            while(!d.empty()){
                aux.push_front(d.front());
                d.pop_front();
            }
            d=aux;
        }
        else if(cuvant=="with"){
            fin>>cuvant;
            fin>>n;
            aux=d;
            int poz=-n;
            for(auto it:d){
                poz+=n;
                poz%=d.size();
                aux[poz]=it;
            }
            d=aux;
        }

   }
   for(int i=0;i<d.size();i++){
    if(d[i]==2019){
        cout<<i;
    }
   }
}
