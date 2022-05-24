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
void Grafo::inicializar(map<string, Nodo<string>>& grafo)
{
	map<string, Nodo<string>>::iterator it;
	for (it = grafo.begin(); it != grafo.end(); it++)
	{
		it->second.setMarca(false);
		it->second.setDistancia(9999);
		it->second.setPadre("#");
	}
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
void Grafo::insertarArista(map<string, Nodo<string>>& grafo,string origen, string destino, int distancia)
{
	grafo[origen].getLista()->insertarPrincipio(destino, distancia);
	grafo[destino].getLista()->insertarPrincipio(origen, distancia);
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
void Grafo::inicioKruskal(map<string, Nodo<string>>& grafo)
{
	map<string, Nodo<string>>::iterator it;
	for (it = grafo.begin(); it != grafo.end(); it++)
	{
		it->second.setMarca(false);
		it->second.setDistancia(9999);
		it->second.setPadre(it->first);
	}
}
map<string, Nodo<string>> Grafo::kruskal(map<string, Nodo<string>>& grafo,int &total)
{
	inicioKruskal(grafo);
	map<string, Nodo<string>> AE;
	Monticulo<int> colaP;
	Trio<int> trio;
	int A, cont, dist;
	string Vo, Vd;
	colaP = llenar(grafo, A);
	cont = 0;
	while (cont < A)
	{
		trio = colaP.sacar();
		Vo = buscarCiclo(trio.getOrigen());
		Vd = buscarCiclo(trio.getDestino());
		if (Vo != Vd)
		{
			AE[colaP.getOrigen()].getLista()->insertarPrincipio(colaP.getDestino(), colaP.getElem());
			total = total + colaP.getElem();
			grafo[Vo].setPadre(grafo[Vd].getPadre());
		}
		cont++;
	}
	return AE;
}
string Grafo::buscarCiclo(string x)
{
	string aux = x;
	while (aux != grafo[aux].getPadre())
	{
		aux = grafo[aux].getPadre();
	}
	return aux;
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