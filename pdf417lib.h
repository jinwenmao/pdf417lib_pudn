/******************************************************************************
 * �ļ�����pdf417lib.h
 * ����  ����������ͷ�ļ�
 * modified by PRTsinghua@hotmail.com
******************************************************************************/

#ifndef __PDF417LIB_H__
#define __PDF417LIB_H__

#define PDF417_USE_ASPECT_RATIO     0
#define PDF417_FIXED_RECTANGLE      1
#define PDF417_FIXED_COLUMNS        2
#define PDF417_FIXED_ROWS           4
#define PDF417_AUTO_ERROR_LEVEL     0
#define PDF417_USE_ERROR_LEVEL      16
#define PDF417_USE_RAW_CODEWORDS    64
#define PDF417_INVERT_BITMAP        128

#define PDF417_ERROR_SUCCESS        0
#define PDF417_ERROR_TEXT_TOO_BIG   1
#define PDF417_ERROR_INVALID_PARAMS 2


typedef struct _pdf417param {
    char *outBits;		// �����bitλ
    int lenBits;		// ����
    int bitColumns;
    int codeRows;		// ����
    int codeColumns;	// ����	
    int codewords[928];	// ����
    int lenCodewords;	// ���ָ���
    int errorLevel;		// �����뼶��
    char *text;			// �ı�
    int lenText;		// �ı�����
    int options;		// ѡ��
    float aspectRatio;	
    float yHeight;
    int error;
} pdf417param, *pPdf417param;

/******************************************************************************
 * ����PDF417������
******************************************************************************/
void paintCode(pPdf417param p);

/******************************************************************************
 * ��ʼ��PDF417������
******************************************************************************/
void pdf417init(pPdf417param param);

/******************************************************************************
 * �ͷ�PDF417������
******************************************************************************/
void pdf417free(pPdf417param param);

#endif
