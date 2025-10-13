#include "CController.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"
#include "CListFinder.h"
#include "CListPrinter.h"

#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <vector>

CController::CController(void)
{
    // 더미 데이터 세팅
    m_list.addNewNode(new CUserData("Tomato", "Tomato_Oct13", "Vegetable", "2025-12-10", "LocalFarm", "120", "2500"));
    m_list.addNewNode(new CUserData("Potato", "Potato_Sep20", "Vegetable", "2025-11-30", "FreshFarm", "200", "1800"));
    m_list.addNewNode(new CUserData("Milk", "Milk_Dec01", "Dairy", "2025-12-15", "DailyDairy", "80", "1900"));
    m_list.addNewNode(new CUserData("Chicken", "Chicken_Nov25", "Meat", "2025-12-20", "PoultryPlus", "60", "7500"));
    m_list.addNewNode(new CUserData("Rice", "Rice_Aug18", "Grain", "2026-01-30", "HanRice", "500", "3200"));
    m_list.addNewNode(new CUserData("SoySauce", "SoySauce_Jul11", "Seasoning", "2026-03-15", "KFoodMart", "45", "5800"));
    m_list.addNewNode(new CUserData("Beef", "Beef_Oct09", "Meat", "2025-12-25", "MeatHouse", "40", "12800"));
    m_list.addNewNode(new CUserData("Cheese", "Cheese_Sep05", "Dairy", "2025-12-18", "DailyDairy", "75", "4200"));
    m_list.addNewNode(new CUserData("Apple", "Apple_Nov10", "Fruit", "2025-11-25", "FruitKing", "150", "2300"));
    m_list.addNewNode(new CUserData("Salt", "Salt_Jun07", "Seasoning", "2026-02-10", "KFoodMart", "300", "500"));
    m_list.addNewNode(new CUserData("Tomato", "Tomato_Nom13", "Vegetable", "2025-12-22", "LocalFarm", "100", "2500"));

	m_ui = new CUserInterface(*this);
}
// UI 생성자에 Controller 참조 넘겨서 양방향 연결

void CController::run() {
    int input = 0;
    do {
        input = m_ui->printMenu();
        switch (input) {
        case 1: addIngredient(); break;
        case 2: removeIngredient(); break;
        case 3: searchIngredient(); break;
        case 4: showAllIngredients(); break;
        case 5: sortIngredients(); break;
		case 6: showStatistics(); break;
        }
    } while (input != 0);
}


// Case 1
void CController::addIngredient() {
    char name[32], id[32], Category[32], Expr[64], Supplier[32], Count[64], Price[64];
    m_ui->inputName(name);
    m_ui->inputIdt(id);
    m_ui->inputCategory(Category);
    m_ui->inputExpr(Expr);
    m_ui->inputSupplier(Supplier);
    m_ui->inputCount(Count);
    m_ui->inputPrice(Price);


    int nResult = m_list.addNewNode(new CUserData(name, id, Category, Expr, Supplier, Count, Price));
    if (nResult == 0)
    {
        puts("ERROR: 이미 존재하는 재료입니다.");
        _getch();

    }

    else if (nResult == -1)
    {
        puts("ERROR: 잘못 입력했습니다.");
        _getch();

    }

    printf("\n해당 재료가 성공적으로 등록되었습니다. \n");
    printf("아무 키나 누르면 메뉴로 돌아갑니다...\n\n");
    _getch();
}

// Case 2
void CController::removeIngredient() {
    char idt[32];
    m_ui->inputIdt(idt);
    if (m_list.removeNode(idt))
        m_ui->printMessage("삭제 완료.");
    else
        m_ui->printMessage("삭제 실패. 해당 재료 없음.");
}

//Case 4 제거 예정
void CController::showAllIngredients() {

	CListPrinter printer(m_list);    // Printer 생성 
	printer.printAll();   //  CMyList::printAll() → CListPrinter로 이관
    
	/*CMyIterator iter = m_list.makeIterator();
    CUserData* pNode = nullptr;

    // model에서 데이터를가져와 UI에 출력요청
    m_ui->displayUserList(iter);
    */
}


/*
// Case 5
void CController::sortByID() {
    m_list.sortByID();
}
*/

