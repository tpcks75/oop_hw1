#pragma once
#include "MyList.h"
#include "IngredientData.h"
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

    // Ư�� �˻� ���(����)�� ���� ���(������� �� ����)
    void printNodes(const std::vector<CMyNode*>& nodes);

    // Ư�� �˻� ���(����)�� ���� ���(�������)
    void printSimpleList(const std::vector<CMyNode*>& nodes);

    // ��� ���
    void printStatisticsByName(CMyList& list);
    void printStatisticsByCategory(CMyList& list);
    void printStatisticsBySupplier(CMyList& list);

    // �˻� ��� ���� ����
    void saveToFile(const std::vector<CMyNode*>& nodes, const char* filename);

    // ��ü ��� ���� ����
    void saveToFileAll(const char* filename);
};