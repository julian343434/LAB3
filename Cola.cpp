#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Cola {
private:
    vector<T> elementos;

public:
    Cola() {}

    void agregar(const T& elemento) {
        elementos.push_back(elemento);
    }

    T quitar() {
        if (elementos.empty()) {
            throw runtime_error("La cola esta vacia");
        }
        T resultado = elementos.front();
        elementos.erase(elementos.begin());
        return resultado;
    }

    T& frente() {
        if (elementos.empty()) {
            throw runtime_error("La cola esta vacia");
        }
        return elementos.front();
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    int tamano() const {
        return elementos.size();
    }

    void imprimir() const {
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
};
