/************************************************************************/
/* ����:����                                                            */
/* DESӦ�üӽ���                                                        */
/************************************************************************/

#ifndef _ENDES_H
#define _ENDES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENCRYPT   0
#define DECRYPT   1
#define BYTE      unsigned char
#define WORD      unsigned short


	//PACK8 Pack 64 bytes at 1 bit/byte into 8 bytes at 8 bits/byte
	static void pack8(BYTE *packed,BYTE *binary);
	
	//UNPACK8 Unpack 8 bytes at 8 bits/byte into 64 bytes at 1 bit/byte
	static void unpack8(BYTE *packed,BYTE *binary);
	
	//���
	void Do_XOR(unsigned char *dest,unsigned char *source,int size);
	
	//���
	void BitXor(BYTE *Data1, BYTE *Data2, int Len, BYTE *Dest);
	
	//���üӽ��ܲ����Լ���Կ Decrypt: 0-���� 1-���� key:��Կ,8�ֽ�
	void DES_setkey( BYTE sw,BYTE *pkey);
	
	//DES����
	void DES_calcul(BYTE *in,BYTE *out);
	
	//�ӽ��ܺ��� Decrypt: 0-���� 1-���� key:��Կ,8�ֽ� Data:����,8�ֽ� Result:���,8�ֽ�
	void DES(BYTE Decrypt,BYTE *Key,BYTE *Data,BYTE *Result );
	
	//3DES�ӽ��ܺ��� Decrypt: 0-���� 1-���� key:��Կ,16�ֽ� Data:����,8�ֽ� Result:���,8�ֽ�
	void Triple_DES(BYTE Decrypt,BYTE* Key,BYTE* Data,BYTE* X_Data );
	
	//3DES�ӽ��ܺ��� Decrypt: 0-���� 1-���� key:��Կ,16�ֽ� Data:����,���Ȳ��� Result:���,���Ȳ���
	void CString_TripleDES_EncryptionA( BYTE * p_Key, CStringA  p_strSourceData, CStringA & p_strTargetData);


	//Key schedule of 16 48-bit subkeys generated from 64-bit key



#endif