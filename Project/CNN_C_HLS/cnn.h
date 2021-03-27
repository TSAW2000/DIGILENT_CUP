# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include <ReadImg.h>

//声明cnn主函数，供Top文件中主函数直接调用
void CNNBox(ImgArr inputData, int Output);

//卷积层
typedef struct conv_layer
{
    int inputWidth;   //输入图像的宽
	int inputHeight;  //输入图像的长

	int inChannels;   //输入图像的数目
	int outChannels;  //输出图像的数目

}ConvLayer;

//池化层
typedef struct pooling_layer
{
    int inputWidth;   //输入图像的宽
	int inputHeight;  //输入图像的长

	int inChannels;   //输入图像的数目
	int outChannels;  //输出图像的数目
}PoolLayer;

//全连接层
typedef struct Connect_Layer
{
    int inputWidth;   //输入图像的宽
	int inputHeight;  //输入图像的长

	int inChannels;   //输入图像的数目
	int outChannels;  //输出图像的数目
}OputLayer;

typedef struct cnn_network
{
    int layerNum;
    ConvLayer* C1;
    PoolLayer* P2;
    ConvLayer* C3;
    PoolLayer* P4;
    OputLayer* O5;
}CNN;



