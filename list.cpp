    #include "list.h"
    
    template<typename T>
    List<T>:: List(): begin(0), count(0){}

    template<typename T>
    List<T>:: ~List(){
        Node<T>* del = begin;
        while(begin){
            begin = begin->next;
            delete del;
            del = begin;
        }    
    }

    template<typename T>
    void List<T>:: insert(int pos, const T& value){
        if(pos < 0 || pos > count){
            cout << "Error! La posicion esta fuera de rango."<<endl;
            return;
        }
        Node<T>* add = makeNode(value);
        if(pos == 0){
            add->next = begin;
            begin = add;
        }else{
            Node<T>* cur = begin;
            for(int i=1; i<pos; i++){
                cur = cur->next;
            }
            add->next = cur->next;
            cur->next = add;
        }
        count++;
    }

    template<typename T>
    void List<T>:: erase(int pos){
        if(pos < 0 || pos > count - 1){
            cout << "Error! La posicion esta fuera de rango."<<endl;
            return;
        }
        if(pos == 0){
            Node<T>* del = begin;
            begin = begin->next;
            delete del;
        }else{
            Node<T>* cur = begin;
            for(int i=0; i < pos -1; i++){
                cur = cur->next;
            }
            Node<T>* del = cur->next;
            cur->next = cur->next->next;
            delete del;
        }
        count--;
    }

    template<typename T>
    Node<T>* List<T>:: makeNode(const T& value){
        Node<T>* temp = new Node<T>;
        temp->data = value;
        temp->next = 0;
        return temp;
    }

    template<typename T>
    T& List<T>::get(int pos) const{
        if(pos < 0 || pos > count -1){
            cout << "Error en la posicion" << endl;
            assert(false);
        }else if(pos == 0){
            return begin->data;
        }else{
            Node<T>* cur = begin;
            for(int i=0; i < pos; i++){
                cur = cur->next;
            }
            return cur->data;   
        }
    }

    template<typename T>
    void List<T>:: print() const{
        if(count == 0){
            cout << "Lista vacia" << endl;
            return;
        }
        Node<T>* cur = begin;
        while(cur != 0){
            cout << cur->data << endl;
            cur = cur->next;
        }
    }

    template<typename T>
    int List<T>::size() const{
        return count;
    }

    //METODO SEARCH
    template<typename T>
    void List<T>::search(const T& value) {
        Node<T>* cur = begin;
        bool found = false;
        int index = 0;
        while (cur != 0) {
            if (cur->data == value) {
                found = true;
                break;
            }
            cur = cur->next;
            index++;
        }
        if (found) {
            cout << "El valor " << value << " esta en la lista en la posicion " << index << endl;
        } else {
            cout << "El valor " << value << " no esta en la lista" << endl;
        }
    }

    //METODO UPDATE
    template<typename T>
    void List<T>::update(int pos, const T& value) {
    if(pos < 0 || pos >= count){
        cout << "Error! La posicion esta fuera de rango." << endl;
        return;
    }
    Node<T>* cur = begin;
    for(int i=0; i < pos; i++){
        cur = cur->next;
    }
    cur->data = value;
    }

    //METODO GETALL
    template<typename T>
    vector<T> List<T>::getAll() const{
        vector<T> result;
        Node<T>* cur = begin;
        while(cur != 0){
            result.push_back(cur->data);
            cur = cur->next;
        }
        return result;
    }




