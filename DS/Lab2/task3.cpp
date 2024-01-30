#include <iostream>
#include <cstring>
using namespace std;

class ProductStockManger
{
    string *product;
    int *stock, size;

public:
    ProductStockManger() {}
    ProductStockManger(int s) : size(s)
    {
        product = new string[size];
        stock = new int[size];

        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter the name of product #" << i + 1 << " : ";
            cin >> product[i];

            cout << "\nEnter the number of stock of product #" << i + 1 << " : ";
            cin >> stock[i];
        }
    }

    // Copy constructore
    ProductStockManger(const ProductStockManger &obj) : size(obj.size)
    {
        product = new string[size];
        stock = new int[size];

        memcpy(product, obj.product, size * sizeof(string));
        memcpy(stock, obj.stock, size * sizeof(int));
    }

    // k226007 Copy assignment operator
    ProductStockManger &operator=(const ProductStockManger &obj)
    {
        if (this == &obj)
        {
            return *this;
        }

        delete[] product;
        delete[] stock;
        product = NULL;
        stock = NULL;

        size = obj.size;
        product = new string[size];
        stock = new int[size];

        memcpy(product, obj.product, size * sizeof(string));
        memcpy(stock, obj.stock, size * sizeof(int));

        return *this;
    }

    // Safe array
    void operator[](int i)
    {
        if (i < 0 || i > size)
        {
            cout << "\n Boundary Error!!";
            exit(1);
        }
    }

    // Methods
    void modify()
    {
        cout << "\nModify the first element,";
        cout << "\nProduct: ";
        cin >> product[0];
        cout << "\nStock: ";
        cin >> stock[0];
    }

    void display()
    {

        cout << "\n\n=========== Displaying Products and Stocks ===========\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << product[i] << ": " << stock[i] << endl;
        }
    }

    ~ProductStockManger()
    {
        delete[] product;
        product = NULL;
        delete[] stock;
        stock = NULL;
    }
};

int main()
{
    ProductStockManger obj(3);
    obj.display();

    ProductStockManger obj2(obj);
    obj2.display();

    // Modifying
    obj2.modify();

    cout << "\n\n ====== Display after modifying ======\n\n";
    obj.display();
    obj2.display();

    return 0;
}