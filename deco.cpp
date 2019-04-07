#include<iostream>
#include<string>
using namespace std;




int main(){
string linea;
int codec=7;

    while (getline(cin,linea)){
        for(char &current:linea){
        current = current - codec;
    }     
        cout<<linea<<'\n';}
}