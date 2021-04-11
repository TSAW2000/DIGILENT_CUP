# ZYNQ

带硬核的ZYNQ的平台设计选用带有硬核处理器的[DIGILENT全系列ZYNQ平台](http://www.digilent.com.cn/products/fpga.html)
包括ZYNQ7000以及ZYNQ MPSoC系列

**DIGILENT官网板：**
[Zybo Z7：](http://www.digilent.com.cn/products/product-zybo-z7-20.html)Zynq-7000 ARM/FPGA SoC开发板，核心芯片为XC7Z020-1CLG400C，包括一个兼容MIPI CSI-2的Pcam（摄像头模块）接口，HDMI输入输出，音频接口，1G高带宽DDR3L，16MB Flash，microUSB卡槽。
<u>官方教学视频推荐的就是这个板子</u>

**官网外设：**
[Pcam 5C：](http://www.digilent.com.cn/products/proinfo/456.html)是一款适用于FPGA（ZYBO Z7）开发板的成像模块。 
[FMC Pcam（CSI-2接口）适配器：](http://www.digilent.com.cn/products/proinfo/474.html)适配器可与Digilent的Pcam相机解决方案配合使用。
[PmodDPG1：](http://www.digilent.com.cn/products/pmoddpg1-differential-pressure-gauge-sensor.html)压差计模块。板载有压阻传感器和ADC，检测出两个端口之间的压差接PMOD口
[PmodCLS：](http://www.digilent.com.cn/products/product-pmodcls.html)带有串行接口的字符型LCD，16x2字符的显示器。

**第三方外设：**
[OV5640：](https://www.cnblogs.com/xuexizhe/p/8710063.html)CMOS类型数字图像传感器。<u>去年集创赛arm杯上开源作品都用的是这个摄像头</u>

**开发软件：**
Xilinx ISE WebPack(XPS,SDK)
Vivado
Tera Term(串口调试器)
<u>官方推荐了这三个，仅用vivado也足够</u>

**开发主要思路：**

1. PS双核，PL移植cortex-M3软核，运行linux
2. 配置外设，包括摄像头采集HDMI输出，压差计模块输入LCD显示屏显示
3. 分析神经网络训练过程算法设计FPGA运算单元
4. 编写linux下FPGA加速器的驱动程序和接口
5. 训练神经网络，进行优化

