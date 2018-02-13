/******************************************************************************
 * �ļ�����pdf417.c
 * ����  ����ӡ�����룬���������浽*.ps�ļ���
 * modified by PRTsinghua@hotmail.com
******************************************************************************/

#include "pdf417lib.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    pdf417param p;
    FILE* f;
    pdf417init(&p);
    
	if (argc < 3) 
	{
        printf("PDF417 ������ postscript ������\n"
            "��ʾ: �������¸�ʽ��������\n"
			"pdf417 filename.ps �������ı�\n");
        return 0;
    }
    
	p.text = argv[2];
    p.options = PDF417_INVERT_BITMAP;
    paintCode(&p);
    
	if (p.error) 
	{
        pdf417free(&p);
        return 0;
    }
    
	f = fopen(argv[1], "wb");
    if (f) 
	{
        int cols = p.bitColumns / 8 + 1;
        int k;
        fprintf(f, "/Times findfont\n12 scalefont setfont\n100 80 moveto\n(A PDF417 example.)show\n");
        fprintf(f, "stroke\n100 100 translate\n%g %g scale\n", p.bitColumns/2.0, p.codeRows * 3/2.0);
        fprintf(f, "%d %d 1 [%d 0 0 %d 0 %d]{<", p.bitColumns, p.codeRows, p.bitColumns, -p.codeRows, p.codeRows);
        for (k = 0; k < p.lenBits; ++k) {
            if (!(k % cols))
                fprintf(f, "\n");
            fprintf(f, "%02X", (int)p.outBits[k] & 0xff);
        }
        fprintf(f, "\n>}image\nshowpage\n");
        fclose(f);
    }
    
    pdf417free(&p);
    return 0;
}
