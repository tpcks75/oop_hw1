#include "CController.h"
#include "UserInterface.h"
#include "MyList.h"
#include "IngredientData.h"
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
    // ���� ������ ����


    m_list.addNewNode(new CIngredientData("Tomato", "Tomato_Oct05", "Vegetable", "20251005", "LocalFarm", "120", "2500"));
    m_list.addNewNode(new CIngredientData("Milk", "Milk_Oct10", "Dairy", "20251010", "DailyDairy", "60", "1900"));
    m_list.addNewNode(new CIngredientData("Tomato", "Tomato_Oct18", "Vegetable", "20251018", "LocalFarm", "150", "2600"));
    m_list.addNewNode(new CIngredientData("Cheese", "Cheese_Oct20", "Dairy", "20251020", "DailyDairy", "75", "4100"));
    m_list.addNewNode(new CIngredientData("Apple", "Apple_Oct22", "Fruit", "20251022", "FruitKing", "130", "2300"));
    m_list.addNewNode(new CIngredientData("Beef", "Beef_Oct25", "Meat", "20251025", "MeatHouse", "40", "12800"));
    m_list.addNewNode(new CIngredientData("SoySauce", "Soy_Oct30", "Seasoning", "20251030", "KFoodMart", "55", "5800"));
    m_list.addNewNode(new CIngredientData("Salt", "Salt_Nov02", "Seasoning", "20251102", "KFoodMart", "300", "500"));
    m_list.addNewNode(new CIngredientData("Cabbage", "Cabbage_Nov10", "Vegetable", "20251110", "LocalFarm", "90", "2100"));
    m_list.addNewNode(new CIngredientData("Chicken", "Chicken_Nov15", "Meat", "20251115", "PoultryPlus", "80", "7500"));


	m_ui = new CUserInterface(*this);
}
// UI �����ڿ� Controller ���� �Ѱܼ� ����� ����

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
        case 7: checkIngredientExpiry(); break;
        case 8: showStatistics(); break;
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


    int nResult = m_list.addNewNode(new CIngredientData(name, id, Category, Expr, Supplier, Count, Price));
    if (nResult == 0)
    {
        puts("ERROR: �̹� �����ϴ� ����Դϴ�.");
        _getch();

    }

    else if (nResult == -1)
    {
        puts("ERROR: �߸� �Է��߽��ϴ�.");
        _getch();

    }

    printf("\n�ش� ��ᰡ ���������� ��ϵǾ����ϴ�. \n");
    printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n\n");
    _getch();
}

// Case 2
void CController::removeIngredient() {
    char idt[32];
    m_ui->inputIdt(idt);
    if (m_list.removeNode(idt))
        m_ui->printMessage("���� �Ϸ�.");
    else
        m_ui->printMessage("���� ����. �ش� ��� ����.");
}

