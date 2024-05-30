#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct {
    char item_name[50];
    int price;
    int stock;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int menu_count = 0;

char admin_password[50] = "";
bool logged_in_as_admin = false;

void set_admin_password() {
    while (1) {
        char password[50];
        char confirm_password[50];
        printf("������ ��й�ȣ�� �����ϼ���: ");
        scanf("%s", password);
        printf("��й�ȣ�� �ٽ� �� �� �Է��ϼ���: ");
        scanf("%s", confirm_password);
        if (strcmp(password, confirm_password) == 0) {
            strcpy(admin_password, password);
            printf("������ ��й�ȣ�� �����Ǿ����ϴ�.\n");
            break;
        }
        else {
            printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}

void add_menu() {
    char item_name[50];
    int price;
    while (1) {
        printf("�߰��� �޴��� �Է��ϼ��� (�����Ϸ��� '�޴� ���� �Ϸ�!' �Է�): ");
        //�޴� ���� �Ϸ�!�� �Է��ص� ���� â���� ���ư��� �ʰ� ��� �޴��� ġ���� �մϴ�. (GPT�� ���� ������ �ݺ��س�...)
        scanf("%s", item_name);
        if (strcmp(item_name, "�޴� ���� �Ϸ�!") == 0) {
            break;
        }
        if (menu_count >= MAX_ITEMS) {
            printf("�� �̻� �޴��� �߰��� �� �����ϴ�. �ִ� ������ �����߽��ϴ�.\n");
            break;
        }
        bool already_exists = false;
        for (int i = 0; i < menu_count; ++i) {
            if (strcmp(menu[i].item_name, item_name) == 0) {
                already_exists = true;
                printf("�̹� �����ϴ� �޴��Դϴ�.\n");
                break;
            }
        }
        if (already_exists) {
            continue;
        }
        printf("������ �Է��ϼ���: ");
        scanf("%d", &price);
        if (price > 10000) {
            printf("������ �ʹ� �����ϴ�. 10000���� �ʰ��� �� �����ϴ�.\n");
        }
        else if (price < 1000) {
            printf("������ �ʹ� �����ϴ�. 1000�� �̻��̾�� �մϴ�.\n");
        }
        else {
            strcpy(menu[menu_count].item_name, item_name);
            menu[menu_count].price = price;
            menu[menu_count].stock = 10;
            menu_count++;
        }
    }
}

void delete_menu() {
    char item_name[50];
    while (1) {
        printf("������ �޴��� �Է��ϼ��� (�����Ϸ��� '�޴� ���� �Ϸ�!' �Է�): ");
        scanf("%s", item_name);
        if (strcmp(item_name, "�޴� ���� �Ϸ�!") == 0) {
            break;
        }
        bool found = false;
        for (int i = 0; i < menu_count; ++i) {
            if (strcmp(menu[i].item_name, item_name) == 0) {
                found = true;
                for (int j = i; j < menu_count - 1; ++j) {
                    menu[j] = menu[j + 1];
                }
                menu_count--;
                printf("�޴��� �����Ǿ����ϴ�.\n");
                break;
            }
        }
        if (!found) {
            printf("�������� �ʴ� �޴��Դϴ�.\n");
        }
    }
}

void show_menu() {
    printf("\n�޴� ���:\n");
    for (int i = 0; i < menu_count; ++i) {
        printf("%s: %d�� - ���: %d��\n", menu[i].item_name, menu[i].price, menu[i].stock);
    }
}

int main() {
    set_admin_password();
    int choice;
    while (1) {
        printf("\n1. �޴� �߰�\n2. �޴� ����\n3. �޴� ��ȸ\n4. ����\n");
        printf("���ϴ� �۾��� �����ϼ���: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_menu();
            break;
        case 2:
            delete_menu();
            break;
        case 3:
            show_menu();
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            return 0; // main �Լ� ����
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}
