#pragma once
#include "Lista7.h"
template <class T>
class Nodo
{
private:
	string padre;
	bool marca;
	int distancia;
	Lista7<T>* lista;
public:
	Nodo();
	~Nodo();
	void mostrar();
	string getPadre();
	bool getMarca();
	int getDistancia();
	Lista7<T>* getLista();
	void setPadre(string padre);
	void setMarca(bool marca);
	void setLista(Lista7<string>* lista);
	void setDistancia(int distancia);
};
template <class T>
Nodo<T>::Nodo()
{
	lista = new Lista7<T>();
	padre = "#";
	distancia = 9999;
	marca = false;
}

template <class T>
Nodo<T>::~Nodo()
{
}
template <class T>
void Nodo<T>::mostrar()
{
	if (lista != NULL)
	{
		lista->mostrarLista();
	}
}
template <class T>
string Nodo<T>::getPadre()
{
	return padre;
}
template <class T>
bool Nodo<T>::getMarca()
{
	return marca;
}
template <class T>
Lista7<T>* Nodo<T>::getLista()
{
	return lista;
}
template <class T>
int Nodo<T>::getDistancia()
{
	return distancia;
}
template <class T>
void Nodo<T>::setPadre(string padre)
{
	this->padre = padre;
}
template <class T>
void Nodo<T>::setMarca(bool marca)
{
	this->marca = marca;
}
template <class T>
void Nodo<T>::setLista(Lista7<string>* lista)
{
	this->lista = lista;
}
template <class T>
void Nodo<T>::setDistancia(int distancia)
{
	this->distancia = distancia;
}
