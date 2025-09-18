#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

struct Item
{
    int id;
    std::string name;
    int quantity;
    double price;

    Item(int id, std::string name, int quantity, double price);

    void ChangeName(int id, std::string newName);
    void ChangePrice(int id, double newPrice);
    void ChangeQuantity(int id, int newQuantity);
};

#endif // ITEM_HPP