void CController::sortIngredients() {

    system("cls");
    printf("- Sort -\n");
    printf("1. Sort by Ingredient Name\n");
    printf("2. Sort by Ingredient IDentifier\n");
    printf("3. Sort by Category\n");
    printf("4. Sort by Expiration Date\n");
    //printf("5. Sort by Supplier\n");
    //printf("6. Sort by Quantity\n");
    //printf("7. Sort by Unit Price\n> ");

    int sel;
    scanf_s("%d", &sel);
    switch (sel) {
    case 1: m_list.sortBy(SortType::NAME);
        break;
    case 2: m_list.sortBy(SortType::ID); 
        break;
    case 3: m_list.sortBy(SortType::Category); 
        break;
    case 4: m_list.sortBy(SortType::Expr); 
        break;
    default: puts("잘못된 입력입니다.");  
        break;
    }
    //_getch();
}


/// ////////////////////////////////////////
/// case 3 - Search

void CController::searchIngredient() {
    CListFinder finder(m_list);      // Finder 생성
    CListPrinter printer(m_list);    // Printer 생성

    int choice = 0;
    /*
    system("cls");
    printf("- Search -\n");
    printf("1. Search by name\n");
    printf("2. Search by student ID\n");
    printf("3. Search by admission year\n");
    printf("4. Search by Category year\n");
    printf("5. Search by department name\n");
    printf("6. List All\n");
    printf("7. Search by partial name\n\n");
    printf("> ");*/
    system("cls");
    printf("- Search -\n");
    printf("1. Search by Ingredient Name\n");
    printf("2. Search by Ingredient ID\n");
    printf("3. Search by Category\n");
    printf("4. Search by Supplier\n");
    printf("5. Partial Search by Ingredient Name\n\n");
    printf("6. Show All Ingredients\n");
    printf("> ");

    scanf_s("%d", &choice);

    char key[64] = { 0 };

    switch (choice) {

        //이름
    case 1:
        m_ui->inputName(key);
        printer.printNodes(finder.findByName(key));
        //  inline 호출(즉시 반환 → 즉시 전달)
        //   vector 바로 전달
        break;

        //식별자
    case 2:
        m_ui->inputIdt(key);
        printer.printNodes(finder.findByIdt(key));
        break;

        // 분류
    case 3:
        m_ui->inputCategory(key);
        printer.printNodes(finder.findByCategory(key));
        break;

        //공급처
    case 4:
        m_ui->inputSupplier(key);
        printer.printNodes(finder.findBySupplier(key));
        break;

        // 부분 문자열 검색
    case 5:
        printf("Enter partial name: ");
        scanf_s("%s", key, (unsigned)sizeof(key));  // 검색어 입력 받기

        {
            auto results = finder.findByPartialName(key);

            if (results.empty()) {
                printf("\n검색 결과가 없습니다.\n");
            }
            else {
                printf("\n[부분 이름 검색 결과]\n");
                printf("----------------------------------------------\n");
                for (auto pNode : results) {
                    CUserData* user = static_cast<CUserData*>(pNode);
                    user->printNode();
                }
                printf("----------------------------------------------\n");
                printf("총 %d개 발견됨.\n", (int)results.size());
            }
            _getch();
        }
        break;

    default:
        printf("Invalid choice.\n");
        _getch();
        break;

    case 6:
        printer.printAll();   //  CMyList::printAll() → CListPrinter로 이관
        break;

    }
}

    void CController::showStatistics() {
    system("cls");
    printf("==============================================\n");
    printf("                 [Statistics]\n");
    printf("==============================================\n\n");
    printf("1. Statistics by Admission Year\n");
    printf("2. Statistics by Ingredient Category\n");
    printf("3. Statistics by Supplier\n\n");
    printf("0. Return to Main Menu\n");
    printf("----------------------------------------------\n");
    printf("Select: ");

    int sel;
    scanf_s("%d", &sel);

    CListPrinter stprint(m_list);

    switch (sel) {
    case 1:
        stprint.printStatisticsByName(m_list);
        break;
    case 2:
        stprint.printStatisticsByCategory(m_list);
        break;
    case 3:
        stprint.printStatisticsBySupplier(m_list);
        break;
    default:
        printf("\nReturning to menu...\n");
        _getch();
        return;
    }
}