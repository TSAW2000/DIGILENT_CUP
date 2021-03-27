#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct MinstImgArr{
	int Imageheight;
	int Imageweight;
	
}*ImgArr;              // 存储图像数据的数组


ImgArr read_Img(const char* filename); // 读入图像