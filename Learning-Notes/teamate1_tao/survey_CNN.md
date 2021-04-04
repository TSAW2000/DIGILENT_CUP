# FPGA加速卷积神经网络

*部分超链接已失效，论文不另附*

捋了下思路，重点还得在FPGA上完成SoC的设计，完成任务点就能保底个奖，能不能拿牛一点的奖还得看应用上的花怎么开，于是拿神经网络出来提升一下格调。

Digilent杯和Arm杯都打算做FPGA加速神经网络，调研了一下确实这玩意比较火，是个东西和AI交叉一下都好像很牛的样子，奈何我对神经网络也没深究过，更别说FPGA加速了，~~仔细一想要做的加速到底是加速个什么劲？~~我就理解为CNN在FPGA上的部署了。

本质很简单，使用Verilog实现了一些CNN的模块。~~好像几乎没有多少实用价值。~~ 大多数FPGA加速CNN运行推断，不能学习，所以没有后向传播~~这不怪大家，Xilinx自己都已经放弃治疗了？~~。但是如果正儿八经用Verilog把CNN写出来呢确实还是相当复杂的~~毕竟我在邵老师的栽培下确实没有掌握什么FPGA的开发技能~~，还得靠邸志雄老师推荐的《数字积木》那本书愣是帮我补了点FPGA的基础，但是真要自己仿照个像tensorflow那样的框架把正儿八经的CNN（还得带时序?）自己写出来臣妾确实没法保证能做出来。

坑已经挖了，怎么实现的问题很大，疯狂找论文找开源，勉强算是列出下面的三种方案，但是具体的实现细节一时半会也看不懂，~~只能嘴上扯一些术语装作懂的样子~~，所以具体方案的取舍以及可实现性还希望老师指点以及同学们一起探讨研究了。~~Hxd们快来帮帮忙啊我淦~~

## 方案一

先在pc上训练好cnn网络模型，然后对其各层分析，利用Viivado编写神经网络单元，包括计算核心，DSP，控制器等模块，然后将各个模块实例化为完整的卷积加速模块，封装为IP然后集成在Soc系统上。

参考论文：
[基于FPGA的CNN加速SoC系统设计_赵烁](file:///E:/work/FPGA/digilent/%E5%9F%BA%E4%BA%8EFPGA%E7%9A%84CNN%E5%8A%A0%E9%80%9FSoC%E7%B3%BB%E7%BB%9F%E8%AE%BE%E8%AE%A1_%E8%B5%B5%E7%83%81.pdf)
[基于FPGA的卷积神经网络的实现与验证_王慈航](E:\work\FPGA\digilent\基于FPGA的卷积神经网络的实现与验证_王慈航.caj)
[基于FPGA的高性能MobileNet硬件加速器_郭良蛟](E:\work\FPGA\digilent\基于FPGA的高性能MobileNet硬件加速器_郭良蛟.caj)
与此相关的论文非常非常非常多，但是verilog还得自己写所以~~都没什么卵用~~

淘宝上购买的以及github上开源的是写好的诸如卷积核池化层等模块，理论上可以分别封装成ip然后组成加速单元，可行性以及如何写testbench还在研究中。我就把淘宝买的和github上找到的也附上了，有兴趣的hxd帮我看看怎么用。

该方案包含了网络的具体分析，之后需要用verilog写出各个模块，全部自己写不现实我也做不到，如果手上的这些别人写好的各个模块.v可行可用，则该方案可以采用。

许安杰同学已经在tensorflow下用keras库训练好了一个神经网络但是怎么导出参数啥的以及具体的网络结构还有待研究。

-------

## 方案二

搜索Xilinx官方的Vitis资料竟然发现这上面自带了官方提供的FPGA加速器

介绍一下[**Vitis**](https://china.xilinx.com/products/design-tools/vitis.html)，是Xilinx统一了Vivado，XilinxSDK，并集成了常用开源IP核，推出的Vitis统一软件平台，提供了各种各样的加速库，就不需要关注底层的Verilog实现，可以直接调用进行开发。

再介绍一下[**DPU**](https://china.xilinx.com/products/intellectual-property/dpu.html)：xilinx官方面向卷积神经网络的DPU：可将 DPU IP 作为一个模块集成到所选 Zynq 上，不过官网只提到了Zynq板，纯FPGA板似乎不能用



-----

## 方案三

利用**Xilinx SDSoc**（[官方教程](https://github.com/Xilinx/SDSoC-Tutorials)）开发套件（[安装教程](http://blog.eetop.cn/blog-1674693-6943425.html?_dsign=c2e07c0d)），直接将C/C++代码综合成FPGA电路（[官方综合手册](https://www.xilinx.com/support/documentation/sw_manuals/xilinx2018_2/ug902-vivado-high-level-synthesis.pdf)），不涉及HDL的编写，只需要修改代码中的卷积层结构相关的参数就可以移植入提起卷积神经网络算法。
Xilinx SDSoc参考开源项目：[Accelerate CNN computation with FPGA](https://github.com/WalkerLau/Accelerating-CNN-with-FPGA)

亦可直接选用**Pynq板**，该板也属于Zynq板，可以直接通过python语言对PS端进行开发设计，然后使用C/C++对PL端进行编程（Vivado HLS工具）。
参考论文：[基于FPGA的卷积神经网络的IP化设计与实现_邹翔熙](E:\work\FPGA\digilent\基于FPGA的卷积神经网络的IP化设计与实现_邹翔熙.caj)（作者本机路径）（这篇论文写得非常详细并且提供了许多伪代码）

移植相对简单，也不涉及HDL的编写，但是需要板载linux，而且大多为c语言编程所以不太符合digilent杯大赛主办方的意图？但是arm杯去年的人脸识别就是采用HLS直接把C转为HDL语言的，所以这个方案还算比较稳健？~~说得好像我用C就能写出来一样~~。

------