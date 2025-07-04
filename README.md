# 🛒 E-Commerce System (Fawry Quantum Internship Challenge)

This is a simple in-memory **e-commerce system** written in **C++**, designed as part of the Fawry Quantum internship challenge. The system allows defining products, adding them to a cart, and performing a checkout that calculates totals and shipping.

---

## 📌 Features

✅ Define products with:
- `name`, `price`, `quantity`
- May expire (e.g., Cheese, Biscuits)
- May require shipping (e.g., TV, Cheese) — with weight

✅ Add items to the cart with a specific quantity  
✅ Prevent adding more items than available stock  
✅ Perform checkout:
- Print subtotal (sum of all items)
- Calculate shipping fee
- Show total paid amount
- Update customer balance
- Deduct stock quantities
- Print shipment notice for shippable items

✅ Handle errors:
- Prevent checkout if cart is empty
- Prevent checkout if any product is expired
- Prevent checkout if customer balance is insufficient

---

## 💻 How it works

- Products (like `Cheese`, `TV`, `ScratchCard`) are created with initial stock.
- A `Customer` is created with a balance.
- The customer adds items to a `Cart`.
- Checkout calculates the cost and shipping, updates stock and balance, and prints a receipt.

---

## ⚠ Assumptions

- **Shipping fee** is a flat 30 EGP per order.
- **Weights** are in grams; total package weight is displayed in kilograms.
- **Prices** and balance are handled using `double` for precision.
- The system runs in-memory (no database) — data resets on program restart.

---

## 📝 Example usage

```cpp
  cart cart;
  Customer cust;
  cust.setBalance(10000);

  Product* tv = new TV(5);
  Product* cheese = new Cheese(5);
  Product* biscuits = new Biscuits(5);
  Product* scratchCard = new ScratchCard(5);

  
  cart.add(tv, 3);
  cart.add(cheese, 2);
  cart.add(scratchCard, 1);

  cart.checkout(cust.getBalance());
```

---

## ✅ Output (sample):
```bash
==== Welcome, sir! ====
** Shipment notice **
3x tv           6000 g
Sorry, cheese     expired
Total package weight 6 kg

** Checkout receipt **
3x tv           900 EGP
1x scratchCard  300 EGP
----------------------
Subtotal 1200 EGP
Shipping 30 EGP
Amount 1230 EGP

Your balance after purchase 8770 EGP
Purchase completed successfully! :)
```

