#pragma once
#include "MyList.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <vector>

//  ����Ʈ �˻� ���� Ŭ���� (has-a ����)
class CListFinder
{
private:
    CMyList& m_list;

public:
    CListFinder(CMyList& list);
    ~CListFinder() {}

    //��� �̸�, �ĺ���, �з�, ����ó
    std::vector<CMyNode*> findByName(const char* pszName);
    std::vector<CMyNode*> findByIdt(const char* pszID);
    std::vector<CMyNode*> findByCategory(const char* pszCategory);
    //std::vector<CMyNode*> findByAdmissionYear(const char* pszYear);
    std::vector<CMyNode*> findBySupplier(const char* pszExpr);

    //�κ� ���ڿ� Ž�� �Լ�
    std::vector<CMyNode*> findByPartialName(const char* pszSubName);

 
    // ������� �ӹ� �� ���� ��� �˻�
    void findExprStatus(int days,
        std::vector<CMyNode*>& expiringSoon,
        std::vector<CMyNode*>& expired);




};
