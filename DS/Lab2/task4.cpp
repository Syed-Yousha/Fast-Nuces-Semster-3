#include <iostream>
#include <cstring>
using namespace std;

class FruitInventory
{
    int *species;
    int fruits;
    int **arr;
    string *fruit_names;

public:
    FruitInventory() {}
    FruitInventory(int q) : fruits(q)
    {
        arr = new int *[fruits];
        fruit_names = new string[fruits];
        species = new int[fruits];

        for (int i = 0; i < fruits; i++)
        {
            cout << "\nEnter the name of fruit #" << i + 1 << " : ";
            cin >> fruit_names[i];

            cout << "\nEnter the quantity of different species of fruits for " << fruit_names[i] << " : ";
            cin >> species[i];

            arr[i] = new int[species[i]];
            for (int j = 0; j < species[i]; j++)
            {
                cout << "\nEnter the price of species #" << j + 1 << " for " << fruit_names[i] << " : ";
                cin >> arr[i][j];
            }
        }
    }

    int &operator()(int i)
    {
        if (i < 0 || i >= fruits)
        {
            cout << "\nBoundary error!";
            exit(1);
        }
        return species[i];
    }

    void displayInvent()
    {
        cout << "\n\n======== Fruits Data ========";
        for (int i = 0; i < fruits; i++)
        {
            cout << "\nPrices of " << fruit_names[i] << " : ";

            for (int j = 0; j < species[i]; j++)
            {
                cout << arr[i][j] << ", ";
            }
        }
    }

    void modify()
    {
        fruit_names[0] = "Modified_banana";
    }

    FruitInventory(const FruitInventory &obj) : fruits(obj.fruits), fruit_names(new string[obj.fruits])
    {
        species = new int[fruits];
        arr = new int *[fruits];

        for (int i = 0; i < fruits; i++)
        {
            fruit_names[i] = obj.fruit_names[i];
            species[i] = obj.species[i];

            arr[i] = new int[species[i]];
            memcpy(arr[i], obj.arr[i], sizeof(int) * species[i]);
        }
    }

    FruitInventory &operator=(const FruitInventory &obj)
    {
        if (this == &obj)
            return *this;

        for (int i = 0; i < fruits; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] species;
        delete[] fruit_names;

        fruits = obj.fruits;
        fruit_names = new string[fruits];
        species = new int[fruits];
        arr = new int *[fruits];

        for (int i = 0; i < fruits; i++)
        {
            species[i] = obj.species[i];
            fruit_names[i] = obj.fruit_names[i];

            arr[i] = new int[species[i]];
            memcpy(arr[i], obj.arr[i], sizeof(int) * species[i]);
        }

        return *this;
    }

    ~FruitInventory()
    {
        for (int i = 0; i < fruits; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] species;
        delete[] fruit_names;
    }
};

int main()
{
    int fruits;
    cout << "\nEnter the number of fruits: ";
    cin >> fruits;

    FruitInventory obj(fruits);
    obj.displayInvent();

    // Object 2
    FruitInventory obj2(obj);
    obj2.displayInvent();

    // Modifying (k226007)
    obj2.modify();
    cout << "\n\n ==================== Displaying both obj after modifying ====================\n";
    obj.displayInvent();
    obj2.displayInvent();
    return 0;
}
