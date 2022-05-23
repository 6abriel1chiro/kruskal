#pragma once
#include "Nodo.h"
#include "Monticulo.h"
#include <map>
class Grafo
{
private:
	map<string, Nodo<string>> grafo;
public:
	Grafo();
	~Grafo();
	map<string, Nodo<string>>& getGrafo();
	Monticulo<int> llenar(map<string, Nodo<string>>& grafo, int& a);
	void leerArchivo(map<string, Nodo<string>>& grafo, string nom);
	string buscarCiclo(string x);
	map<string, Nodo<string>>& kruskal(map<string, Nodo<string>>& grafo, int& total);
	void mostrar(map<string, Nodo<string>> grafo);
};

