#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <iomanip>

using namespace std;

class Prendas{
protected:
    int Cantidad_polos, Cantidad_camisas, Cantidad_cuellos;
    float peso_polos, peso_camisas, peso_cuellos;
public:
    Prendas(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
            float peso_polos0, float peso_camisas0, float peso_cuellos0):
            Cantidad_polos(Cantidad_polos0), Cantidad_camisas(Cantidad_camisas0),
            Cantidad_cuellos(Cantidad_cuellos0), peso_polos(peso_polos0),
            peso_camisas(peso_camisas0), peso_cuellos(peso_cuellos0){};
};

class Jersey: public Prendas{
public:
    Jersey(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
           float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                   Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};

};

class Pique: public Prendas{
public:
    Pique(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
          float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                  Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};
};

class Franela: public Prendas{
public:
    Franela(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
            float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                    Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};
};

const int Tipos_tela=3;

int main(){
    string linea;
    int Cantidad_polos, Cantidad_camisas, Cantidad_cuellos;
    string Telas[Tipos_tela]={"Jersey", "Pique", "Franela"};
    string Pesos_string[9]={};
    fstream inicio("inicio.txt", ios::in);

    Prendas **objetos= nullptr;
    objetos = new Prendas*[Tipos_tela];
    
    int contador=0;
    while(inicio.is_open()){
      getline(inicio,linea);
      Pesos_string[contador]=linea;
      contador++;
    };

    for (int i=0; i<Tipos_tela; i++){
      cout<<"Ingrese cantidad de polos para la tela "<<Telas[i]<<" :";
      cin>>Cantidad_polos;
      cout<<"Ingrese cantidad de camisas para la tela "<<Telas[i]<<" :";
      cin>>Cantidad_camisas;
      cout<<"Ingrese cantidad de cuellos para la tela "<<Telas[i]<<" :";
      cin>>Cantidad_cuellos;

      if (i==0){objetos[i]=new Jersey(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos);}
      if (i==1){objetos[i]=new Pique(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos);}
      if (i==2){objetos[i]=new Franela(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos);}
    };

    return 0;
}
