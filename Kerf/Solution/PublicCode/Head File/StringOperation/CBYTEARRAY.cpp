#include "stdafx.h"
#include "CBYTEARRAY.h"


CBYTEARRAY::CBYTEARRAY()
{
	m_BYTEArray = NULL;
	m_ulArraySize = 0;
}


CBYTEARRAY::~CBYTEARRAY()
{
	Empty();
}

//************************************
// Method:    PushBack
// FullName:  CBYTEARRAY::PushBack
// Access:    public 
// Returns:   void
// Qualifier: ������ĩ��׷������
// Parameter: IN BYTE * p_pBYTEArray         ׷������
// Parameter: IN unsigned long p_ulArraySize ׷�����ݳ���
//************************************
void CBYTEARRAY::PushBack(IN BYTE * p_pBYTEArray, IN unsigned long p_ulArraySize)
{
	unsigned long t_ulArrayLen = m_ulArraySize + p_ulArraySize;
	BYTE * t_pBYTEArray = new BYTE[t_ulArrayLen];

	if (0 != m_ulArraySize)
	{
		memcpy(t_pBYTEArray, m_BYTEArray, m_ulArraySize);
		delete[] m_BYTEArray;
	}
	memcpy(t_pBYTEArray + m_ulArraySize, p_pBYTEArray, p_ulArraySize);

	m_ulArraySize = t_ulArrayLen;
	m_BYTEArray = t_pBYTEArray;
}

//************************************
// Method:    GetBYTE
// FullName:  CBYTEARRAY::GetBYTE
// Access:    public 
// Returns:   unsigned long							������ݳ���
// Qualifier: ��ָ��λ�û�ȡ�����е�����
// Parameter: IN unsigned long p_ulStartPosition	��ȡ���
// Parameter: IN unsigned long p_ulLen				��ȡ����
// Parameter: OUT BYTE * p_pBYTEArray				��������ָ��
//************************************
unsigned long CBYTEARRAY::GetBYTE(IN unsigned long p_ulStartPosition, IN unsigned long p_ulLen, OUT BYTE * p_pBYTEArray)
{
	unsigned long t_ulLen = p_ulStartPosition + p_ulLen;

	//�ж�����Ƿ񳬹����鳤��
	if (p_ulStartPosition > m_ulArraySize)
	{
		return 0;
	}

	//�ж�Ҫ��ȡ�������Ƿ񳬹����鳤��
	if (t_ulLen > m_ulArraySize)
	{
		t_ulLen = m_ulArraySize - p_ulStartPosition;
	} 
	else
	{
		t_ulLen = t_ulLen - p_ulStartPosition;
	}
	memcpy(p_pBYTEArray, m_BYTEArray + p_ulStartPosition, t_ulLen);
	return t_ulLen;
}

//************************************
// Method:    GetBYTE
// FullName:  CBYTEARRAY::GetBYTE
// Access:    public 
// Returns:   unsigned long				������ݳ���
// Qualifier: ��ȡ��������������
// Parameter: IN unsigned long p_ulSize	�������������С 
// Parameter: OUT BYTE * p_pBYTEArray	������������ָ��
//************************************
unsigned long CBYTEARRAY::GetBYTE(IN unsigned long p_ulSize, OUT BYTE * p_pBYTEArray)
{
	unsigned long t_ulLen = p_ulSize;
	if (t_ulLen > m_ulArraySize)
	{
		t_ulLen = m_ulArraySize;
	} 
	else
	{
	}
	memcpy(p_pBYTEArray, m_BYTEArray, t_ulLen);
	return t_ulLen;
}

//************************************
// Method:    GetSize
// FullName:  CBYTEARRAY::GetSize
// Access:    public 
// Returns:   unsigned long
// Qualifier: ��ȡ�����С
//************************************
unsigned long CBYTEARRAY::GetSize()
{
	return m_ulArraySize;
}

//************************************
// Method:    Empty
// FullName:  CBYTEARRAY::Empty
// Access:    public 
// Returns:   void
// Qualifier: �������
//************************************
void CBYTEARRAY::Empty()
{
	m_ulArraySize = 0;
	delete[] m_BYTEArray;
	m_BYTEArray = NULL;
}
