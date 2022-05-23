#pragma once
#include "Lista7.h"
template <class T>
class Nodo
{
private:
	string padre;
	Lista7<T>* lista;
public:
	Nodo();
	~Nodo();
	string getPadre();
	Lista7<T>* getLista();
	void setPadre(string padre);
	void setLista(Lista7<T>* lista);
};
template <class T>
Nodo<T>::Nodo()
{
	this->lista = new Lista7<T>();
	this->padre = "#";
}
template <class T>
Nodo<T>::~Nodo()
{
	delete lista;
}
template <class T>
string Nodo<T>::getPadre()
{
	return padre;
}
template <class T>
Lista7<T>* Nodo<T>::getLista()
{
	return lista;
}
template <class T>
void Nodo<T>::setPadre(string padre)
{
	this->padre = padre;
}
template <class T>
void Nodo<T>::setLista(Lista7<T>* lista)
{
	this->lista = lista;
}