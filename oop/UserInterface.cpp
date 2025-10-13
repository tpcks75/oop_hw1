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
    printf("[1] Add Ingredient\
\n[2] Delete Ingredient\
\n[3] Search Ingredient\
\n[4] Display All Ingredients\
\n[5] Sort Ingredients\
\n[6] View Statistics\
\n[0] Exit\n>");
    scanf_s("%d", &sel);
    return sel;
}
////////////////////////////////////////////////////////////////
// 재료 이름
void CUserInterface::inputName(char* name) {
    while (true) {
        printf("Input Ingredient Name (1~15 chars, no space): ");
        getchar(); // flush leftover newline
        fgets(name, 32, stdin);
        name[strcspn(name, "\n")] = '\0';

        size_t len = strlen(name);
        bool valid = true;

        // 공백 또는 비어있는 이름, 길이 초과 검사
        if (len == 0 || len > 15) valid = false;
        for (size_t i = 0; i < len; ++i) {
            if (isspace((unsigned char)name[i])) valid = false;
        }

        if (!valid) {
            printf("Error: Invalid ingredient name format.\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }
        break;
    }
}

//   재료 식별자 (예: Apple_Oct13)
void CUserInterface::inputIdt(char* idt) {
    while (true) {
        printf("Input Ingredient ID (e.g., Apple_Oct13): ");
        scanf_s("%s", idt, 32);

        size_t len = strlen(idt);
        bool valid = true;

        // '_' 포함 여부 검사
        if (strchr(idt, '_') == nullptr) valid = false;

        // 알파벳/숫자/'_' 만 허용
        for (size_t i = 0; i < len; ++i) {
            if (!isalnum((unsigned char)idt[i]) && idt[i] != '_') {
                valid = false;
                break;
            }
        }

        if (!valid || len < 5 || len > 25) {
            printf("Error: Invalid ID format. (ex: Apple_Oct13)\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }
        break;
    }
}

//   재료 분류
void CUserInterface::inputCategory(char* category) {
    while (true) {
        printf("Input Category (e.g., Fruit, Dairy): ");
        scanf_s("%s", category, 32);

        size_t len = strlen(category);
        bool valid = true;

        // 영문만 허용
        for (size_t i = 0; i < len; ++i) {
            if (!isalpha((unsigned char)category[i])) {
                valid = false;
                break;
            }
        }

        if (!valid || len == 0 || len > 15) {
            printf("Error: Invalid category format. Use letters only.\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }
        break;
    }
}


//    유통기한 (YYYYMMDD, 8자리 숫자)
void CUserInterface::inputExpr(char* expr) {
    while (true) {
        printf("Input Expiration Date (YYYYMMDD): ");
        scanf_s("%s", expr, 32);

        size_t len = strlen(expr);
        bool allDigits = true;
        for (size_t i = 0; i < len; ++i) {
            if (!isdigit((unsigned char)expr[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits || len != 8) {
            printf("Error: Invalid expiration date. (format: YYYYMMDD)\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }
        break;
    }
}

//   공급처 (문자열, 공백 없음)
void CUserInterface::inputSupplier(char* supplier) {
    while (true) {
        printf("Input Supplier Name (1~20 chars): ");
        scanf_s("%s", supplier, 32);

        size_t len = strlen(supplier);
        bool valid = true;
        for (size_t i = 0; i < len; ++i) {
            if (isspace((unsigned char)supplier[i])) {
                valid = false;
                break;
            }
        }

        if (!valid || len == 0 || len > 20) {
            printf("Error: Invalid supplier name.\n");
            printf("Press any key to retry...\n\n");
            _getch();
            continue;
        }
        break;
    }
}

//   재료 개수 (0 이상 정수)
void CUserInterface::inputCount(char* countStr) {
    while (true) {
        printf("Input Count (integer ≥ 0): ");
        scanf_s("%s", countStr, 32);

        bool valid = true;
        for (size_t i = 0; i < strlen(countStr); ++i) {
            if (!isdigit((unsigned char)countStr[i])) {
                valid = false;
                break;
            }
        }

        int count = atoi(countStr);
        if (!valid || count < 0) {
            printf("Error: Invalid quantity. Must be a non-negative integer.\n");
            _getch();
            continue;
        }

        break;
    }
}


//   단가 (0 이상 정수)
void CUserInterface::inputPrice(char* priceStr) {
    while (true) {
        printf("Input Unit Price (integer ≥ 0): ");
        scanf_s("%s", priceStr, 32);

        bool valid = true;
        for (size_t i = 0; i < strlen(priceStr); ++i) {
            if (!isdigit((unsigned char)priceStr[i])) {
                valid = false;
                break;
            }
        }

        int price = atoi(priceStr);
        if (!valid || price < 0) {
            printf("Error: Invalid price. Must be a non-negative integer.\n");
            _getch();
            continue;
        }

        break;
    }
}

/*
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
}*/

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