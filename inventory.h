#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

template <class T>
class Inventory {
private:
    int numItems;
    int capacity;

public:
    Inventory();
    ~Inventory();
    T addItem(T item);
    std::vector<T> items;
};

template <class T>
Inventory<T>::Inventory(){
    this->numItems = 0;
    this->capacity = 0;
}

template <class T>
Inventory<T>::~Inventory(){

}

template <class T>
T Inventory<T>::addItem(T item){
    this->items.push_back(item);
    this->numItems++;
    return items[0];
}
#endif // INVENTORY_H
