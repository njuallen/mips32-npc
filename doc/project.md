# 项目介绍

我们项目的名字是mips32-npc，即NJU Processor Collection。即我们这个会是一系列的处理器。我们现在只有mips32_npc这一个处理器，未来我们可能会加进去更多。参照emulator目录和srcmulu下的结构，我们可以看到都分为了commom和mips32_npc，common中是所有处理器共有的部分，而其他目录下，则是每个处理器自己的设计。

## 项目目录

* *project* scala sbt的工程定义  
* *emulator* 仿真需要的verilog，cpp文件及脚本
* *src* scala源文件
* *common*和*mips32_npc*等文件夹下都是scala编译产生的class文件，我们不用关心

## 仿真流程

我们写的chisel，实际上就是scala，我们执行scala代码，会在emulator/mips32_npc/generated_src目录下生成Top模块对应的verilog文件Top.v。我们用verilator将verilog转成cpp，顶层模块就变成了一个名为VTop的C++类。我们在emulator.cpp中实例化并执行这个类，就可以仿真CPU的运行。以下是emulator/common/emulator.cpp中的一段代码：
```
VTop dut; // 实例化我们的CPU

// 设置CPU的输入信号的值
dut.reset = 1;
// 下面四行代码，就跑完了一个时钟周期，一个时钟周期包括一个高电平，加一个低电平
dut.clock = 0;
dut.eval();
dut.clock = 1;
dut.eval();

// 打印Top模块一个输出的信号
cout << dut.io_di_pc;
```

## 内存映射及外设

在仿真时，内存及外设是用verilog及C++代码进行仿真的，他们的代码都在emulator/common目录下。其中外设现在只做到了AM中TRM的状态，支持trap，支持uart接口。
在内存映射上，与AM中mips32-npc的arch保持一致，mips32-npc的代码编译之后可以直接用于我们的仿真。

同时，我们对内存及外设的读写都是可以在一个周期内完成的。

## 可测试性设计

通过verilator，verilog代码被转成了C++代码，我们写的代码就可以和CPU设计进行交互了。基于此，我们的CPU进一步加强了可测试性设计。我们定义了DebugIO接口，Top模块的接口中应包含此接口。我们在仿真时，有一个类似PA的monitor将会通过此接口与CPU进行交互。monitor可以支持周期级或者指令级的单步执行，同时可以查看pc和通用寄存器的值。未来，在mips32-nemu实现完成后，还将支持指令级的crosscheck。
DebugIO接口定义如下：
```
// external debug interface
class DebugIO extends Bundle
{
  val reg = Input(Vec(32, UInt(conf.xprlen.W)))
  val pc = Input(UInt(conf.xprlen.W))
  // number of instruction retired
  val ninstr_retired = Input(UInt(64.W))
  // freeze precessor
  val freeze = Output(Bool())
}
```
这只是初步的接口设计，其中reg和pc接口在实现时，只需要直接将pc和reg连出去就行了。ninstr_retired应该连到一个counter上，freeze是用来freeze住处理器的，所谓冻结状态，就是阻止处理器状态变化，即停止对寄存器、内存等状态元件的更新。

## 开发调试

使用chisel进行调试非常方便，直接使用printf即可，printf最后会被转成verilog中的fwrite。值得注意的是，verilog在仿真时，组合逻辑电路的执行在先，等组合逻辑稳定下来后，才会执行fwrite等function/task，在最后才会执行阻塞赋值语句。具体到verilator上，寄存器等的赋值总是在clock为高电平的最后执行的。这对于理解monitor和printf的某些输出非常重要。
例如下面的例子：
```
VTop dut; // 实例化我们的CPU

// 设置高电平
dut.clock = 1;
// 执行直到电路收敛，在此过程中，我们的chisel代码printf的pc值会被输出
dut.eval();

// 从Top的接口中读取pc
cout << dut.io_di_pc;
```
在上面的这个例子中，两处输出的pc值会是不同的，因为寄存器更新是在printf之后执行的。

## git使用注意点

在每次准备commit时，请不要直接使用`git add .`直接添加所有修改，这会导致好多scala编译的中间文件被加进去，请对照`git status`的输出，小心地一项一项地添加。欢迎帮助我们写出更完备的gitignore文件。 
