#include "Grafo.h"
int main()
{
	Grafo<string> grafo;
	string origen, destino;
	int opcion;
	do
	{
		system("cls");
		cout << "Menu de Opciones" << endl;
		cout << "1 Insertar Archivo" << endl;
		cout << "2 Dijkstra" << endl;
		cout << "3 Mostrar" << endl;
		cout << "4 Salir" << endl;
		cout << " Escoja la opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			grafo.llenarGrafo(grafo.getGrafo(), "num.txt");
			grafo.mostrar(grafo.getGrafo());
			system("pause");
			break;
		case 2:
			cout << "Ingrese un origen: ";
			cin >> origen;
			grafo.busqueda(grafo.getGrafo(), origen);
			break;
		case 3:
			grafo.mostrar(grafo.getGrafo());
			break;
		}
		system("pause");
	} while (opcion != 4);
}

