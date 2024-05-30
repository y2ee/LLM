#include <stdio.h>
#include <windows.h>

int main() {
    char source_file[MAX_PATH];
    char link_name[MAX_PATH];

    // ����ڷκ��� ���� ��� �Է� �ޱ�
    printf("Enter the path of the file you want to link: ");
    fgets(source_file, sizeof(source_file), stdin);

    // ����ڷκ��� �ɺ��� ��ũ�� �̸� �Է� �ޱ�
    printf("Enter the name for the symbolic link: ");
    fgets(link_name, sizeof(link_name), stdin);

    // ���� ���� ����
    source_file[strcspn(source_file, "\n")] = 0;
    link_name[strcspn(link_name, "\n")] = 0;

    // �ɺ��� ��ũ ����
    if (CreateSymbolicLink(link_name, source_file, 0) != 0) {
        printf("Symbolic link created from %s to %s\n", link_name, source_file);
    }
    else {
        printf("Failed to create symbolic link\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
