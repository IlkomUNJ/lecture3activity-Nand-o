#include <string>
#include <vector>
#include <iostream>
#include "User.hpp"

using namespace std;

User::User(int id, string name, int bankAccountId)
{
    this->id = id;
    this->name = name;
    this->bankAccountId = bankAccountId;
}

int User::getId() const
{
    return id;
}

int User::getBankAccountId() const
{
    return bankAccountId;
}

Seller::Seller(int id, string name, int bankAccountId)
    : User(id, name, bankAccountId)
{
}

void Seller::tambahItem(const Item &newItem)
{
    stock.push_back(newItem);
}

void Seller::tampilkanStock()
{
    cout << "Stock for Seller ID: " << id << ", Name: " << name << endl;
    for (const auto &item : stock)
    {
        cout << "Item ID: " << item.id << ", Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << endl;
    }
}

Buyer::Buyer(int id, string name, int bankAccountId)
    : User(id, name, bankAccountId)
{
}

void Buyer::beliBarang(int itemId, int quantity, Seller &seller, Bank &bank)
{
    for (auto &item : seller.stock)
    {
        if (item.id == itemId)
        {
            if (item.quantity >= quantity)
            {
                double totalPrice = item.price * quantity;
                BankCustomer *buyerAccount = bank.cariCustomer(this->bankAccountId);
                BankCustomer *sellerAccount = bank.cariCustomer(seller.getBankAccountId());

                if (buyerAccount && sellerAccount)
                {
                    if (buyerAccount->saving >= totalPrice)
                    {
                        // Proses pembayaran
                        bank.transferUang(this->bankAccountId, seller.getBankAccountId(), totalPrice);

                        // Update stock
                        item.quantity -= quantity;

                        cout << "Purchase successful! Buyer ID: " << this->id << " bought " << quantity << " of Item ID: " << itemId << " from Seller ID: " << seller.getId() << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds in Buyer ID: " << this->id << "'s account." << endl;
                    }
                }
                else
                {
                    cout << "Bank account not found for either buyer or seller." << endl;
                }
            }
            else
            {
                cout << "Insufficient stock for Item ID: " << itemId << endl;
            }
            return; // Exit after processing the item
        }
    }
    cout << "Item ID: " << itemId << " not found in Seller ID: " << seller.getId() << "'s stock." << endl;
}
