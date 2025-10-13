#include "CListFinder.h"
#include "UserData.h"
#include "MyNode.h"
#include "MyList.h"
#include <cstring>
#include <vector>

CListFinder::CListFinder(CMyList& list)
    : m_list(list)
{
}

// data vector로 저장
// 이름으로 검색
std::vector<CMyNode*> CListFinder::findByName(const char* pszName)
{
    std::vector<CMyNode*> results;   //  결과 저장용

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getName(), pszName) == 0)
        {
            results.push_back(pTmp); //  일치 시 vector에 저장
        }
    }

    return results; //  출력은 하지 않고 결과만 반환
}

// 식별자로 검색
std::vector<CMyNode*> CListFinder::findByIdt(const char* pszID)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strcmp(pUser->getIdt(), pszID) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}


// 목록으로 검색
std::vector<CMyNode*> CListFinder::findByCategory(const char* pszCategory)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getCategorytmp(), pszCategory) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}
// 공급처로 검색
std::vector<CMyNode*> CListFinder::findBySupplier(const char* pszExpr)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getSupplier(), pszExpr) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

//부분 문자열 탐색 
std::vector<CMyNode*> CListFinder::findByPartialName(const char* pszSubName) {
    std::vector<CMyNode*> results; //  결과 저장용 벡터

    for (CMyNode* p = m_list.getHead()->getNext(); p != nullptr; p = p->getNext()) {
        CUserData* user = static_cast<CUserData*>(p);

        //  MyString 변환 후 부분 문자열 검색
        CMyString tempName(user->getName()); // const char* → CMyString
        if (tempName.Find(pszSubName) != -1) {
            results.push_back(user); // 일치하는 사용자 추가
        }
    }

    return results; // vector<CUserData*> 반환
}