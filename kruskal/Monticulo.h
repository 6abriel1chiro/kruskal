#pragma once
#include "Trio.h"
#include <fstream>
#define TAM 100
template <class T>
class Monticulo
{
private:
	Trio<T> arr[TAM];
	int ultimo;
public:
	Monticulo();
	~Monticulo();
	void poner(T elem, string origen, string destino);
	void recuperarAbajoArriba(int pos);
	void recuperarArribaAbajo(int pos);
	T getElem();
	string getOrigen();
	string getDestino();
	void eliminar();
	bool vacio();

};
template <class T>
Monticulo<T>::Monticulo()
{
	for (int pos = 0; pos < TAM; pos += 1)
	{
		arr[pos] = Trio<T>();
	}
	ultimo = -1;
}
template <class T>
void Monticulo<T>::recuperarAbajoArriba(int pos) 
{
	T aux;
	if (arr[pos / 2].getPresente())
	{
		if (arr[pos].getElem() < arr[pos / 2].getElem())
		{
			swap(arr[pos], arr[pos / 2]);
		}
	}
}
template <class T>
Monticulo<T>::~Monticulo()
{
	
}
template <class T>
void Monticulo<T>::poner(T elem, string origen, string destino)
{
	if (arr[1].getPresente() == false)
	{
		ultimo = 1;
		arr[ultimo].setElem(elem);
		arr[ultimo].setOrigen(origen);
		arr[ultimo].setDestino(destino);
		arr[ultimo].setPresente(true);
	}
	else
	{
		ultimo += 1;
		arr[ultimo].setElem(elem);
		arr[ultimo].setOrigen(origen);
		arr[ultimo].setDestino(destino);
		arr[ultimo].setPresente(true);
		recuperarAbajoArriba(ultimo);
	}
}
template <class T>
bool Monticulo<T>::vacio()
{
	return arr[1].getPresente() == true;
}
template <class T>
T  Monticulo<T>::getElem()
{
	return arr[1].getElem();
}
template <class T>
string Monticulo<T>::getOrigen()
{
	return arr[1].getOrigen();
}
template <class T>
string Monticulo<T>::getDestino()
{
	return arr[1].getDestino();
}
template <class T>
void Monticulo<T>::recuperarArribaAbajo(int pos)
{
	int posMayor;
	if (arr[pos * 2].getPresente() && arr[pos * 2 + 1].getPresente())
	{
		if (arr[pos * 2].getElem() > arr[pos * 2 + 1].getElem())
		{
			posMayor = pos * 2;
		}
		else
		{
			posMayor = pos * 2 + 1;
		}
		if (arr[posMayor].getElem() > arr[pos].getElem())
		{
			T aux;
			aux = arr[posMayor].getElem();
			arr[posMayor].setElem(arr[pos].getElem());
			arr[pos].setElem(aux);
			recuperarArribaAbajo(posMayor);
		}
	}
	else
	{
		if (arr[pos * 2].getPresente())
		{
			if (arr[pos * 2].getElem() > arr[pos].getElem())
			{
				T aux;
				aux = arr[pos].getElem();
				arr[pos].setElem(arr[pos * 2].getElem());
				arr[pos * 2].setElem(aux);
				recuperarArribaAbajo(pos * 2);
			}
		}
	}
}
template <class T>
void Monticulo<T>::eliminar()
{
	int pos = 1;
	bool esta = true;
	T mayor;
	if (arr[pos].getPresente() == false)
	{
		esta = false;
	}
	else
	{
		mayor = arr[1].getElem();
		arr[1].setElem(arr[ultimo].getElem());
		arr[ultimo].setPresente(false);
		ultimo -= 1;
		recuperarArribaAbajo(1);
	}
}
