#pragma once

class CMyString
{
public:
	CMyString(void);
	explicit CMyString(const char* pszParam);
	CMyString(const CMyString & rhs);
	virtual ~CMyString(void);
	// 문자열 설정
	int setString(const char * pszParam);
	// 문자열 반환
	const char* getString(void) const { return m_pszData; }
	// 문자열 길이 반환
	int getLength(void) const
	{
		if (m_pszData == nullptr && m_nLength)
			m_nLength = 0;
		return m_nLength;
	}
private:
	// 동적 할당된 메모리의 주소가 저장될 멤버
	char *m_pszData;
	mutable int m_nLength;

public:
	void release(void);

	// 연산자 오버로딩 
	CMyString& operator =(const CMyString &strParam);
	CMyString& operator =(const char * pszParam);
	CMyString operator +(const CMyString & rhs);
	int append(const char* pszParam);
	CMyString operator +(const char* pszParam);
	friend CMyString operator + (const char *, const CMyString &);

	operator const char * () const
	{
		return m_pszData;
	}

	int testFunc(const char* pszParam);
	virtual int onSetString(const char*);
};