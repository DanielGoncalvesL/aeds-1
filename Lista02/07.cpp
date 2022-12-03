#include <iostream>

using namespace std;

int main(){
  int a,b,c,d,e,f;
  float x,y;

  cout<<"\nInforme o valor de a: ";
  cin>>a;

  cout<<"\nInforme o valor de b: ";
  cin>>b;

  cout<<"\nInforme o valor de c: ";
  cin>>c;

  cout<<"\nInforme o valor de d: ";
  cin>>d;

  cout<<"\nInforme o valor de e: ";
  cin>>e;

  cout<<"\nInforme o valor de f: ";
  cin>>f;

  if((float) a/d != (float) b/e){
    x=(f*a-d*c)/(a*e-d*b);

    y=(c-b*x)/a ;

    cout << "\nValor de X: " << x;

    cout << "\nValor de Y: " << y;

    cout << "\nO sistema é possível!";
  }else if((float) a/d == (float) b/e && (float) b/e == (float) d/f){
    cout << "\nO sistema é indeterminado!";
  }else {
    cout << "\nO sistema é impossível!";
  }
}
