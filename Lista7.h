#pragma once
#include "Par.h"
template <class T>
class Lista7
{
private:
	Par<T>* primer;
	Par<T>* ultimo;
public:
	Lista7();
	~Lista7();
	Par<T>* getPrimer();
	Par<T>* getUltimo();
	void setPrimer(Par<T>* primer);
	void setUltimo(Par<T>* ultimo);
	void insertarPrincipio(T elemento, int peso);
	bool eliminarPrincipio();
	void insertarFinal(T elemento);
	bool eliminarFinal();
	void mostrarLista();
	bool BuscarNoRec(T elementoBuscar);
	T BuscarPos(int posBuscar);
	bool eliminarElementoDado(T elemento);
	T sacarSiguienteAdyacente(T ienisima);
	bool estaVacio();
};
template <class T>
Lista7<T>::Lista7()
{
	primer = NULL;
	ultimo = NULL;
}

template <class T>
Lista7<T>::~Lista7()
{
}

template <class T>
Par<T>* Lista7<T>::getPrimer()
{
	return primer;
}

template <class T>
Par<T>* Lista7<T>::getUltimo()
{
	return ultimo;
}

template <class T>
void Lista7<T>::setPrimer(Par<T>* primer)
{
	this->primer = primer;
}

template <class T>
void Lista7<T>::setUltimo(Par<T>* ultimo)
{
	this->ultimo = ultimo;
}



template <class T>
void Lista7<T>::insertarPrincipio(T elemento, int peso)
{
	if (primer == NULL)
	{
		primer = new Par<T>(NULL, elemento, peso);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(primer, elemento, peso);
		primer = aux;
	}
}

template <class T>
bool Lista7<T>::eliminarPrincipio()
{
	bool res;
	if (primer == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (primer == ultimo) //Solo uno
		{
			delete primer;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Par<T>* aux;
			aux = primer->getSig();
			delete primer;
			primer = aux;
		}
	}
	return res;
}

template <class T>
void Lista7<T>::insertarFinal(T elemento)
{
	if (ultimo == NULL)
	{
		primer = new Par<T>(NULL, elemento);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(NULL, elemento);
		ultimo->setSig(aux);
		ultimo = aux;
	}
}

template <class T>
bool Lista7<T>::eliminarFinal()
{
	bool res;
	if (primer == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (primer == ultimo) //Solo uno
		{
			delete primer;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Par<T>* aux = primer;
			while (aux->getSig()->getSig() != NULL)
			{
				aux = aux->getSig();
			}
			delete ultimo;
			ultimo = aux;
			ultimo->setSig(NULL);
		}
	}
	return res;
}

template <class T>
void Lista7<T>::mostrarLista()
{
	if (primer == NULL)
	{
		cout << "Lista Vacia" << endl;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			cout << aux->getElem();
			cout << ":" << aux->getPeso() << " ";
			if (aux->getSig() != NULL)
			{
				cout << "; ";
			}
			aux = aux->getSig();
		}
		cout << endl;
	}
}

template <class T>
bool Lista7<T>::BuscarNoRec(T elementoBuscar)
{
	bool encontro;
	if (primer == NULL)
	{
		encontro = false;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			if (elementoBuscar == aux->getElem())
			{
				encontro = true;
				return encontro;
			}
			else
			{
				encontro = false;
			}
			aux = aux->getSig();
		}
	}
	return encontro;
}

template <class T>
T Lista7<T>::BuscarPos(int posBuscar)
{
	T encontro;
	int pos = 0;
	if (primer == NULL)
	{
		encontro = NULL;
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			if (posBuscar == pos)
			{
				encontro = aux->getElem();
				return encontro;
			}
			else
			{
				encontro = NULL;
			}
			aux = aux->getSig();
			pos++;
		}
	}
	return encontro;
}

template <class T>
bool Lista7<T>::eliminarElementoDado(T elemento)
{
	bool funciono = false;
	if (primer == NULL)
	{
		funciono = false;
	}
	else
	{
		if (primer->getElem() == elemento)
		{
			funciono = eliminarPrincipio();
		}
		else if (ultimo->getElem() == elemento)
		{
			funciono = eliminarFinal();
		}
		else
		{
			Par<T>* aux = primer;
			while (aux->getSig()->getElem() != elemento && aux->getSig() != ultimo)
			{
				aux = aux->getSig();
			}
			if (aux->getSig() == ultimo && aux->getSig()->getElem() == elemento)
			{
				delete aux->getSig();
				ultimo = aux;
				ultimo->setElem(NULL);
				funciono = true;
			}
			else
			{
				if (aux->getSig()->getElem() == elemento)
				{
					Par<T>* ayuda = aux->getSig()->getSig();
					delete aux->getSig();
					aux->setSig(ayuda);
					funciono = true;
				}
			}
		}
	}
	return funciono;
}
template<class T>
T Lista7<T>::sacarSiguienteAdyacente(T ienisima)
{
	bool bandera = false;
	int indice = 1;
	T elemento;
	Par<T>* aux;
	aux = primer;

	while (aux != NULL)
	{
		if (indice == ienisima)
		{
			elemento = aux->getElem();
			bandera = true;
			aux = NULL;
		}
		else
		{
			indice++;
			aux = aux->getSig();
		}
	}
	if (bandera == false)
	{
		elemento = NULL;
	}
	return elemento;
}
template<class T>
bool Lista7<T>::estaVacio()
{
	bool res;
	if (primer == NULL && ultimo == NULL)
	{
		res = true;
	}
	else
	{
		res = false;
	}
	return res;
}