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

void insertar(Nodo *&arbol, const int n, Nodo * padre);
void mostrar(Nodo * arbol, int espaciado);
void preOrder(Nodo * arbol);
void inOrder(Nodo * arbol);
void postOrder(Nodo * arbol);
void eliminar(Nodo *&arbol);


int main() {
	int datos[] = {8,3,1,6,4,7,10,14,13};
	Nodo * arbol = NULL;
	random_device rd;
	mt19937 engine(rd());
	uniform_int_distribution<int> intDistribution(0, 99);
	intDistribution(engine);
	for (int i = 0; i < 9; i++)
		insertar(arbol, datos[i]/*intDistribution(engine)*/, NULL);
	mostrar(arbol, 0);
	preOrder(arbol);
	printf("\n");
	inOrder(arbol);
	printf("\n");
	postOrder(arbol);
	printf("\n");
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

void mostrar(Nodo *arbol, int espaciado)
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

void preOrder(Nodo * arbol) {
	if (!arbol)
	{
		return;
	}
	else
	{
		printf("%d ", arbol->dato);
		preOrder(arbol->izq);
		preOrder(arbol->der);
	}
}

void inOrder(Nodo * arbol) {
	if (!arbol)
	{
		return;
	}
	else
	{
		inOrder(arbol->izq);
		printf("%d ", arbol->dato);
		inOrder(arbol->der);
	}
}

void postOrder(Nodo * arbol) {
	if (!arbol)
	{
		return;
	}
	else
	{
		postOrder(arbol->izq);
		postOrder(arbol->der);
		printf("%d ", arbol->dato);
	}
}

void eliminar(Nodo *&arbol)
{

}


