#include<iostream>
#include "Queue.hh"

using std::cout;
using std::cin;
using std::endl;

int main(){
    Priority_Queue<int,string> Kolejeczka;
    Kolejeczka.insert(2,"ma");
    Kolejeczka.insert(4,"i");
    Kolejeczka.insert(1,"Ala");
    Kolejeczka.insert(5,"psa");
    Kolejeczka.insert(3,"kota");
    Kolejeczka.insert(0,"i");
    Kolejeczka.insert(-1,"Bartek");
    //cout<<Kolejeczka.min()<<endl;
    while (!(Kolejeczka.is_empty()))
    {
        cout<<Kolejeczka.remove_min()<<endl;
    }
    
}