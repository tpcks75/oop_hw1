#include "CListPrinter.h"
#include "UserData.h"
#include "MyString.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <map>
#include <string>
#include <ctime>

#define PRINT_HEADER(title) \
    printf("\n[Print - %s]\n", title); \
    printf("%-15s %-10s %-10s %-20s %-12s\n", \
           "Name", "StudentID", "Birth", "Department", "Tel"); \
    printf("---------------------------------------------------------------\n")

#define PRINT_FOOTER() \
    printf("---------------------------------------------------------------\n"); \
    //printf("Press any key to return...\n"); \
    _getch();

CListPrinter::CListPrinter(CMyList& list)
    : m_list(list)
{
}

// 전체 출력 (기존 CMyList::printAll 역할 그대로)
void CListPrinter::printAll()
{
    if (m_list.getHead()->getNext() == nullptr) {
        printf("리스트가 비어 있습니다.\n");
        _getch();
        return;
    }

    PRINT_HEADER("All Users");

    CMyIterator it = m_list.makeIterator();
    CUserData* pNode = nullptr;
    std::vector<CMyNode*> nodes; // 출력 노드 저장용 벡터

    int count = 0;
    while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
        pNode->printNode();
        nodes.push_back(pNode); // 벡터에 추가
        it.MoveNext();
        count++;
    }
    printf("\n총 %d명 출력 완료.\n", count);

    PRINT_FOOTER();

    int choice;
    printf("\n[1] 저장하고 돌아가기\n[2] 그냥 돌아가기\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        saveToFile(nodes, "file1.txt");  // 벡터를 전달
    }

    printf("\nReturning to main menu...\n");
    _getch();
}

// 검색 결과 출력 (다중 결과용)
void CListPrinter::printNodes(const std::vector<CMyNode*>& nodes)
{
    if (nodes.empty()) {
        printf("검색 결과가 없습니다.\n");
        _getch();
        return;
    }

    PRINT_HEADER("Search Results");

    for (CMyNode* node : nodes) {
        CUserData* pUser = static_cast<CUserData*>(node);
        pUser->printNode();
    }

    PRINT_FOOTER();

    int choice;
    printf("\n[1] 저장하고 돌아가기\n[2] 그냥 돌아가기\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        saveToFile(nodes, "file1.txt");  //  file1.txt에 저장
    }

    printf("\nReturning to main menu...\n");
    _getch();

    //printf("아무 키나 누르면 메뉴로 돌아갑니다...\n");
    //_getch();
}

// 입학년도별 통계
void CListPrinter::printStatisticsByAdmissionYear(CMyList& list) {
    // map으로 빈도 수 집계
    std::map<std::string, int> admissionCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);
        // 학번 앞 4자리 추출
        std::string admissionYear(u->getStudentID(), 4);
        admissionCount[admissionYear]++;
        total++;
    }

    system("cls");
    printf(" [입학년도별 통계]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : admissionCount)
        printf("  %s학번 : %d명\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  전체 인원 합계 : %d명\n", total);
    _getch();
}

// 출생연도별 통계
void CListPrinter::printStatisticsByBirthYear(CMyList& list) {
    std::map<std::string, int> birthCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);

        // 출생년도 (예: "2001") 문자열 그대로 사용
        std::string birthYear = u->getBirthYear();  // getBirthYear()이 const char* 반환 시 그대로 가능
        birthCount[birthYear]++;
        total++;
    }

    system("cls");
    printf(" [출생년도별 통계]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : birthCount)
        printf("  %s년생 : %d명\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  전체 인원 합계 : %d명\n", total);
    _getch();
}

// 학과별 통계
void CListPrinter::printStatisticsByDepartment(CMyList& list) {
    std::map<std::string, int> deptCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);

        // 학과명 문자열 그대로 사용
        std::string dept = u->getDepartment();   // getDepartment()이 const char* 반환 시 그대로 가능
        deptCount[dept]++;
        total++;
    }

    system("cls");
    printf(" [학과별 통계]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : deptCount)
        printf("  %-20s : %2d명\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  전체 인원 합계 : %2d명\n", total);
    _getch();
}

// 검색 결과 파일 저장
void CListPrinter::saveToFile(const std::vector<CMyNode*>& nodes, const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "a"); // 누적저장
    if (!fp) {
        printf("파일 열기 실패.\n");
        return;
    }

    //현재 시간 가져오기
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

    fprintf(fp, "%-15s %-10s %-10s %-20s %-12s\n",
        "Name", "StudentID", "Birth", "Department", "Tel");
    fprintf(fp, "================================================================\n");

    for (CMyNode* node : nodes) {
        CUserData* u = static_cast<CUserData*>(node);
        fprintf(fp, "%-15s %-10s %-10s %-20s %-12s\n",
            u->getName(), u->getStudentID(), u->getBirthYear(),
            u->getDepartment(), u->getTel());
    }

    fclose(fp);
    printf("\n 파일에 누적 저장되었습니다: %s\n", filename);
}