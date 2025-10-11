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

    std::vector<CMyNode*> findByName(const char* pszName);
    std::vector<CMyNode*> findByStudentID(const char* pszID);
    std::vector<CMyNode*> findByAdmissionYear(const char* pszYear);
    std::vector<CMyNode*> findByBirth(const char* pszBirth);
    std::vector<CMyNode*> findByDept(const char* pszDept);

    //�κ� ���ڿ� Ž�� �Լ�
    std::vector<CMyNode*> findByPartialName(const char* pszSubName);
};
