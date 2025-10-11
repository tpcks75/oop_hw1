#pragma once
#include "MyList.h"
#include "UserData.h"
// ����ó���� ���� STL
#include <vector>

class CListPrinter
{
private:
    CMyList& m_list;

public:
    CListPrinter(CMyList& list);
    ~CListPrinter() {}

    // ��ü ���
    void printAll();

    // Ư�� �˻� ���(����)�� ���� ���
    void printNodes(const std::vector<CMyNode*>& nodes);

    // ��� ���
    void printStatisticsByAdmissionYear(CMyList& list);
    void printStatisticsByBirthYear(CMyList& list);
    void printStatisticsByDepartment(CMyList& list);

    // �˻� ��� ���� ����
    void saveToFile(const std::vector<CMyNode*>& nodes, const char* filename);

    // ��ü ��� ���� ����
    void saveToFileAll(const char* filename);
};