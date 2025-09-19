#include <bits/stdc++.h>
using namespace std;
class IDiscountable {
protected:
    virtual double applyDiscount(double rate) = 0; // pure virtual
};
class Product : public IDiscountable {
protected:
    string id;
    string name;
    double price;
    int stock;
public:
    Product(string _id, string _name, double _price, int _stock)
        : id(_id), name(_name), price(_price), stock(_stock) {}
    Product() : id(""), name(""), price(0), stock(0) {}
    string getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStock() { return stock; }
    void setPrice(double _price) { price = _price; }
    void setStock(int _stock) { stock = _stock; }
    void setId(string _id) { id = _id; }
    void setName(string _name) { name = _name; }
    virtual void display() {
        cout << "Product: " << name << " | Price: " << price
             << " | Stock: " << stock << endl;
    }
    double applyDiscount(double rate) {
        price = price - (price * rate);
        return price;
    }
    bool operator==(Product &other) {
        return this->id == other.id;
    }
};
class Electronics : public Product {
private:
    int warrantyMonths;
public:
    Electronics(string _id, string _name, double _price, int _stock, int _warranty)
        : Product(_id, _name, _price, _stock), warrantyMonths(_warranty) {}

    Electronics() : Product("", "", 0, 0), warrantyMonths(0) {}

    int getWarranty() { return warrantyMonths; }
    void setWarranty(int _months) { warrantyMonths = _months; }

    void display() {
        cout << "Electronics: " << name << " | Price: " << price
             << " | Stock: " << stock
             << " | Warranty: " << warrantyMonths << " months" << endl;
    }
};
template <typename T>
class InventoryList {
private:
    vector<T> items;
public:
    void addItem(T item) {
        items.push_back(item);
    }
    void showAll() {
        for (size_t i = 0; i < items.size(); i++) {
            items[i].display();
        }
    }
    vector<T>& getItems() { return items; }
};
struct CartItem {
    Product* product;
    int quantity;
};

class ShoppingCart {
private:
    vector<CartItem> cartItems;
public:
    void addToCart(Product* p, int qty) {
        if (p->getStock() >= qty) {
            p->setStock(p->getStock() - qty); // tr? kho
            bool found = false;
            for (size_t i = 0; i < cartItems.size(); i++) {
                if (cartItems[i].product == p) {
                    cartItems[i].quantity += qty;
                    found = true;
                    break;
                }
            }
            if (!found) {
                CartItem ci = {p, qty};
                cartItems.push_back(ci);
            }
            cout << "Added " << qty << " x " << p->getName() << " to cart." << endl;
        } else {
            cout << "Not enough stock! Available: " << p->getStock() << endl;
        }
    }

    void showCart() {
        cout << "=== Cart Contents ===" << endl;
        double total = 0;
        for (size_t i = 0; i < cartItems.size(); i++) {
            Product* p = cartItems[i].product;
            int qty = cartItems[i].quantity;
            double line = p->getPrice() * qty;
            cout << qty << " x ";
            p->display();
            total += line;
        }
        cout << "Total Price: " << total << endl;
    }
};
int main() {
    InventoryList<Product> inventory;
    ShoppingCart cart;

    int choice;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Add Electronics" << endl;
        cout << "3. Show Inventory" << endl;
        cout << "4. Add Item to Cart" << endl;
        cout << "5. Show Cart" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            string id, name;
            double price;
            int stock;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Stock: ";
            cin >> stock;
            Product p(id, name, price, stock);
            inventory.addItem(p);
        }
        else if (choice == 2) {
            string id, name;
            double price;
            int stock, warranty;
            cout << "Enter Electronics ID: ";
            cin >> id;
            cout << "Enter Electronics Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Stock: ";
            cin >> stock;
            cout << "Enter Warranty (months): ";
            cin >> warranty;
            Electronics e(id, name, price, stock, warranty);
            inventory.addItem(e);
        }
        else if (choice == 3) {
            cout << "\n=== Inventory ===" << endl;
            inventory.showAll();
        }
        else if (choice == 4) {
            string pid;
            int qty;
            cout << "Enter Product ID to add to cart: ";
            cin >> pid;
            cout << "Enter quantity: ";
            cin >> qty;
            vector<Product>& items = inventory.getItems();
            bool found = false;
            for (size_t i = 0; i < items.size(); i++) {
                if (items[i].getId() == pid) {
                    cart.addToCart(&items[i], qty);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found in inventory." << endl;
            }
        }
        else if (choice == 5) {
            cart.showCart();
        }
    } while (choice != 0);

    return 0;
}

