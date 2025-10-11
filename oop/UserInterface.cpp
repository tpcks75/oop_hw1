#include "UserInterface.h"
#include "UserData.h"
#include "MyIterator.h"


#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <cctype>   // isdigit

CUserInterface::CUserInterface(CController& ctrl)
    : m_ctrl(ctrl) {
}

int CUserInterface::printMenu() {
    int sel;
    system("cls");
    printf("[1] Add\n[2] Remove\n[3] Search\n[4] PrintAll\n[5] Sort\n[0] Exit\nSelect: ");
    scanf_s("%d", &sel);
    return sel;
}
////////////////////////////////////////////////////////////////
void CUserInterface::inputName(char* name) {
    while (true) {
        
        printf("Input Name (<=15 chars): ");
        getchar();
        fgets(name, 32, stdin);
        name[strcspn(name, "\n")] = '\0'; // ���� ����

        size_t len = strlen(name);

        if (len == 0 || len > 15) {
            printf("Error: Invalid name format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // ������ �����
            continue;
        }
        break;
    }
}

void CUserInterface::inputStudentID(char* id) {
    while (true) {
        
        printf("Input Student ID (10 digits): ");
        scanf_s("%s", id, 32);

        size_t len = strlen(id);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)id[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len != 10) {
            printf("Error: Invalid student ID format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // ������ �����
            continue;
        }
        
        break;
    }
}

void CUserInterface::inputBirth(char* birth) {
    while (true) {
       
        printf("Input Birth Year (4 digits): ");
        scanf_s("%s", birth, 32);

        size_t len = strlen(birth);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)birth[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len != 4) {
            printf("Error: Invalid birth year format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // ������ �����
            continue;
        }
        
        break;
    }
}

void CUserInterface::inputDept(char* dept) {
    printf("Input Department (���� ���): ");
    getchar(); // ���� �Է��� ���� ����
    fgets(dept, 64, stdin); // scanf�� ���� ���� �Ұ�.
    dept[strcspn(dept, "\n")] = 0; // ���� ����
}

void CUserInterface::inputTel(char* tel) {
    while (true) {

        printf("Input Tel : ");
        scanf_s("%s", tel, 32);

        size_t len = strlen(tel);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)tel[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len > 12 || len == 0) {
            printf("Error: Invalid phone number format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // ������ �����
            continue;
        }
       
        break;
    }
}

void CUserInterface::inputAdmissionYear(char* year) {
    while (true) {
        printf("Input Admission Year (4 digits): ");
        scanf_s("%s", year, 32);

        size_t len = strlen(year);
        bool allDigits = true;

        // ��� ���ڰ� �������� �˻�
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)year[i])) {
                allDigits = false;
                break;
            }
        }

        // ���� ���� ��
        if (!allDigits || len != 4) {
            printf("Error: Invalid admission year format.\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }

        // ���� ���� �� Ż��
        break;
    }
}

////////////////////////////////////////////////////////////////
void CUserInterface::printMessage(const char* msg) {
    printf("%s\n", msg);
    _getch();
}

void CUserInterface::displayUserList(CMyIterator& it) {
    CUserData* pNode = nullptr;
    while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
        pNode->printNode();
        it.MoveNext();
    }
    printf("\n�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n\n");
    _getch();
}