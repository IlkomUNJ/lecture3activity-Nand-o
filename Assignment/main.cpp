#include <iostream>
#include "item.hpp"
#include "Bank.hpp"
#include "User.hpp"

using namespace std;

int main() {

    Bank bankMandiri;

    BankCustomer nasabah1(101, "Nando", 10000.0);
    BankCustomer nasabah2(202, "Candra", 50000.0);
    bankMandiri.tambahCustomer(nasabah1);
    bankMandiri.tambahCustomer(nasabah2);
    
    cout << "\nNasabah Awal di Bank:" << endl;
    bankMandiri.tampilkanCustomers();

    Seller seller(1, "Nando", 101);
    Buyer buyer(2, "Candra", 202);

    seller.tambahItem(Item(1, "Mie Ayam Hello Kitty", 5, 15000.0));
    seller.tambahItem(Item(2, "Teh Solo", 3, 5000.0));
    
    cout << "\nStock barang Nando (Seller) awal:" << endl;
    seller.tampilkanStock();
    
    cout << "\nMencoba Mengganti nama item dengan ID 2 menjadi Teh Botol." << endl;
    for (auto &item : seller.stock) {
        item.ChangeName(2, "Teh Botol");
    }

    cout << "\nMencoba Mengganti harga item dengan ID 2 menjadi 4000." << endl;
    for (auto &item : seller.stock) {
        item.ChangePrice(2, 4000.0);
    }

    cout << "\nMencoba Mengganti kuantitas item dengan ID 2 menjadi 5." << endl;
    for (auto &item : seller.stock) {
        item.ChangeQuantity(2, 5);
    }

    cout << "\nStock barang Nando (Seller) setelah perubahan:" << endl;
    seller.tampilkanStock();

    cout << "\nSaldo sebelum transaksi:" << endl;
    bankMandiri.cekSaldo(seller.getBankAccountId());
    bankMandiri.cekSaldo(buyer.getBankAccountId());
    cout << "--------------------------------\n" << endl;

    cout << "\n>> Skenario 1: Candra (Buyer) membeli 1 Mie Ayam Hello Kitty" << endl;
    buyer.beliBarang(1, 1, seller, bankMandiri);

    cout << "\n>> Skenario 2: Candra (Buyer) mencoba membeli 10 Teh Botol" << endl;
    buyer.beliBarang(2, 10, seller, bankMandiri);

    cout << "\n>> Skenario 3: Candra (Buyer) mencoba membeli 2 Teh Botol" << endl;
    buyer.beliBarang(2, 2, seller, bankMandiri);

    cout << "--------------------------------\n" << endl;
    // Tampilkan kondisi akhir
    seller.tampilkanStock();
    cout << "\nSaldo setelah transaksi:" << endl;
    bankMandiri.cekSaldo(seller.getBankAccountId());
    bankMandiri.cekSaldo(buyer.getBankAccountId());

    return 0;
}
