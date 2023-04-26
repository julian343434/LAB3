#ifndef LIST_H
#define LIST_H
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
};

template<typename T>
class List{
private:
    Node<T>* begin;
    int count;
    Node<T>* makeNode(const T& value);
public:
    List();
    ~List();
    void insert(int pos, const T& value);
    void erase(int pos);
    T& get(int pos) const;
    void print() const;
    int size() const;
    void search(const T& value);
    void update(int pos , const T& value);
    vector<T> getAll() const;
};

#endif