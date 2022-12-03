#include <iostream>

using namespace std;

int main(){
  float mediaUm = (8 + 9 + 7)/3;
  float mediaDois = (4 + 5 + 6)/3;

  float somaMedias = mediaUm + mediaDois;

  cout << "Soma das duas medias: " << somaMedias << endl;
  cout << "Media das medias: " << somaMedias/2;
}