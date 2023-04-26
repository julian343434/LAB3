#include "list.cpp"

using namespace std;

int main(){
    List<string> list;
    list.insert(0, "Victor");
    list.insert(1, "Amanda");
    list.insert(2, "Ali");
    list.insert(3, "Primera");
    list.insert(4, "Jose");

    cout << "Imprimir: " << endl;
    list.print();

    cout << "Obteniendo algunos nodos" << endl;
    cout << list.get(0) << endl;
    cout << list.get(2) << endl;
    
    cout << "Borrando algunos nodos" << endl;
    list.erase(0);
    list.erase(3);
    list.print();

    cout << "Evaluando el tamanio" << endl;
    cout << "Tamanio: "<< list.size()<<endl;
    cout << "se busca un valor en la lista "<<endl;
    list.search("nuevo valor");

    cout << "Actualaiza una posicion de la lista"<<endl;
    list.update(0,"pollo frito");    
    cout<<list.get(2)<<endl;
    
    cout<<"Obtienen todos los elementos de la lista en un array"<<endl;
    vector<string> allElements = list.getAll();
    cout<<"imprime todos los elementos del vector asignado desde la lista"<<endl;
    for (int i = 0; i < allElements.size(); i++) {
        cout << allElements[i] << " "<<endl;
    }

    return 0;
}