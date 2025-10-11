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

// ��ü ��� (���� CMyList::printAll ���� �״��)
void CListPrinter::printAll()
{
    if (m_list.getHead()->getNext() == nullptr) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        _getch();
        return;
    }

    PRINT_HEADER("All Users");

    CMyIterator it = m_list.makeIterator();
    CUserData* pNode = nullptr;
    std::vector<CMyNode*> nodes; // ��� ��� ����� ����

    int count = 0;
    while ((pNode = static_cast<CUserData*>(it.GetCurrent())) != nullptr) {
        pNode->printNode();
        nodes.push_back(pNode); // ���Ϳ� �߰�
        it.MoveNext();
        count++;
    }
    printf("\n�� %d�� ��� �Ϸ�.\n", count);

    PRINT_FOOTER();

    int choice;
    printf("\n[1] �����ϰ� ���ư���\n[2] �׳� ���ư���\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        saveToFile(nodes, "file1.txt");  // ���͸� ����
    }

    printf("\nReturning to main menu...\n");
    _getch();
}

// �˻� ��� ��� (���� �����)
void CListPrinter::printNodes(const std::vector<CMyNode*>& nodes)
{
    if (nodes.empty()) {
        printf("�˻� ����� �����ϴ�.\n");
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
    printf("\n[1] �����ϰ� ���ư���\n[2] �׳� ���ư���\nSelect: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        saveToFile(nodes, "file1.txt");  //  file1.txt�� ����
    }

    printf("\nReturning to main menu...\n");
    _getch();

    //printf("�ƹ� Ű�� ������ �޴��� ���ư��ϴ�...\n");
    //_getch();
}

// ���г⵵�� ���
void CListPrinter::printStatisticsByAdmissionYear(CMyList& list) {
    // map���� �� �� ����
    std::map<std::string, int> admissionCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);
        // �й� �� 4�ڸ� ����
        std::string admissionYear(u->getStudentID(), 4);
        admissionCount[admissionYear]++;
        total++;
    }

    system("cls");
    printf(" [���г⵵�� ���]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : admissionCount)
        printf("  %s�й� : %d��\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  ��ü �ο� �հ� : %d��\n", total);
    _getch();
}

// ��������� ���
void CListPrinter::printStatisticsByBirthYear(CMyList& list) {
    std::map<std::string, int> birthCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);

        // ����⵵ (��: "2001") ���ڿ� �״�� ���
        std::string birthYear = u->getBirthYear();  // getBirthYear()�� const char* ��ȯ �� �״�� ����
        birthCount[birthYear]++;
        total++;
    }

    system("cls");
    printf(" [����⵵�� ���]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : birthCount)
        printf("  %s��� : %d��\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  ��ü �ο� �հ� : %d��\n", total);
    _getch();
}

// �а��� ���
void CListPrinter::printStatisticsByDepartment(CMyList& list) {
    std::map<std::string, int> deptCount;
    int total = 0;

    for (CMyNode* p = list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* u = static_cast<CUserData*>(p);

        // �а��� ���ڿ� �״�� ���
        std::string dept = u->getDepartment();   // getDepartment()�� const char* ��ȯ �� �״�� ����
        deptCount[dept]++;
        total++;
    }

    system("cls");
    printf(" [�а��� ���]\n");
    printf("----------------------------------------------\n");
    for (auto& pair : deptCount)
        printf("  %-20s : %2d��\n", pair.first.c_str(), pair.second);
    printf("----------------------------------------------\n");
    printf("  ��ü �ο� �հ� : %2d��\n", total);
    _getch();
}

// �˻� ��� ���� ����
void CListPrinter::saveToFile(const std::vector<CMyNode*>& nodes, const char* filename)
{
    FILE* fp;
    fopen_s(&fp, filename, "a"); // ��������
    if (!fp) {
        printf("���� ���� ����.\n");
        return;
    }

    //���� �ð� ��������
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
    printf("\n ���Ͽ� ���� ����Ǿ����ϴ�: %s\n", filename);
}