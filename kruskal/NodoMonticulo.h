#pragma once
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class NodoMonticulo
{
private:
	T elem;
	bool presente;
	string vert;
public:
	NodoMonticulo();
	~NodoMonticulo();
	T getElem();
	bool getPresente();
	void poner(T elem, string vert);
	string getVert();
	void setVert(string vert);
	void setElem(T elem);
	void setPresente(bool presente);
};
template <class T>
NodoMonticulo<T>::NodoMonticulo<T>() {
	this->presente = false;
}
template <class T>
NodoMonticulo<T>::~NodoMonticulo() {

}
template <class T>
void NodoMonticulo<T>::poner(T elem, string vert)
{
	this->elem = elem;
	this->vert = vert;
	presente = true;
}
template <class T>
T NodoMonticulo<T>::getElem() {
	return elem;
}
template <class T>
bool NodoMonticulo<T>::getPresente() {
	return presente;
}
template <class T>
void NodoMonticulo<T>::setElem(T elem) {
	this->elem = elem;
}
template <class T>
void NodoMonticulo<T>::setPresente(bool presente) {
	this->presente = presente;
}
template <class T>
string NodoMonticulo<T>::getVert()
{
	return vert;
}
template <class T>
void NodoMonticulo<T>::setVert(string vert)
{
	this->vert = vert;
}