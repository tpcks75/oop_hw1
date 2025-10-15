#include "CListPrinter.h"
#include "IngredientData.h"
#include "MyString.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <map>
#include <string>
#include <ctime>

#define PRINT_HEADER(title) \
    //printf("\n[Print - %s]\n", title); \
    printf("---------------------------------------------------------------------------------------------------\n"); \
    printf("%-15s %-20s %-15s %-15s %-15s %-10s %-10s""\n", \
           "Name", "Idt", "Category", "Expr", "Supplier", "Count", "Price"); \
    printf("---------------------------------------------------------------------------------------------------\n");

#define PRINT_FOOTER() \
    printf("---------------------------------------------------------------------------------------------------\n"); \
    //_getch();

CListPrinter::CListPrinter(CMyList& list)
    : m_list(list)
{
}

// ===============================================================
// 전체 출력
void CListPrinter::printAll()
{
    if (m_list.getHead()->getNext() == nullptr) {
        printf("List is empty.\n");
        _getch();
        return;
    }

    PRINT_HEADER("All Users");

    CMyIterator it = m_list.makeIterator();
    CIngredientData* pNode = nullptr;
    std::vector<CMyNode*> nodes;
    int count = 0;

    while ((pNode = static_cast<CIngredientData*>(it.GetCurrent())) != nullptr) {
        printf("%-15s %-20s %-15s %-15s %-15s %-10s % -10s\n",
            (const char*)pNode->getName(),
            (const char*)pNode->getIdt(),
            (const char*)pNode->getCategorytmp(),
            (const char*)pNode->getExpr(),    // Expr (유통기한)
            (const char*)pNode->getSupplier(),
            (const char*)pNode->getCount(),
            (const char*)pNode->getPrice()
        );
        nodes.push_back(pNode);
        it.MoveNext();
        count++;
    }

    printf("\n총 %d개 항목 출력 완료.\n", count);
    PRINT_FOOTER();

    int choice;
    printf("\n[1] Save and Return\n[2] Return without Saving\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1)
        saveToFile(nodes, "ingredients_log.txt");

    printf("\nReturning to main menu...\n");
    _getch();
}


// ===============================================================
// 검색 결과 출력 및 저장(다중결과용)
void CListPrinter::printNodes(const std::vector<CMyNode*>& nodes)
{
    if (nodes.empty()) {
        printf("검색 결과가 없습니다.\n");
        _getch();
        return;
    }

    PRINT_HEADER("Search Results");

    for (CMyNode* node : nodes) {
        CIngredientData* u = static_cast<CIngredientData*>(node);
        printf("%-15s %-20s %-15s %-15s %-15s %-10s %-10s\n",
            (const char*)u->getName(),
            (const char*)u->getIdt(),
            (const char*)u->getCategorytmp(),
            (const char*)u->getExpr(),
            (const char*)u->getSupplier(),
            (const char*)u->getCount(),
            (const char*)u->getPrice()
        );
    }

    PRINT_FOOTER();

    int choice;
    printf("\n[1] Save and Return\n[2] Return without Saving\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1)
        saveToFile(nodes, "ingredients_log.txt");

    printf("\nReturning to main menu...\n");
    _getch();
    
}

// 검색 결과 출력 (다중결과용)
void CListPrinter::printSimpleList(const std::vector<CMyNode*>& nodes)
{
    if (nodes.empty()) {
        printf("해당 목록이 비어 있습니다.\n");
        return;
    }

    PRINT_HEADER("Expiry Check Results");

    for (CMyNode* node : nodes) {
        CIngredientData* u = static_cast<CIngredientData*>(node);
        printf("%-15s %-20s %-15s %-15s %-15s %-10s %-10s\n",
            (const char*)u->getName(),
            (const char*)u->getIdt(),
            (const char*)u->getCategorytmp(),
            (const char*)u->getExpr(),
            (const char*)u->getSupplier(),
            (const char*)u->getCount(),
            (const char*)u->getPrice()
        );
    }

    PRINT_FOOTER();
}

/////////////////////////////// 통계 //////////////////////////////
// 재료 이름별 통계
void CListPrinter::printStatisticsByName(CMyList& list) {
    std::map<std::string, int> nameCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CIngredientData* u = static_cast<CIngredientData*>(p);

        std::string name((const char*)u->getName());
        nameCount[name]++;
        total++;
    }

    system("cls");
    printf(" [Statistics by Ingredient Name]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : nameCount)
        printf("  %-15s : %3d개\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  Total Ingredients : %d개\n", total);
    printf("\nReturning to main menu...\n");
    _getch();
}

// 재료 분류(Category)별 통계
void CListPrinter::printStatisticsByCategory(CMyList& list) {
    std::map<std::string, int> categoryCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CIngredientData* u = static_cast<CIngredientData*>(p);

        std::string category((const char*)u->getCategorytmp());
        categoryCount[category]++;
        total++;
    }

    system("cls");
    printf(" [Statistics by Ingredient Category]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : categoryCount)
        printf("  %-15s : %3d개\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  Total Ingredients : %d개\n", total);
    printf("\nReturning to main menu...\n");
    _getch();
}

// 공급처(Supplier)별 통계
void CListPrinter::printStatisticsBySupplier(CMyList& list) {
    std::map<std::string, int> supplierCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CIngredientData* u = static_cast<CIngredientData*>(p);

        std::string supplier((const char*)u->getSupplier());
        supplierCount[supplier]++;
        total++;
    }

    system("cls");
    printf(" [Statistics by Supplier]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : supplierCount)
        printf("  %-15s : %3d개\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  Total Ingredients : %d개\n", total);
    printf("\nReturning to main menu...\n");
    _getch();
}

///////////////////////////////// 파일 저장 //////////////////////////////
// 파일 저장
void CListPrinter::saveToFile(const std::vector<CMyNode*>& nodes, const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "a");
    if (!fp) {
        printf("파일 열기 실패.\n");
        return;
    }

    // 현재 시간
    time_t now = time(nullptr);
    struct tm localTime;
    localtime_s(&localTime, &now);

    fprintf(fp, "\n\n============== [Record Time: %04d-%02d-%02d %02d:%02d:%02d] ==============\n",
        localTime.tm_year + 1900,
        localTime.tm_mon + 1,
        localTime.tm_mday,
        localTime.tm_hour,
        localTime.tm_min,
        localTime.tm_sec);

    fprintf(fp, "%-15s %-20s %-15s %-15s %-15s %-10s %-10s\n",
        "Name", "Idt", "Category", "Expr", "Supplier", "Count", "Price");
    fprintf(fp, "---------------------------------------------------------------------------------------------------\n");

    for (CMyNode* node : nodes) {
        CIngredientData* u = static_cast<CIngredientData*>(node);
        fprintf(fp, "%-15s %-20s %-15s %-15s %-15s %-10s %-10s\n",
            (const char*)u->getName(),
            (const char*)u->getIdt(),
            (const char*)u->getCategorytmp(),
            (const char*)u->getExpr(),
            (const char*)u->getSupplier(),
            (const char*)u->getCount(),
            (const char*)u->getPrice()
        );
    }

    fclose(fp);
    printf("\nSaved successfully to %s\n", filename);
}