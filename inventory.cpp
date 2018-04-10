#include "inventory.h"
#include "mainwindow.h"

Inventory::Inventory()
{
    this->capacity = 0;
    this->numItems = 0;
//    this->itemArr = new Item*[capacity];
}

Inventory::~Inventory(){

}

void Inventory::addItem(Item item){
    items[numItems++] = &item;

}

void Inventory::removeItem(int index){

}

void Inventory::debugPrint(){

}

//int Inventory::getInfo(QString itemType){
//    emit updateIetm();
//}
