#include "Grafo.h"
int main()
{
	Grafo grafo;
	int opcion;
	int a=0;
	map<string, Nodo<string>> newGraph;
	do
	{
		system("cls");
		cout << "Menu de Opciones" << endl;
		cout << "1 Insertar Archivo" << endl;
		cout << "2 Kruskal" << endl;
		cout << "3 Mostrar" << endl;
		cout << "4 Salir" << endl;
		cout << " Escoja la opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			grafo.leerArchivo(grafo.getGrafo(), "direccion.txt");
			break;
		case 2:
			//cout << "Ingrese un origen: ";
			newGraph = grafo.kruskal(grafo.getGrafo(), a);
			cout<<"result : ";
			grafo.mostrar(newGraph);
			break;
		case 3:
			grafo.mostrar(grafo.getGrafo());
			break;
		}
		system("pause");
	} while (opcion != 4);
}