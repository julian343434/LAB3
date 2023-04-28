#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Cola {
private:
    vector<T> elementos;

public:
    Cola();
    void agregar(const T& elemento);
    T quitar();
    T& frente();
    bool estaVacia() const;
    int tamano() const;
    void imprimir() const;
};

template<typename T>
Cola<T>::Cola() {}

template<typename T>
void Cola<T>::agregar(const T& elemento) {
    elementos.push_back(elemento);
}

template<typename T>
T Cola<T>::quitar() {
    if (elementos.empty()) {
        throw runtime_error("La cola esta vacia");
    }
    T resultado = elementos.front();
    elementos.erase(elementos.begin());
    return resultado;
}

template<typename T>
T& Cola<T>::frente() {
    if (elementos.empty()) {
        throw runtime_error("La cola esta vacia");
    }
    return elementos.front();
}

template<typename T>
bool Cola<T>::estaVacia() const {
    return elementos.empty();
}

template<typename T>
int Cola<T>::tamano() const {
    return elementos.size();
}

template<typename T>
void Cola<T>::imprimir() const {
    if (elementos.empty()) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "Contenido de la cola:" << endl;
        for (const T& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

#endif // COLA_H
