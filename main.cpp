// E-Commerce System Task
// This program simulates a simple e-commerce system with products, customers, and a shopping cart.
#include <iostream>
#include <vector>
using namespace std;

// base class
class Product {
private:
  int quantity;
  string name;
  double price;
  int weight;
  bool expire;
  bool shippable;

public:
  // Constructor with default values
  Product(int q, string n = "name", double p = 0.00, int w = 0, bool e = false, bool s = false) {
    name = n;
    price = p;
    quantity = q;
    weight = w;
    expire = e;
    shippable = s;
  }

  string getName() const {
    return name;
  }

  bool isShippable() const {
    return shippable;
  }

  bool isExpire() const {
    return expire;
  }

  double getPrice() const {
    return price;
  }

  double getWeight() const {
    return weight;
  }

  int getQuantity() {
    return quantity;
  }

  // Reduce the quantity of the product after purchase
  void reduceQuantity(int amount) {
  if (amount > quantity) {
    throw std::runtime_error("Not enough stock for " + name);
  }
  quantity -= amount;
}
};

// Customer class
class Customer {
private:
  string name;
  int balance; 

public:
  Customer(string n = "Abdul-Rahaman", double b = 1000) {
    name = n;
    balance = b;
  }

  string getName() const {
    return name;
  }

  int getBalance() const {
    return balance;
  }

  void setBalance(int b) {
    balance = b;
  }

  void setName(const string& n) {
    name = n;
  }
};

// Derived product classes for specific product types
class Cheese : public Product {
  public:
    Cheese(int q = 0, string n = "cheese    ", double p = 100, int w = 200, bool e = true, bool s = true)
      : Product(q, n, p, w, e, s) {}
};

class Biscuits : public Product {
  public:
    Biscuits(int q = 0, string n  = "biscuits  ", double p = 150, int w = 700, bool e = false, bool s = true)
      : Product(q, n, p, w, e, s) {}
};

class TV : public Product {
  public:
    TV(int q = 0, string n = "tv        ", double p = 300, int w = 2000, bool e = false, bool s = true)
      : Product(q, n, p, w, e, s) {}
};

class ScratchCard : public Product {
  public:
    ScratchCard(int q = 0, string n = "scratchCard", double p = 300, int w = 2000, bool e = false, bool s = false)
      : Product(q, n, p, w, e, s) {}
};

// Shopping cart class
class cart {
public:
  vector<pair<Product*, int>> items; // Each item: pointer to Product and quantity
  int count = 0; // Number of different products in the cart

  // Add a product to the cart
  void add(Product* product, int quantity) {
    if (quantity > product->getQuantity()) {
      cout << "Out of stock" << endl;
    } else {
      items.push_back({product, quantity});
      count++;
		}
  }

  // Remove a product from the cart
  void remove(Product* product) {
    for (auto it = items.begin(); it != items.end(); ++it) {
      if (it->first == product) {
        items.erase(it);
        count--;
        break;
      }
    }
  }

  // Checkout process
  void checkout(double balance) {
    if (count < 1) {
      cout << "The cart is empty!" << endl; 
      return;
    }

    double totalWeight = 0;
    double totalPrice = 0;

    cout << "==== Welcome, sir! ====" << endl;
    cout << "** Shipment notice **" << endl;
    for (auto& item : items) {
      if (item.first->isExpire()) {
        cout << "Sorry, " << item.first->getName() << " expired" << endl;
        remove(item.first);
      } else {
        if (item.first->isShippable()) {        
          cout << item.second << "x " << item.first->getName() << "\t" << item.second * item.first->getWeight() << " g" << endl;
          totalWeight += item.second * item.first->getWeight();
        }
      }
    }
    cout << "Total package weight " << totalWeight / 1000 << " kg" << endl;
    cout << endl;

    cout << "** Checkout receipt **" << endl;
    for (auto& item : items) {
      cout << item.second << "x " << item.first->getName() << "\t" << item.second * item.first->getPrice() << " EGP" << endl;
      totalPrice += item.second * item.first->getPrice();
      item.first->reduceQuantity(item.second);
    }
    cout << "----------------------" << endl;
    cout << "Subtotal " << totalPrice << " EGP" << endl;
    cout << "Shipping 30 EGP" << endl;
    double totalPriceAfterTax = totalPrice + 30;
    cout << "Amount " << totalPriceAfterTax << " EGP" << endl;

    // Check if customer has enough balance
    if (balance - totalPriceAfterTax < 0) {
      cout << "\nSorry, your balance is insufficient." << endl;
      cout << "Purchase not completed :(" << endl;
    } else {
      cout << "\nYour balance after purchase " << balance - totalPriceAfterTax << " EGP" << endl;
      cout << "Purchase completed successfully! :)" << endl;
    }
  }

};

int main() {
  cart cart;
  Customer cust;
  cust.setBalance(10000); // initial balance

  // Create products
  Product* tv = new TV(5);
  Product* cheese = new Cheese(5);
  Product* biscuits = new Biscuits(5);
  Product* scratchCard = new ScratchCard(5);

  // Add products to cart
  cart.add(tv, 3);
  cart.add(cheese, 2);
  cart.add(scratchCard, 1);

  // checkout
  cart.checkout(cust.getBalance());
}