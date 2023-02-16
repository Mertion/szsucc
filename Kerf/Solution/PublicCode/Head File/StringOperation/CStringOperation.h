#pragma once

class CStringOperation
{
public:

	static int CopyCStringToCharA(OUT char * p_cstrTarget, IN int p_nCharSizeOf, IN CStringA p_strSource);

	static int CopyCharToCharA(OUT char * p_cstrTarget, IN int p_nCharSizeOf, IN char * p_cstrSource);

	static int ctoi(char cSingle);
	static BOOL BCD2ASC(char *strBCD, char *strASC, int lenBCD);
	static int AscToInt(char cIn);
	static BOOL ASC2BCD(char *strASC, char *strBCD, int lenBCD);

	//��ȡXML��ָ��������ֵ
	//���� true-��ȡ�ɹ���false-��ȡʧ��
	static bool getXMLKEYValueForInt(IN CString p_strXML, IN CString p_strKEY, OUT int & p_nValue, IN int t_nDefaultValue);
	//��ȡXML��ָ�������ַ���
	//���� true-��ȡ�ɹ���false-��ȡʧ��
	static bool getXMLKEYValueForString(IN CString p_strXML, IN CString p_strKEY, OUT CString & p_strValue);
};

