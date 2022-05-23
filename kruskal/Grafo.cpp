#include "Grafo.h"
Grafo::Grafo()
{
	
}
Grafo::~Grafo()
{

}
map<string, Nodo<string>>& Grafo::getGrafo()
{
	return grafo;
}
void Grafo::leerArchivo(map<string, Nodo<string>>& grafo, string nom)
{
	ifstream arch;
	string dato1, dato2;
	int dato3;
	arch.open(nom);
	while (!arch.eof())
	{
		arch >> dato1;
		arch >> dato2;
		arch >> dato3;
		grafo[dato1].getLista()->insertarPrincipio(dato2, dato3);
		grafo[dato2].getLista()->insertarPrincipio(dato1, dato3);
	}
	arch.close();
}
Monticulo<int> Grafo::llenar(map<string, Nodo<string>>& grafo, int& a)
{
	Monticulo<int> colaP;
	a = 0;
	Par<string>* aux;
	map<string, Nodo<string>> ::iterator it;
	for (it = grafo.begin(); it != grafo.end(); it++)
	{
		aux = it->second.getLista()->getPrimer();
		while (aux != NULL)
		{
			colaP.poner(aux->getPeso(), it->first, aux->getElem());
			a += 1;
			aux = aux->getSig();
		}
	}
	return colaP;
}
map<string, Nodo<string>>& Grafo::kruskal(map<string, Nodo<string>>& grafo, int& total)
{
	map<string, Nodo<string>> AE;
	Monticulo<int> ColaP;
	int a, cont = 0;
	ColaP = llenar(grafo,a);
	while (cont < a)
	{
		ColaP.poner(ColaP.getElem(), ColaP.getOrigen(), ColaP.getDestino());
		ColaP.eliminar();
		string Vo = buscarCiclo(ColaP.getOrigen());
		string Vd = buscarCiclo(ColaP.getDestino());
		if (Vo != Vd)
		{
			AE[ColaP.getOrigen()].getLista()->insertarPrincipio(ColaP.getDestino(), ColaP.getElem());
			total = total + ColaP.getElem();
			grafo[Vo].setPadre(grafo[Vd].getPadre());
		}
		cont += 1;
	}
	return AE;
}
string Grafo::buscarCiclo(string x)
{
	while (x != grafo[x].getPadre())
	{
		x = grafo[x].getPadre();
	}
	return x;
}
void Grafo::mostrar(map<string, Nodo<string>> grafo)
{
	map<string, Nodo<string>>::iterator it;
	for (it = grafo.begin(); it != grafo.end(); ++it)
	{
		cout << it->second.getPadre() << " ";
		cout << it->first << " => ";
		it->second.getLista()->mostrarLista();
	}
}