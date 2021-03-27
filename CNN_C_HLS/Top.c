# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# include <ReadImg.h>
# include <cnn.h>


int main()
{
    //头文件<ReadImg.h>中定ImgArr结构体
    //LabelArr Label = read_Lable("路径");
    ImgArr Img = read_Img("路径"); //读取图片与标签

    float res = 0.0; //定义输出结果
    res = CNN_Box(Img); //卷积神经网络函数

    return 0;
}
