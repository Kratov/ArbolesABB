#include<stdio.h>
#include<stdlib.h>
#include<random>

using namespace  std;

struct Nodo
{
	int dato;
	Nodo * padre;
	Nodo * izq;
	Nodo * der;
};

void insertar(Nodo *&arbol, const int n, Nodo *padre);
void mostrar(Nodo *&arbol, int espaciado);
void eliminar(Nodo *&arbol);

int main() {
	Nodo * arbol = NULL;
	random_device rd;
	mt19937 engine(rd());
	uniform_int_distribution<int> intDistribution(0, 99);
	intDistribution(engine);
	for (int i = 0; i < 10; i++)
		insertar(arbol, intDistribution(engine), NULL);
	mostrar(arbol, 0);
	system("PAUSE");
	return 0;
}

void insertar(Nodo *&arbol,  const int n, Nodo *padre)
{	
	if (!arbol) 
	{
		Nodo * nuevo = (Nodo*)malloc(sizeof(Nodo));
		nuevo->dato = n;
		nuevo->padre = padre;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		arbol = nuevo;
	}
	else
		if (n < arbol->dato)
			insertar(arbol->izq, n, arbol);
		else
			insertar(arbol->der, n , arbol);
}

void mostrar(Nodo *&arbol, int espaciado)
{
	if (!arbol)
		return;
	else
	{
		mostrar(arbol->der, espaciado+1);
		for (int i = 0; i < espaciado; i++)		
			printf("     ");
		printf("%d\n", arbol->dato);
		mostrar(arbol->izq, espaciado+1);
	}
}

void eliminar(Nodo *&arbol)
{

}


