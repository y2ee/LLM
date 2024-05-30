#include <iostream>
#include <vector>

#define MAX_ITEMS 100

struct MenuItem {
    std::string item_name;
    int price;
    int stock;
};

std::vector<MenuItem> menu;
std::string admin_password = "";
bool logged_in_as_admin = false;

void set_admin_password() {
    while (true) {
        std::string password, confirm_password;
        std::cout << "������ ��й�ȣ�� �����ϼ���: ";
        std::cin >> password;
        std::cout << "��й�ȣ�� �ٽ� �� �� �Է��ϼ���: ";
        std::cin >> confirm_password;
        if (password == confirm_password) {
            admin_password = password;
            std::cout << "������ ��й�ȣ�� �����Ǿ����ϴ�.\n";
            break;
        }
        else {
            std::cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�. �ٽ� �õ��ϼ���.\n";
        }
    }
}

void add_menu() {
    while (true) {
        std::string item_name;
        int price;
        std::cout << "�߰��� �޴��� �Է��ϼ��� (�����Ϸ��� '�޴� ���� �Ϸ�!' �Է�): ";
        std::cin >> item_name;
        if (item_name == "�޴� ���� �Ϸ�!")
            break;
        if (menu.size() >= MAX_ITEMS) {
            std::cout << "�� �̻� �޴��� �߰��� �� �����ϴ�. �ִ� ������ �����߽��ϴ�.\n";
            break;
        }
        bool already_exists = false;
        for (const auto& menuItem : menu) {
            if (menuItem.item_name == item_name) {
                already_exists = true;
                std::cout << "�̹� �����ϴ� �޴��Դϴ�.\n";
                break;
            }
        }
        if (already_exists)
            continue;
        std::cout << "������ �Է��ϼ���: ";
        std::cin >> price;
        if (price > 10000) {
            std::cout << "������ �ʹ� �����ϴ�. 10000���� �ʰ��� �� �����ϴ�.\n";
        }
        else if (price < 1000) {
            std::cout << "������ �ʹ� �����ϴ�. 1000�� �̻��̾�� �մϴ�.\n";
        }
        else {
            menu.push_back({ item_name, price, 10 });
        }
    }
}

void delete_menu() {
    while (true) {
        std::string item_name;
        std::cout << "������ �޴��� �Է��ϼ��� (�����Ϸ��� '�޴� ���� �Ϸ�!' �Է�): ";
        std::cin >> item_name;
        if (item_name == "�޴� ���� �Ϸ�!")
            // �޴� ���� �ϷḦ ġ�� ���ѷ����� ��... GPT�� �Ȱ��� ���� ��� �߻���Ŵ
            break;
        bool found = false;
        for (auto it = menu.begin(); it != menu.end(); ++it) {
            if (it->item_name == item_name) {
                found = true;
                menu.erase(it);
                std::cout << "�޴��� �����Ǿ����ϴ�.\n";
                break;
            }
        }
        if (!found) {
            std::cout << "�������� �ʴ� �޴��Դϴ�.\n";
        }
    }
}

void show_menu() {
    std::cout << "\n�޴� ���:\n";
    for (const auto& menuItem : menu) {
        std::cout << menuItem.item_name << ": " << menuItem.price << "�� - ���: " << menuItem.stock << "��\n";
    }
}

int main() {
    set_admin_password();
    int choice;
    while (true) {
        std::cout << "\n1. �޴� �߰�\n2. �޴� ����\n3. �޴� ��ȸ\n4. ����\n";
        std::cout << "���ϴ� �۾��� �����ϼ���: ";
        std::cin >> choice;
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
            std::cout << "���α׷��� �����մϴ�.\n";
            return 0; // main �Լ� ����
        default:
            std::cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n";
        }
    }
}
