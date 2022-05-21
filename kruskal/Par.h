#pragma once
#include <iostream>
using namespace std;
template <class T>
class Par
{
private:
	Par<T>* sig;
	T elem;
	int peso;
public:
	Par(Par<T>* sig, T elem, int peso);
	~Par();
	Par* getSig();
	T getElem();
	int getPeso();
	void setSig(Par<T>* sig);
	void setElem(T elem);
	void setPeso(int peso);
};
template <class T>
Par<T>::Par(Par<T>* sig, T elem, int peso)
{
	this->sig = sig;
	this->elem = elem;
	this->peso = peso;
}
template <class T>
Par<T>::~Par()
{
}
template <class T>
Par<T>* Par<T>::getSig()
{
	return sig;
}

template <class T>
T Par<T>::getElem()
{
	return elem;
}
template <class T>
int Par<T>::getPeso()
{
	return peso;
}
template <class T>
void Par<T>::setSig(Par<T>* sig)
{
	this->sig = sig;
}
template <class T>
void Par<T>::setElem(T elem)
{
	this->elem = elem;
}
template <class T>
void Par<T>::setPeso(int peso)
{
	this->peso = peso;
}