#pragma once

class CMyString
{
public:
	CMyString(void);
	explicit CMyString(const char* pszParam);
	CMyString(const CMyString & rhs);
	virtual ~CMyString(void);
	// ���ڿ� ����
	int setString(const char * pszParam);
	// ���ڿ� ��ȯ
	const char* getString(void) const { return m_pszData; }
	// ���ڿ� ���� ��ȯ
	int getLength(void) const
	{
		if (m_pszData == nullptr && m_nLength)
			m_nLength = 0;
		return m_nLength;
	}
private:
	// ���� �Ҵ�� �޸��� �ּҰ� ����� ���
	char *m_pszData;
	mutable int m_nLength;

public:
	void release(void);

	// ������ �����ε� 
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