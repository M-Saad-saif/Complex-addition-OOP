# Operator Overloading in C++ (Prefix & Postfix, istream & ostream)

This project demonstrates **operator overloading** in C++ for:
- Prefix increment (`++n`)
- Postfix increment (`n++`)
- Input operator (`>>`)
- Output operator (`<<`)

## 📌 Features
- Overload **prefix ++**
- Overload **postfix ++**
- Overload **istream (>>) for input**
- Overload **ostream (<<) for output**

---

## 📘 Code Example

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, img;

    Complex() {
        real = 0;
        img = 0;
    }

    // PREFIX ++n
    Complex operator ++() {
        Complex temp;
        temp.real = ++real;
        temp.img = ++img;
        return temp;
    }

    // POSTFIX n++
    Complex operator ++(int) {
        Complex temp;
        temp.real = real++;
        temp.img = img++;
        return temp;
    }

    // INPUT using istream
    friend istream& operator >> (istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.img;
        return in;
    }

    // OUTPUT using ostream
    friend ostream& operator << (ostream &out, const Complex &c) {
        out << c.real << " + " << c.img << "i";
        return out;
    }
};

int main() {
    Complex c1;

    cin >> c1;
    cout << "Original: " << c1 << endl;

    cout << "Prefix (++c1): " << ++c1 << endl;
    cout << "After Prefix: " << c1 << endl;

    cout << "Postfix (c1++): " << c1++ << endl;
    cout << "After Postfix: " << c1 << endl;

    return 0;
}
```

---

## 📚 Why `istream` and `ostream`?

### ✔ `istream`  
Used for **input operations** (like `cin`).  
We overload `>>` so the object can take input directly.

### ✔ `ostream`  
Used for **output operations** (like `cout`).  
We overload `<<` so the object can print itself easily.

---

## 📝 Summary
This README explains and demonstrates:
- How prefix & postfix increment operators work
- How to overload `>>` and `<<`
- Clean and simple C++ implementation
