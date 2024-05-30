#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ǰ ������ ��� ����ü
typedef struct {
    char name[100];
    int quantity;
    char location[100];
    int urgent; // 1: true, 0: false
} Product;

// ��ٱ��� ����ü
typedef struct {
    Product* products;
    int size;
} Cart;

// ���� â�� ����ü
typedef struct {
    Product* products;
    int size;
} Warehouse;

// ��ǰ�� ��ٱ��Ͽ� �߰��ϴ� �Լ�
void addProductToCart(Cart* cart, char* name, int quantity, char* location, int urgent) {
    cart->products = (Product*)realloc(cart->products, (cart->size + 1) * sizeof(Product));
    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    strcpy(product.location, location);
    product.urgent = urgent;
    cart->products[cart->size++] = product;
}

// ��ٱ��� ������ ����ϴ� �Լ�
void printCart(Cart* cart) {
    for (int i = 0; i < cart->size; i++) {
        printf("{Name: %s, Quantity: %d, Location: %s, Urgent: %s}\n", cart->products[i].name, cart->products[i].quantity, cart->products[i].location, cart->products[i].urgent ? "true" : "false");
    }
}

// ��ٱ����� ��ǰ�� ���� â��� �̵���Ű�� �Լ�
void deliverToWarehouse(Cart* cart, Warehouse* warehouse) {
    for (int i = 0; i < cart->size; i++) {
        warehouse->products = (Product*)realloc(warehouse->products, (warehouse->size + 1) * sizeof(Product));
        warehouse->products[warehouse->size++] = cart->products[i];
    }

    // ��� ��ǰ�� ���� ��ġ
    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].urgent) {
            for (int j = i; j > 0; j--) {
                Product temp = warehouse->products[j];
                warehouse->products[j] = warehouse->products[j - 1];
                warehouse->products[j - 1] = temp;
            }
        }
    }

    // ���� â���� �ִ� ũ�⸦ �ʰ��ϴ� ��ǰ�� �ٽ� ��ٱ��Ϸ� ��������
    if (warehouse->size > 3) {
        cart->size = warehouse->size - 3;
        for (int i = 0; i < cart->size; i++) {
            cart->products[i] = warehouse->products[i + 3];
        }
        warehouse->size = 3;
    }
    else {
        cart->size = 0;
    }
}

// ���� â���� ��ǰ�� ������ ����ϴ� �Լ�
void deliverToCustomer(Warehouse* warehouse) {
    printf("Products delivered to customers:\n");
    int delivered = warehouse->size < 3 ? warehouse->size : 3;
    for (int i = 0; i < delivered; i++) {
        printf("{Name: %s, Quantity: %d, Location: %s, Urgent: %s}\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].location, warehouse->products[i].urgent ? "true" : "false");
    }
    for (int i = 0; i < warehouse->size - delivered; i++) {
        warehouse->products[i] = warehouse->products[i + delivered];
    }
    warehouse->size -= delivered;
}

// ���� �Լ�
int main() {
    Cart cart;
    cart.products = NULL;
    cart.size = 0;

    Warehouse warehouse;
    warehouse.products = NULL;
    warehouse.size = 0;

    int choice;
    char name[100], location[100];
    int quantity, urgent;

    while (1) {
        printf("\n1: Add product to cart\n2: Deliver products to warehouses\n3: Deliver products to customers\n4: Print cart and warehouse information\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter location: ");
            scanf("%s", location);
            printf("Is it urgent delivery? (1: yes, 0: no): ");
            scanf("%d", &urgent);
            addProductToCart(&cart, name, quantity, location, urgent);
            printf("Product added to cart.\n");
            break;
        case 2:
            deliverToWarehouse(&cart, &warehouse);
            printf("Products delivered to warehouses.\n");
            break;
        case 3:
            deliverToCustomer(&warehouse);
            break;
        case 4:
            printf("\nCart Information:\n");
            printCart(&cart);
            printf("\nWarehouse Information:\n");
            printf("Seoul Warehouse:\n");
            for (int i = 0; i < warehouse.size; i++) {
                printf("{Name: %s, Quantity: %d, Location: %s, Urgent: %s}\n", warehouse.products[i].name, warehouse.products[i].quantity, warehouse.products[i].location, warehouse.products[i].urgent ? "true" : "false");
            }
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
