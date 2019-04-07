#include <iostream>
#include<string>

int tresn(int x){
    int num =x;
    int counter =0;
    while (num !=1){
        if (num%2 == 0){
            num=num/2;
        }else
        {
            num=(3*num)+1;
        }
        ++counter;
    
}return(counter+1);}


int main(){
int a,b,maxi;

std::string line;

   
    while (std::cin>>a>>b){
        maxi=0;
    if (b>=a){
    for(int i = a; i <= b; i++)
    {
        maxi=std::max(maxi,tresn(i));
    }
    std::cout<<a<<' '<<b<<' '<<maxi<<'\n';
    }else{
        for(int i = b; i < a; i++)
        {
            maxi=std::max(maxi,tresn(i));

        }
        std::cout<<a<<' '<<b<<' '<<maxi<<'\n';   }}}