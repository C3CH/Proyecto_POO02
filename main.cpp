#include <iostream>
#include <sstream>
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
	Prendas(){};
    Prendas(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
            float peso_polos0, float peso_camisas0, float peso_cuellos0):
            Cantidad_polos(Cantidad_polos0), Cantidad_camisas(Cantidad_camisas0),
            Cantidad_cuellos(Cantidad_cuellos0), peso_polos(peso_polos0),
            peso_camisas(peso_camisas0), peso_cuellos(peso_cuellos0){};
    virtual ~Prendas();
    virtual float calculo_tiempos()=0;
    
};

class Jersey: public Prendas{
public:
	Jersey(){};
    Jersey(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
           float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                   Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};
    virtual ~Jersey();
		
};

class Pique: public Prendas{
public:
	Pique(){};
    Pique(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
          float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                  Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};
    virtual ~Pique();
};

class Franela: public Prendas{
public:
	Franela(){};
    Franela(int Cantidad_polos0, int Cantidad_camisas0, int Cantidad_cuellos0,
            float peso_polos0, float peso_camisas0, float peso_cuellos0): Prendas(Cantidad_polos0,
                    Cantidad_camisas0, Cantidad_cuellos0, peso_polos0, peso_camisas0, peso_cuellos0){};
    virtual ~Franela();
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

    float pesos_numeros[9]={};
    int contador=0;
    while(inicio.is_open()){
      getline(inicio,linea);
      Pesos_string[contador]=linea;
      istringstream(linea)>>pesos_numeros[contador];
      contador++;
    };

    for (int i=0; i<Tipos_tela; i++){
      cout<<"Ingrese cantidad de polos para la tela "<<Telas[i]<<": ";
      cin>>Cantidad_polos;
      cout<<"Ingrese cantidad de camisas para la tela "<<Telas[i]<<": ";
      cin>>Cantidad_camisas;
      cout<<"Ingrese cantidad de cuellos para la tela "<<Telas[i]<<": ";
      cin>>Cantidad_cuellos;
      cout<<endl;

      if (i==0){objetos[i]=new Jersey(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos, pesos_numeros[0],pesos_numeros[1],pesos_numeros[2]);}
      if (i==1){objetos[i]=new Pique(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos,pesos_numeros[3],pesos_numeros[4],pesos_numeros[5]);}
      if (i==2){objetos[i]=new Franela(Cantidad_polos, Cantidad_camisas, Cantidad_cuellos,pesos_numeros[6],pesos_numeros[7],pesos_numeros[8]);}
    };
    return 0;
}

float calculo_tiempos(float M[][COLUMNAS], size_t FILAS, size_t COLUMNAS, float &JERSEY, float &PIQUE, float &FRANELA)
{
	float TIEMPO=0;
	float TIEMPOS[9]={0.20, 0.50, 0.05, 0.22, 0.33, 0.04, 0.25, 0.50, 0.05};
	for(size_t i=0; i<FILAS; i++)
	{
		if(i<3)
			JERSEY += ((M[i][0]*M[i][1])+(M[i][0]*M[i][1]/10)+(M[i][0]*M[i][1]/20)+(M[i][0]*M[i][1]/TIEMPOS[i]));
		if(2<i and i<6)	
			PIQUE += ((M[i][0]*M[i][1])+(M[i][0]*M[i][1]/10)+(M[i][0]*M[i][1]/20)+(M[i][0]*M[i][1]/TIEMPOS[i]));
		if(5<i and i<9)	
			FRANELA += ((M[i][0]*M[i][1])+(M[i][0]*M[i][1]/10)+(M[i][0]*M[i][1]/20)+(M[i][0]*M[i][1]/TIEMPOS[i]));
	}
	TIEMPO = JERSEY + PIQUE + FRANELA;
	return TIEMPO;
}

