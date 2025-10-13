#pragma once
#include "MyList.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <vector>

//  리스트 검색 전용 클래스 (has-a 관계)
class CListFinder
{
private:
    CMyList& m_list;

public:
    CListFinder(CMyList& list);
    ~CListFinder() {}

    std::vector<CMyNode*> findByName(const char* pszName);
    std::vector<CMyNode*> findByIdt(const char* pszID);
    std::vector<CMyNode*> findByAdmissionYear(const char* pszYear);
    std::vector<CMyNode*> findByCategory(const char* pszCategory);
    std::vector<CMyNode*> findByExpr(const char* pszExpr);

    //부분 문자열 탐색 함수
    std::vector<CMyNode*> findByPartialName(const char* pszSubName);
};
