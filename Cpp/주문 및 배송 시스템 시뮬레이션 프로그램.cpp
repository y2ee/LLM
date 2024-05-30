#include <iostream>
#include <vector>
#include <algorithm>

// ��ǰ ������ ��� Ŭ����
class Product {
public:
    std::string name;
    int quantity;
    std::string location;
    bool urgent;

    // �⺻ ������
    Product() {}

    Product(std::string name, int quantity, std::string location, bool urgent) {
        this->name = name;
        this->quantity = quantity;
        this->location = location;
        this->urgent = urgent;
    }
};

// ��ٱ��� Ŭ����
class Cart {
public:
    std::vector<Product> products;

    void addProduct(Product product) {
        products.push_back(product);
    }

    void printCart() {
        for (const auto& product : products) {
            std::cout << "{Name: " << product.name << ", Quantity: " << product.quantity << ", Location: " << product.location << ", Urgent: " << (product.urgent ? "true" : "false") << "}\n";
        }
    }
};

// ���� â�� Ŭ����
class Warehouse {
public:
    std::vector<Product> products;

    void deliverToWarehouse(Cart& cart) {
        for (const auto& product : cart.products) {
            products.push_back(product);
        }

        // ��� ��ǰ�� ���� ��ġ
        std::stable_partition(products.begin(), products.end(), [](const Product& product) {
            return product.urgent;
            });

        // ���� â���� �ִ� ũ�⸦ �ʰ��ϴ� ��ǰ�� �ٽ� ��ٱ��Ϸ� ��������
        if (products.size() > 3) {
            cart.products.assign(products.begin() + 3, products.end());
            products.resize(3);
        }
        else {
            cart.products.clear();
        }
    }

    void deliverToCustomer() {
        std::cout << "Products delivered to customers:\n";
        int delivered = std::min(static_cast<int>(products.size()), 3);
        for (int i = 0; i < delivered; i++) {
            std::cout << "{Name: " << products[i].name << ", Quantity: " << products[i].quantity << ", Location: " << products[i].location << ", Urgent: " << (products[i].urgent ? "true" : "false") << "}\n";
        }
        products.erase(products.begin(), products.begin() + delivered);
    }
};

// ���� �Լ�
int main() {
    Cart cart;
    Warehouse warehouse;

    while (true) {
        std::cout << "\n1: Add product to cart\n2: Deliver products to warehouses\n3: Deliver products to customers\n4: Print cart and warehouse information\n5: Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, location;
            int quantity;
            bool urgent;
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            std::cout << "Enter location: ";
            std::cin >> location;
            std::cout << "Is it urgent delivery? (1: yes, 0: no): ";
            std::cin >> urgent;
            cart.addProduct(Product(name, quantity, location, urgent));
            std::cout << "Product added to cart.\n";
            break;
        }
        case 2:
            warehouse.deliverToWarehouse(cart);
            std::cout << "Products delivered to warehouses.\n";
            break;
        case 3:
            warehouse.deliverToCustomer();
            break;
        case 4:
            std::cout << "\nCart Information:\n";
            cart.printCart();
            std::cout << "\nWarehouse Information:\n";
            std::cout << "Seoul Warehouse:\n";
            for (const auto& product : warehouse.products) {
                std::cout << "{Name: " << product.name << ", Quantity: " << product.quantity << ", Location: " << product.location << ", Urgent: " << (product.urgent ? "true" : "false") << "}\n";
            }
            break;
        case 5:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
