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

// 학번으로 검색
std::vector<CMyNode*> CListFinder::findByStudentID(const char* pszID)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strcmp(pUser->getKey(), pszID) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

// 입학년도(학번 앞 4자리)로 검색
std::vector<CMyNode*> CListFinder::findByAdmissionYear(const char* pszYear)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strncmp(pUser->getAdmissionYear(), pszYear, 4) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}

// 생년으로 검색
std::vector<CMyNode*> CListFinder::findByBirth(const char* pszBirth)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (strcmp(pUser->getBirthYear(), pszBirth) == 0)
        {
            results.push_back(pTmp);
        }
    }

    return results;
}
// 학과로 검색
std::vector<CMyNode*> CListFinder::findByDept(const char* pszDept)
{
    std::vector<CMyNode*> results;

    for (CMyNode* pTmp = m_list.getHead()->getNext();
        pTmp != nullptr; pTmp = pTmp->getNext())
    {
        CUserData* pUser = static_cast<CUserData*>(pTmp);
        if (_stricmp(pUser->getDepartment(), pszDept) == 0)
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