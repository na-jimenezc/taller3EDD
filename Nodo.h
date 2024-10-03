#ifndef NODO_H
#define NODO_H

template<class T>
class Nodo {
private:
    T dato; // Dato almacenado en el nodo
    Nodo* hijoIzq; // Puntero al hijo izquierdo
    Nodo* hijoDer; // Puntero al hijo derecho
    int altura; // Altura del nodo

public:
    // Constructor sin parámetros
    Nodo();

    // Constructor que recibe un valor tipo T
    Nodo(T val);

    // Destructor
    ~Nodo();

    // Métodos de acceso
    T& obtenerDato(); // Devuelve el dato almacenado
    void fijarDato(const T& val); // Establece el dato almacenado

    Nodo* obtenerHijoIzq() const; // Devuelve el hijo izquierdo
    void fijarHijoIzq(Nodo* hijo); // Establece el hijo izquierdo

    Nodo* obtenerHijoDer() const; // Devuelve el hijo derecho
    void fijarHijoDer(Nodo* hijo); // Establece el hijo derecho

    int obtenerAltura() const; // Devuelve la altura del nodo
    void fijarAltura(int nuevaAltura); // Establece la altura del nodo
};

#include "Nodo.hxx" // Incluir la implementación

#endif // NODO_H

