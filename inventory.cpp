#include "inventory.h"
#include "mainwindow.h"

template<typename T>
Inventory<T>::Inventory()
{
    this->capacity = 0;
    this->numItems = 0;
    this->itemArr = new T[2];
}

template<typename T>
Inventory<T>::~Inventory(){

}

template<typename T>
void Inventory<T>::addItem(T item){
    itemArr[numItems] = &item;
    numItems++;

}

/*void Inventory::removeItem(int index){

}

void Inventory::debugPrint(){

}*/

//int Inventory::getInfo(QString itemType){
//    emit updateIetm();
//}
