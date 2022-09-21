# 数字逻辑与计算机组成实验六 单周期 CPU 设计与测试 实验报告 

## 一、实验目的

1. 了解指令执行过程及其与 CPU 基本结构之间的关系。
2. 掌握单周期数据通路及其控制器的设计方法。 
3.  掌握 RISC-V 汇编语言程序的基本设计方法。 
4. 理解汇编语言程序与机器语言代码之间的对应关系。

## 二、实验环境

Logisim：https://github.com/Logisim-Ita/Logisim RISC-V 模拟器工具 RARS：https://github.com/thethirdone/rars

## 三、实验内容

进行单周期 CPU 设计与测试。支持9 条 RV32I 目标指令的单周期 CPU 结构

![image-20220530185640805](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530185640805.png)

#### 1. 控制器设计实验

##### 原理图及电路图

![image-20220530190600492](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530190600492.png)

![image-20220530193026683](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530193026683.png)

##### 功能表

![image-20220530193100510](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530193100510.png)

##### 仿真测试

![image-20220530193456296](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530193456296.png)



##### 错误现象及分析

无

#### 2. 单周期 CPU 设计实验

##### 原理图及电路图

![image-20220530195211651](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530195211651.png)

##### 输入输出引脚

instr:

op 操作码 funct3 功能码

rd 目标寄存器 rs1 rs2 源寄存器 funct7额外功能码

extop 扩展方式 imm扩展的立即数

##### 仿真测试

见 3 4 实验

##### 错误现象及分析

由于按照pdf文件描述更改了寄存器堆和pc的触发方式，导致死循环QWQ

#### 3. 用累加和程序进行 CPU 设计验证

##### 原理图及电路图

见实验2

##### 输入输出引脚

同实验2

##### 仿真测试

在 RARS 的编辑窗口中编写汇编语言源程序并进行保存

![image-20220530201932235](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530201932235.png)

![image-20220530205146002](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530205146002.png)

##### 错误现象及分析

无

#### 4. 用冒泡排序程序进行 CPU 设计验证

##### 原理图及电路图

同上

##### 输入输出引脚

同上

##### 仿真测试

![image-20220530210308172](C:\Users\Hooder\AppData\Roaming\Typora\typora-user-images\image-20220530210308172.png)

##### 错误现象及分析

无