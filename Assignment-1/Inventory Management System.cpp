// Array



// 1. :



// Design an inventory management system for a any small business. Use
// an array to store the quantity of different products in stock. Implement
// functionalities to add products (quantity of product), update quantities,
// display the current inventory.
// - Perform inventory management functionalities and alert when a product
// is running low on stock.


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int max_product = 100;

class Inventory
{
    string product[max_product];
    int quantities[max_product];
    int productNum;

public:
    Inventory()
    {
        fill_n(product, max_product, "-1");
        fill_n(quantities, max_product, -1);
        productNum = 0;
    }

    void addProduct()
    {
        string name;
        int quantity;
        if (productNum == max_product - 1)
        {
            cout << "Array is full, can't add more products" << endl;
        }
        else
        {
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            while (quantity < 0)
            {
                cout << "Negative quantity not allowed. Enter again the value : ";
                cin >> quantity;
            }
            product[productNum] = name;
            quantities[productNum] = quantity;
            productNum++;
            cout << "Product: " << name << " added to inventory." << endl;
        }
    }

    void removeProduct()
    {
        string name;
        int pos = -1;
        if (productNum == 0)
        {
            cout << "Inventory is empty\n";
            return;
        }
        cout << "Enter product name to remove: ";
        cin.ignore();
        getline(cin, name);
        for (int i = 0; i < productNum; i++)
        {
            if (product[i] == name)
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            cout << "Product not found\n";
            return;
        }
        int i = pos;
        while (i < productNum)
        {
            product[i] = product[i + 1];
            quantities[i] = quantities[i + 1];
            i++;
        }
        productNum--;
        cout << "Product removed\n";
    }

    void updateQuantity()
    {
        int pos = 0;
        if (productNum == 0)
        {
            cout << "Inventory is empty\n";
            return;
        }
        string name;
        int quantity;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter updated quantity: ";
        cin >> quantity;
        while (quantity < 0)
        {
            cout << "Negative quantity not allowed. Enter again: ";
            cin >> quantity;
        }
        for (int i = 0; i < productNum; i++)
        {
            if (product[i] == name)
            {
                quantities[i] = quantity;
                if (quantities[i] <= 0)
                {
                    pos = i;
                    int j = pos;
                    while (j < productNum)
                    {
                        product[j] = product[j + 1];
                        quantities[j] = quantities[j + 1];
                        j++;
                    }
                    productNum--;
                }
                return;
            }
        }
        cout << "Product not found in inventory." << endl;
    }

    void displayInventory()
    {
        if (productNum == 0)
        {
            cout << "Inventory is empty\n";
            return;
        }
        cout << "Inventory: " << endl;
        for (int i = 0; i < productNum; i++)
        {
            cout << product[i] << " - " << quantities[i] << " units\n";
            if (quantities[i] < 10)
            {
                cout << "* ALERT: Low stock for " << product[i] << " *\n";
            }
        }
    }
};

int main()
{
    Inventory inventory;
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Add product\n2.Remove a product\n3.Update quantity of a product\n4.Show inventory\n5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            inventory.addProduct();
            break;
        case 2:
            inventory.removeProduct();
            break;
        case 3:
            inventory.updateQuantity();
            break;
        case 4:
            inventory.displayInventory();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}