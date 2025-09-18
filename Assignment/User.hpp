#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Bank.hpp"
#include "item.hpp"

class User
{
protected:
    int id;
    std::string name;
    int bankAccountId;

public:
    User(int id, std::string name, int bankAccountId);
    int getId() const;
    int getBankAccountId() const;
};

class Seller : public User
{
public:
    std::vector<Item> stock;

    Seller(int id, std::string name, int bankAccountId);

    void tambahItem(const Item &newItem);
    void tampilkanStock();
};

class Buyer : public User
{
public:
    Buyer(int id, std::string name, int bankAccountId);

    void beliBarang(int itemId, int quantity, Seller &seller, Bank &bank);
};

#endif // USER_HPP
