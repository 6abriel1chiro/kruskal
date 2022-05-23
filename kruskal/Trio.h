#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class Trio
{
private:
	T elem;
	bool presente;
	string origen;
	string destino;
public:
	Trio();
	~Trio();
	T getElem();
	bool getPresente();
	string getOrigen();
	string getDestino();
	void setElem(T elem);
	void setPresente(bool presente);
	void setOrigen(string origen);
	void setDestino(string destino);
};
template <class T>
Trio<T>::Trio()
{
	presente = false;
	origen = " ";
	destino = " ";
}
template <class T>
Trio<T>::~Trio()
{

}
template <class T>
T Trio<T>::getElem()
{
	return elem;
}
template <class T>
bool Trio<T>::getPresente()
{
	return presente;
}
template <class T>
string Trio<T>::getOrigen()
{
	return origen;
}
template <class T>
string Trio<T>::getDestino()
{
	return destino;
}
template <class T>
void Trio<T>::setElem(T elem)
{
	this->elem = elem;
}
template <class T>
void Trio<T>::setPresente(bool presente)
{
	this->presente = presente;
}
template <class T>
void Trio<T>::setOrigen(string origen)
{
	this->origen = origen;
}
template <class T>
void Trio<T>::setDestino(string destino)
{
	this->destino = destino;
}