#include "bank.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

BankCustomer::BankCustomer(int id, string name, double saving)
{
    this->id = id;
    this->name = name;
    this->saving = saving;
};

void Bank::tampilkanCustomers()
{
    for (const auto &customer : customers)
    {
        cout << "ID: " << customer.id << ", Name: " << customer.name << ", Saving: " << customer.saving << endl;
    }
}

BankCustomer *Bank::cariCustomer(int customerId)
{
    for (auto &customer : customers)
    {
        if (customer.id == customerId)
        {
            return &customer;
        }
    }
    return nullptr;
}

void Bank::tambahCustomer(BankCustomer newCustomer)
{
    customers.push_back(newCustomer);
}

void Bank::hapusCustomer(int customerId)
{
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].id == customerId)
        {
            customers.erase(customers.begin() + i);
            cout << "Customer with ID " << customerId << " has been removed." << endl;
            return;
        }
    }
}

void Bank::cekSaldo(int customerId)
{
    BankCustomer *customer = cariCustomer(customerId);
    if (customer)
    {
        cout << "Customer ID: " << customer->id << ", Name: " << customer->name << ", Saving: " << customer->saving << endl;
    }
    else
    {
        cout << "Customer with ID " << customerId << " not found." << endl;
    }
}

void Bank::setorUang(int customerId, double amount)
{
    BankCustomer *customer = cariCustomer(customerId);
    if (customer)
    {
        customer->saving += amount;
        cout << "Successfully deposited " << amount << " to Customer ID: " << customer->id << ". New Saving: " << customer->saving << endl;
    }
    else
    {
        cout << "Customer with ID " << customerId << " not found." << endl;
    }
}

void Bank::tarikUang(int customerId, double amount)
{
    BankCustomer *customer = cariCustomer(customerId);
    if (customer)
    {
        if (customer->saving >= amount)
        {
            customer->saving -= amount;
            cout << "Successfully withdrew " << amount << " from Customer ID: " << customer->id << ". New Saving: " << customer->saving << endl;
        }
        else
        {
            cout << "Insufficient funds for Customer ID: " << customer->id << endl;
        }
    }
    else
    {
        cout << "Customer with ID " << customerId << " not found." << endl;
    }
}

void Bank::transferUang(int fromCustomerId, int toCustomerId, double amount)
{
    BankCustomer *fromCustomer = cariCustomer(fromCustomerId);
    BankCustomer *toCustomer = cariCustomer(toCustomerId);

    if (fromCustomer && toCustomer)
    {
        if (fromCustomer->saving >= amount)
        {
            fromCustomer->saving -= amount;
            toCustomer->saving += amount;
            cout << "Successfully transferred " << amount << " from Customer ID: " << fromCustomer->id << " to Customer ID: " << toCustomer->id << endl;
        }
        else
        {
            cout << "Insufficient funds for Customer ID: " << fromCustomer->id << endl;
        }
    }
    else
    {
        if (!fromCustomer)
            cout << "Sender Customer with ID " << fromCustomerId << " not found." << endl;
        if (!toCustomer)
            cout << "Receiver Customer with ID " << toCustomerId << " not found." << endl;
    }
}
