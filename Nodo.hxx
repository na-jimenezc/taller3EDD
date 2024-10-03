#include "Nodo.h"

// Constructor sin parámetros
template<class T>
Nodo<T>::Nodo() : hijoIzq(nullptr), hijoDer(nullptr), altura(0) {}

// Constructor cuando recibe un valor tipo T
template<class T>
Nodo<T>::Nodo(T val) : dato(val), hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

// Destructor
template<class T>
Nodo<T>::~Nodo() {
    // Eliminación automática de hijos en el destructor
    delete hijoIzq;
    delete hijoDer;
}

// Métodos de acceso
template<class T>
T& Nodo<T>::obtenerDato() {
    return dato;
}

template<class T>
void Nodo<T>::fijarDato(const T& val) {
    dato = val;
}

template<class T>
Nodo<T>* Nodo<T>::obtenerHijoIzq() const {
    return hijoIzq;
}

template<class T>
void Nodo<T>::fijarHijoIzq(Nodo<T>* hijo) {
    hijoIzq = hijo;
}

template<class T>
Nodo<T>* Nodo<T>::obtenerHijoDer() const {
    return hijoDer;
}

template<class T>
void Nodo<T>::fijarHijoDer(Nodo<T>* hijo) {
    hijoDer = hijo;
}

template<class T>
int Nodo<T>::obtenerAltura() const {
    return altura;
}

template<class T>
void Nodo<T>::fijarAltura(int nuevaAltura) {
    altura = nuevaAltura;
}

