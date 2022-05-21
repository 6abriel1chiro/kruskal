#pragma once
#include "NodoMonticulo.h"
#include <fstream>
#include <list>
#define TAM 10000
template <class T>
class Monticulo
{
private:
	NodoMonticulo<T> array[TAM];
	int ultimo;
	int posMayor;
	list<int> lista;
public:
	Monticulo();
	~Monticulo();
	void recuperarAbajoArriba(int pos);
	void recuperarArribaAbajo(int pos);
	void insertar(T elem, int pos);
	bool eliminar();
	void poner(T elem, string ori);
	T buscarMenor();
	string buscarOrigen();
	bool vacio();
};
template <class T>
Monticulo<T>::Monticulo<T>() {
	for (int i = 0; i < TAM; i += 1) {
		array[i] = NodoMonticulo<T>();
	}
	ultimo = -1;
}
template <class T>
Monticulo<T>::~Monticulo() {

}
template <class T>
void Monticulo<T>::recuperarAbajoArriba(int pos) {
	T aux;
	if (array[pos / 2].getPresente())
	{
		if (array[pos].getElem() < array[pos / 2].getElem())
		{
			swap(array[pos], array[pos / 2]);
		}
	}
}
template <class T>
void Monticulo<T>::recuperarArribaAbajo(int pos)
{
	int posMayor;
	if (array[pos * 2].getPresente() && array[pos * 2 + 1].getPresente())
	{
		if (array[pos * 2].getElem() > array[pos * 2 + 1].getElem())
		{
			posMayor = pos * 2;
		}
		else
		{
			posMayor = pos * 2 + 1;
		}
		if (array[posMayor].getElem() > array[pos].getElem())
		{
			T aux;
			aux = array[posMayor].getElem();
			array[posMayor].setElem(array[pos].getElem());
			array[pos].setElem(aux);
			recuperarArribaAbajo(posMayor);
		}
	}
	else
	{
		if (array[pos * 2].getPresente())
		{
			if (array[pos * 2].getElem() > array[pos].getElem())
			{
				T aux;
				aux = array[pos].getElem();
				array[pos].setElem(array[pos * 2].getElem());
				array[pos * 2].setElem(aux);
				recuperarArribaAbajo(pos * 2);
			}
		}
	}
}
template <class T>
void Monticulo<T>::insertar(T elem, int pos)
{
	if (array[pos].getPresente() == false)
	{
		ultimo = 1;
		array[ultimo].setElem(elem);
		array[ultimo].setPresente(true);
	}
	else
	{
		ultimo += 1;
		array[ultimo].setElem(elem);
		array[ultimo].setPresente(true);
		recuperarAbajoArriba(ultimo);
	}
}
template <class T>
bool Monticulo<T>::eliminar()
{
	int pos = 1;
	bool esta = true;
	T mayor;
	if (array[pos].getPresente() == false)
	{
		esta = false;
	}
	else
	{
		mayor = array[1].getElem();
		array[1].setElem(array[ultimo].getElem());
		array[ultimo].setPresente(false);
		ultimo -= 1;
		recuperarArribaAbajo(1);
	}
	return esta;
}

template <class T>
void Monticulo<T>::poner(T elem, string ori)
{
	if (array[1].getPresente() == false)
	{
		ultimo = 1;
		array[ultimo].poner(elem, ori);
	}
	else
	{
		ultimo = ultimo + 1;
		array[ultimo].poner(elem, ori);
		recuperarAbajoArriba(ultimo);
	}
}
template <class T>
bool Monticulo<T>::vacio()
{
	bool res = true;
	if (array[1].getPresente() == false) res = false;
	return res;
}
template <class T>
T Monticulo<T>::buscarMenor()
{
	return array[1].getElem();
}
template <class T>
string Monticulo<T>::buscarOrigen()
{
	return array[1].getVert();
}