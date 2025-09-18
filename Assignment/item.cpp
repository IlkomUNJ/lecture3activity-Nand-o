// Disini gunanya buat implementasi dari class Item yang ada di item.hpp,
// kek cara ngerakitnya ke dalem class

#include "item.hpp"

Item::Item(int id, std::string name, int quantity, double price)
{
    this->id = id;
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

void Item::ChangeName(int id, std::string newName)
{
    if (this->id == id)
    {
        this->name = newName;
    }
}

void Item::ChangePrice(int id, double newPrice)
{
    if (this->id == id)
    {
        this->price = newPrice;
    }
}

void Item::ChangeQuantity(int id, int newQuantity)
{
    if (this->id == id)
    {
        this->quantity = newQuantity;
    }
}