float calculo_materia_prima(float M[][COLUMNAS], size_t FILAS, size_t COLUMNAS, float &jersey_T, float &pique_T, float &franela_T)
{
	float materia_prima=0, R=1;
	float MATERIA[3]={0.7, 0.5, 0.3};
	/*Para calcular la materia prima usamos la formula preestablecida:
	 * Materia prima=Kg tela / rendimiento*/
	for(size_t i=0; i<FILAS; i++)
	{
		if(i<3)
			jersey_T += (M[i][1]*M[i][0])/(R*MATERIA[0]);
		if(2<i and i<6)
			pique_T += (M[i][1]*M[i][0])/(R*MATERIA[1]);
		if(5<i and i<9)
			franela_T += (M[i][1]*M[i][0])/(R*MATERIA[2]);
	}
	materia_prima = jersey_T + pique_T + franela_T;
	return materia_prima;
}

float calculo_costos(float M[][COLUMNAS], size_t FILAS, size_t COLUMNAS, float MP, float T, float &jersey_T, float &pique_T, float &franela_T, float &JERSEY, float &PIQUE, float &FRANELA)
{
	float PRECIOS[9]={30, 50, 5, 60, 75, 10, 60, 80, 15};
	float TOTAL_PRENDAS=0, GJ=0, GP=0, GF=0, GANANCIA_J, GANANCIA_P, GANANCIA_F;
	float C_VENTA=0, C_PRODUCCION=0, C_MP=0, C_HORAS=0, C_VENTA_J=0, C_VENTA_P=0, C_VENTA_F=0;
	for(size_t i=0; i<FILAS; i++)
	{
		if(i<3)
			C_VENTA_J += (M[i][0]*PRECIOS[i]);
		if(2<i and i<6)
			C_VENTA_P += (M[i][0]*PRECIOS[i]);
		if(5<i and i<9)
			C_VENTA_F += (M[i][0]*PRECIOS[i]);
		C_VENTA = C_VENTA_J + C_VENTA_P + C_VENTA_F;
	}
	//Para el calculo de costo de producción multiplicamos el costo de la materia prima más el costo de producción por hora
	C_MP = (MP)*precio_hilo;
	C_HORAS = (T)*precio_horas;
	GANANCIA_J = C_VENTA_J - (jersey_T*precio_hilo + JERSEY*precio_horas);
	GANANCIA_P = C_VENTA_P - (pique_T*precio_hilo + PIQUE*precio_horas);
	GANANCIA_F = C_VENTA_F - (franela_T*precio_hilo + FRANELA*precio_horas);
	cout << "GANANCIA JERSEY: " << GANANCIA_J << " soles\n" << "TIEMPO: " << JERSEY << " horas\nMATERIA PRIMA: " << jersey_T << " kg\n\n";
	cout << "GANANCIA PIQUE: " << GANANCIA_P << " soles\n" << "TIEMPO: " << PIQUE << " horas\nMATERIA PRIMA: " << pique_T << " kg\n\n";
	cout << "GANANCIA FRANELA: " << GANANCIA_F << " soles\n" << "TIEMPO: " << FRANELA << " horas\nMATERIA PRIMA: " << franela_T << " kg\n\n";
	C_PRODUCCION = C_MP + C_HORAS;
	for(size_t x=0; x<FILAS; x++)
		TOTAL_PRENDAS += M[x][0];
	if(100 < TOTAL_PRENDAS)
		C_PRODUCCION = 0.8*(C_MP + C_HORAS);
	GJ = (GANANCIA_J)/JERSEY;
	GP = (GANANCIA_P)/PIQUE;
	GF = (GANANCIA_F)/FRANELA;
	cout << "RECOMENDACIÓN:\n\n";
	if((GJ < GP or GP < GJ) and (GJ < GF or GP < GF))
		cout << "Conviene empezar por las prendas de franela.\n\n";
	else if((GJ < GF or GF < GJ) and (GJ < GP or GF < GP))
		cout << "Conviene empezar por las prendas de pique.\n\n";
	else if((GP < GF or GF < GP) and (GP < GJ or GF < GJ))
		cout << "Conviene empezar por las prendas de jersey.\n\n";
	cout << "GANACIA TOTAL: ";
	return (C_VENTA-C_PRODUCCION);
}

