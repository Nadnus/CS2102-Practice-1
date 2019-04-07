#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long> desmenuzar(long a){
     vector<long> vec;
    while (a !=0){
    long buffer = a%10;
    a = a/10;
    vec.push_back(buffer);
  }
  return vec;
}
//c es la BASE, ACUERDATE QUE ES sizea+sizeb /4
long karatsubaSplit(vector<long> a, long c, bool b){
  long a1, a2 =0;
  long sizea= a.size();
   for (long i = 0; i < c; ++i){
      if (i<=(c/2)){
       a1 = a1 + a[i]*(pow(10,i));
    }else{
      a2 = a2 + a[i]*(pow(10,i));
    }
  if (b){
    return (a1);
  }else{return a2;}


}
}
long Karatsuba(long ia , long ib){
    long  accum = 0;
    //ksplits va a almacenar a todos los Numeros partidos, y a la hora de partirlos insertarlos
    vector<long> a = desmenuzar(ia);
    vector<long> b = desmenuzar(ib);
    vector<long> kSplits;
    long sizea= a.size();
    long sizeb= b.size();
    long n1=0,n2 =0;
    //elegimos la base
    long base = ((sizea+sizeb)/4)+1;
    long a1=0,b1=0,a2=0,b2=0,z0=0,z1=0,z2 =0;
   
    if (base==2){
      for (long i = 0; i < sizea; ++i){
       
       n1 = n1 + a[i]*(pow(10,i));

      }
      for (long i = 0; i < sizeb; ++i){n2 = n2 + b[i]*(pow(10,i));}
      return(n1*n2);
    }else{
      //aca abajo estan
      for (long i = 0; i < sizea; ++i){
        if (i<(base)){
        a1 = a1 + a[i]*(pow(10,i));
      }else{
        //estoy poniendo el -n/2
        a2 = a2 + a[i]*(pow(10,i-base));
      }
      }
      for (long j = 0; j < sizeb; j++){
        if (j<(base)){
        b1 = b1 + b[j]*(pow(10,j));
      }else{
        b2 = b2 + b[j]*(pow(10,j-base));
      }
      }
      z0 = Karatsuba(a1,b1);
z1= Karatsuba(a1,b2)+Karatsuba(a2,b1);
z2=Karatsuba(a2,b2);
long t1= Karatsuba (z2,pow(10,2*base));
long t2= Karatsuba (z1,pow(10,base));
return(z0+t1+t2);
}

}

long  gradeSchool(vector<long> a , vector<long> b ){
  long  accum = 0;
  long sizea= a.size();
  long sizeb= b.size();

    for (long i = 0; i != sizea; ++i){
    for(long j = 0 ; j != sizeb ;++j){
      long  test = pow(10.0, i+j);
      long  buffa = (a[i] * b[j])*test;
       accum = accum + buffa;
        }
     }
  return(accum);

}
int main() {
  long a,b;
  a=123;
  b=4567;
  long z = a*b;
  vector<long> va;
  vector<long> vb;

  va = desmenuzar(a);
  vb = desmenuzar(b);

 
  long w =Karatsuba(a,b);
 
  
  return 0;
}
