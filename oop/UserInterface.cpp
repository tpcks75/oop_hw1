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
    printf("[1] Add\n[2] Remove\n[3] Search\n[4] PrintAll\n[5] Sort\n[6] Statistics\n[0] Exit\n>");
    scanf_s("%d", &sel);
    return sel;
}
////////////////////////////////////////////////////////////////
void CUserInterface::inputName(char* name) {
    while (true) {
        
        printf("Input Name (<=15 chars): ");
        getchar();
        fgets(name, 32, stdin);
        name[strcspn(name, "\n")] = '\0'; // 개행 제거

        size_t len = strlen(name);

        if (len == 0 || len > 15) {
            printf("Error: Invalid name format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // 현재줄 지우기
            continue;
        }
        break;
    }
}

void CUserInterface::inputIdt(char* id) {
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

            printf("\r\033[K"); // 현재줄 지우기
            continue;
        }
        
        break;
    }
}

void CUserInterface::inputCategory(char* Category) {
    while (true) {
       
        printf("Input Category Year (4 digits): ");
        scanf_s("%s", Category, 32);

        size_t len = strlen(Category);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)Category[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len != 4) {
            printf("Error: Invalid Category year format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // 현재줄 지우기
            continue;
        }
        
        break;
    }
}

void CUserInterface::inputExpr(char* Expr) {
    printf("Input Department (공백 허용): ");
    getchar(); // 이전 입력의 개행 제거
    fgets(Expr, 64, stdin); // scanf는 공백 포함 불가.
    Expr[strcspn(Expr, "\n")] = 0; // 개행 제거
}

void CUserInterface::inputSupplier(char* Supplier) {
    while (true) {

        printf("Input Supplier : ");
        scanf_s("%s", Supplier, 32);

        size_t len = strlen(Supplier);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)Supplier[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len > 12 || len == 0) {
            printf("Error: Invalid phone number format.\n");
            printf("Press any key to retry...\n\n");
            _getch();

            printf("\r\033[K"); // 현재줄 지우기
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

        // 모든 문자가 숫자인지 검사
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)year[i])) {
                allDigits = false;
                break;
            }
        }

        // 검증 실패 시
        if (!allDigits || len != 4) {
            printf("Error: Invalid admission year format.\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }

        // 검증 성공 시 탈출
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
    printf("\n아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
    _getch();
}