#ifndef BANK_HPP
#define BANK_HPP

#include <string>
#include <vector>

struct BankCustomer
{
    int id;
    std::string name;
    double saving;

    BankCustomer(int id, std::string name, double saving);
};

struct Bank
{
    std::vector<BankCustomer> customers;

    void tampilkanCustomers();
    BankCustomer *cariCustomer(int customerId);

    void tambahCustomer(BankCustomer newCustomer);
    void hapusCustomer(int customerId);

    void cekSaldo(int customerId);

    void setorUang(int customerId, double amount);
    void tarikUang(int customerId, double amount);
    void transferUang(int fromCustomerId, int toCustomerId, double amount);
};

#endif // BANK_HPP
