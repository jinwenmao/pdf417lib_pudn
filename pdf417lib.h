/******************************************************************************
 * 文件名：pdf417lib.h
 * 功能  ：条形码库的头文件
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
    char *outBits;		// 输出的bit位
    int lenBits;		// 长度
    int bitColumns;
    int codeRows;		// 层数
    int codeColumns;	// 列数	
    int codewords[928];	// 码字
    int lenCodewords;	// 码字个数
    int errorLevel;		// 纠错码级别
    char *text;			// 文本
    int lenText;		// 文本长度
    int options;		// 选项
    float aspectRatio;	
    float yHeight;
    int error;
} pdf417param, *pPdf417param;

/******************************************************************************
 * 绘制PDF417条形码
******************************************************************************/
void paintCode(pPdf417param p);

/******************************************************************************
 * 初始化PDF417条形码
******************************************************************************/
void pdf417init(pPdf417param param);

/******************************************************************************
 * 释放PDF417条形码
******************************************************************************/
void pdf417free(pPdf417param param);

#endif
