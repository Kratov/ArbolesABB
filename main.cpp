#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cctype>

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
bool esUnNumero(const char* cadena);
bool seguirIngresando();
char mainMenu();
int pedirNumero();


int main() {
	char op = '0';
	Nodo * arbol = NULL;
	do {
		system("CLS");
		if (arbol) {
			printf("\n	============ ARBOL ABB ============	\n\n");
			mostrar(arbol, 0);
			printf("\n	============ FIN ARBOL ABB ============	\n\n");
		}
		switch (op = mainMenu())
		{
		case '1':
				insertar(arbol, pedirNumero(), NULL);
			break;
		case '2':
			printf("\n	============ PREORDER ============	\n\n");
			preOrder(arbol);
			printf("\n\n	============ FIN PREORDER ============	\n\n");
			break;
		case '3':
			printf("\n	============ INORDER ============	\n\n");
			inOrder(arbol);
			printf("\n\n	============ FIN INORDER ============	\n\n");
			break;
		case '4':
			printf("\n	============ POSTORDER ============	\n\n");
			postOrder(arbol);
			printf("\n\n	============ FIN POSTORDER ============	\n\n");
			break;
		}
		printf("\n");
		system("PAUSE");
	} while (op != '0');
	return 0;
}

char mainMenu()
{
	char temp = '0';
	printf("\n	PROGRAMA DE LECTURA DE ARBOLES ABB\n	1. Insertar	\n	2. Leer PreOrden  (RID)	\n	3. Leer InOrden   (IRD)	\n	4. Leer PostOrden (IDR)	\n	0. Salir\n	Seleccion: ");
	scanf(" %c", &temp);
	return temp;
}

bool seguirIngresando()
{
	char temp = '0';
	do {
		printf("\n	Desea seguir ingresando valores al arbol (Y/N)?	");
		scanf(" %c", &temp);
		switch (temp)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		}
	} while (temp != 'Y' || temp != 'N');
}

bool esUnNumero(const char* cadena)
{
	for (; *cadena; ++cadena)
		if (!std::isdigit(*cadena))
			return false;
	return true;
}

int pedirNumero()
{
	char temp[255];
	do {
		printf("\n	Ingrese numero: ");
		scanf(" %s", temp);
	} while (!esUnNumero(temp));
	return atoi(temp);
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
			printf("	");
		printf("	%d\n", arbol->dato);
		mostrar(arbol->izq, espaciado+1);
		
	}
}

void preOrder(Nodo * arbol) {
	if (!arbol)
		return;
	else
	{
		printf("	%d ", arbol->dato);
		preOrder(arbol->izq);
		preOrder(arbol->der);
	}
}

void inOrder(Nodo * arbol) {
	if (!arbol)
		return;
	else
	{
		inOrder(arbol->izq);
		printf("	%d ", arbol->dato);
		inOrder(arbol->der);
	}
}

void postOrder(Nodo * arbol) {
	if (!arbol)
		return;
	else
	{
		postOrder(arbol->izq);
		postOrder(arbol->der);
		printf("	%d ", arbol->dato);
	}
}