//Case 4 ���� ����
void CController::showAllIngredients() {

	CListPrinter printer(m_list);    // Printer ���� 
	printer.printAll();   //  CMyList::printAll() �� CListPrinter�� �̰�
    
	/*CMyIterator iter = m_list.makeIterator();
    CIngredientData* pNode = nullptr;

    // model���� �����͸������� UI�� ��¿�û
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
    while (getchar() != '\n'); // flush

    switch (sel) {
    case 1: m_list.sortBy(SortType::NAME);
        break;
    case 2: m_list.sortBy(SortType::ID); 
        break;
    case 3: m_list.sortBy(SortType::Category); 
        break;
    case 4: m_list.sortBy(SortType::Expr); 
        break;
    default: puts("�߸��� �Է��Դϴ�.");  
        break;
    }
    //_getch();
}


/// ////////////////////////////////////////
/// case 3 - Search

void CController::searchIngredient() 
{
    CListFinder finder(m_list);      // Finder ����
    CListPrinter printer(m_list);    // Printer ����

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
    printf("5. Partial Search by Ingredient Name\n");
    printf("6. Show All Ingredients\n");
    printf("> ");

    scanf_s("%d", &choice);
    while (getchar() != '\n'); // flush

    char key[64] = { 0 };

    switch (choice) {

        //�̸�
    case 1:
        m_ui->inputName(key);
        printer.printNodes(finder.findByName(key));
        //  inline ȣ��(��� ��ȯ �� ��� ����)
        //   vector �ٷ� ����
        break;

        //�ĺ���
    case 2:
        m_ui->inputIdt(key);
        printer.printNodes(finder.findByIdt(key));
        break;

        // �з�
    case 3:
        m_ui->inputCategory(key);
        printer.printNodes(finder.findByCategory(key));
        break;

        //����ó
    case 4:
        m_ui->inputSupplier(key);
        printer.printNodes(finder.findBySupplier(key));
        break;

        // �κ� ���ڿ� �˻�
    case 5:
        printf("Enter partial name: ");
        scanf_s("%s", key, (unsigned)sizeof(key));  // �˻��� �Է� �ޱ�
        while (getchar() != '\n'); // flush

        {
            auto results = finder.findByPartialName(key);

            if (results.empty()) {
                printf("\n�˻� ����� �����ϴ�.\n");
            }
            else {
                printf("\n[�κ� �̸� �˻� ���]\n");
                printf("----------------------------------------------\n");
                for (auto pNode : results) {
                    CIngredientData* user = static_cast<CIngredientData*>(pNode);
                    user->printNode();
                }
                printf("----------------------------------------------\n");
                printf("�� %d�� �߰ߵ�.\n", (int)results.size());
            }

            printf("\n[1] Save and Return\n[2] Return without Saving\nSelect: ");
            int choice = 0;
            scanf_s("%d", &choice);
            while (getchar() != '\n'); // flush

            if (choice == 1) {
                printer.saveToFile(results, "ingredients_log.txt");
                printf("\n����� ingredients_log.txt ���Ͽ� ����Ǿ����ϴ�.\n");
            }

            printf("\n�޴��� ���ư����� �ƹ� Ű�� ��������...\n");

            _getch();
        }
        break;

    default:
        printf("Invalid choice.\n");
        _getch();
        break;

    case 6:
        printer.printAll();   //  CMyList::printAll() �� CListPrinter�� �̰�
        break;

    }
}

void CController::showStatistics() {
    system("cls");
    printf("==============================================\n");
    printf("                 [Statistics]\n");
    printf("==============================================\n\n");
    printf("1. Statistics by Ingredient\n");
    printf("2. Statistics by Ingredient Category\n");
    printf("3. Statistics by Supplier\n\n");
    printf("0. Return to Main Menu\n");
    printf("----------------------------------------------\n");
    printf("Select: ");

    int sel;
    scanf_s("%d", &sel);
    while (getchar() != '\n'); // flush

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


// 7. ������� �ӹ� �� ������ǰ Ȯ��
void CController::checkIngredientExpiry() {
    CListFinder finder(m_list);
    CListPrinter printer(m_list);

    puts("[DBG] BEFORE FOOTER"); fflush(stdout);
    // debgug


    int days;
    printf("������� �ӹ� ���� �ϼ� �Է� (��: 7): ");
    scanf_s("%d", &days);
    while (getchar() != '\n'); // ���� ����

    std::vector<CMyNode*> expiringSoon;
    std::vector<CMyNode*> expired;

    finder.findExprStatus(days, expiringSoon, expired);

    system("cls");
    printf("==================================================================================================\n");
    printf("                                     [Ingredient Expiry Status]\n");
    printf("===================================================================================================\n\n");
           //-------------------------------------------------------------------------------------------------- -
    if (expired.empty() && expiringSoon.empty()) {
        printf(" ��� ��ᰡ ���� ������� ���� �ֽ��ϴ�!\n");
        _getch();
        return;
    }

    // 1.����� ��ǰ ǥ��
    if (!expired.empty()) {
        printf(" [������� ���� ��� ���]\n");
        printf("---------------------------------------------------------------------------------------------------\n");
        printer.printSimpleList(expired);
        printf("\n");
    }

    //debgug
    puts("[DBG] AFTER FOOTER"); fflush(stdout);


    // 2. �ӹ� ��ǰ ǥ��
    if (!expiringSoon.empty()) {
        printf(" [������� %d�� �̳� �ӹ� ��� ���]\n", days);
        printf("---------------------------------------------------------------------------------------------------\n");
        printer.printSimpleList(expiringSoon);
        printf("\n");
    }

    printf("===============================================\n");
    printf("[1] ��ü ��� ���� �� ������\n");
    printf("[2] �׳� ������\n");
    printf("-----------------------------------------------\n");
    printf("����: ");

    int choice = 0;
    scanf_s("%d", &choice);
    while (getchar() != '\n'); // ���� ����

    if (choice == 1) {
        // �� ����� ���ļ� �� ���� ����
        std::vector<CMyNode*> combined;
        combined.reserve(expired.size() + expiringSoon.size());
        combined.insert(combined.end(), expired.begin(), expired.end());
        combined.insert(combined.end(), expiringSoon.begin(), expiringSoon.end());

        printer.saveToFile(combined, "ingredients_log.txt");

        printf("\n����� ingredients_log.txt ���Ͽ� �߰��Ǿ����ϴ�.\n");
    }

    printf("\n�޴��� ���ư����� �ƹ� Ű�� ��������...\n");
    _getch();
}