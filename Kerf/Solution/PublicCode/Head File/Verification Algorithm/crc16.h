#ifndef _CRC16_H
#define _CRC16_H
/*
����˵��
crc: ����crc����,ͨ����ʹ��0;
buf: ԭʼ����.
len: ���ݳ���.
����ֵ: ���ظ����������ݼ������CRC��,�����ֽ�

*/
unsigned short crc16(unsigned short crc, unsigned char *buf, unsigned int len);
#endif				/* crc16.h */
