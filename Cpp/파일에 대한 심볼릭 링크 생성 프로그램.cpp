#include <iostream>
#include <Windows.h>
#include <string>

int main() {
    wchar_t source_file[MAX_PATH];
    wchar_t link_name[MAX_PATH];

    // ����ڷκ��� ���� ��� �Է� �ޱ�
    std::wcout << L"Enter the path of the file you want to link: ";
    std::wcin.getline(source_file, sizeof(source_file));

    // ����ڷκ��� �ɺ��� ��ũ�� �̸� �Է� �ޱ�
    std::wcout << L"Enter the name for the symbolic link: ";
    std::wcin.getline(link_name, sizeof(link_name));

    // �ɺ��� ��ũ ����
    if (CreateSymbolicLinkW(link_name, source_file, 0) != 0) {
        std::wcout << L"Symbolic link created from " << link_name << L" to " << source_file << std::endl;
    }
    else {
        std::wcerr << L"Failed to create symbolic link" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
