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
