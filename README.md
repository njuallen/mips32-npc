# MIPS32-NPC(MIPS32 NJU Processor Collection)

>
所有这些基础设施是从[riscv-sodor](https://github.com/ucb-bar/riscv-sodor)中改过来的。

---

## 准备工作

### clone这个repo
```bash
git clone https://github.com/njuallen/mips32-npc.git
```

### 安装gcc mips32工具链
```
sudo apt get update
sudo apt-cache search gcc-5-mips
```

### 安装scala工具链

1. 安装Java
   ```
   sudo apt-get install default-jdk
   ```
1. [安装sbt](http://www.scala-sbt.org/release/docs/Installing-sbt-on-Linux.html)
    ```
    echo "deb https://dl.bintray.com/sbt/debian /" | sudo tee -a /etc/apt/sources.list.d/sbt.list
    sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 642AC823
    sudo apt-get update
    sudo apt-get install sbt
    ```

### 安装verilator

#### 对于Ubuntu 17.04

```bash
sudo apt install pkg-config verilator
```

#### 对于Ubuntu 16.10及更低版本

```bash 
sudo apt install pkg-config
wget http://mirrors.kernel.org/ubuntu/pool/universe/v/verilator/verilator_3.900-1_amd64.deb
sudo dpkg -i verilator_3.900-1_amd64.deb
```

### clone AM及MIPS32-NEMU

```
git clone https://github.com/njuallen/nexus-am.git
git clone https://github.com/njuallen/mips32-nemu.git
```

设置环境变量

将下列命令修改后添加到你的.profile文件或者添加到.bashrc文件中。
```
export AM_HOME=/path/to/am
export MIPS32_NEMU_HOME=/path/to/mips32-nemu
```
你可以在所在的命令行界面中运行`source .profile`或`source .bashrc`使之生效。
需要注意的是，运行上述命令仅仅是针对你当前用的shell设置了环境变量，如果切换到其他窗口，你还需要再执行source命令。
为方便起见，建议你关闭所有窗口，log out后再重新log in进入系统，这样子可以确保每个新开的shell窗口都设置好了上述环境变量。

---

## 编译运行

### 编译

```
# this will generate Makefile
./configure
cd emulator/mips32_npc
make
```

以上的make流程，每次开始都需要先加载jar包，会导致编译的时间变得很长。建议用sbt console进行编译。

```
# 请先切换到项目根目录下
sbt
# 接下来我们进入了sbt的shell
# 选定项目
> project mips32_npc
# 每次修改了源文件之后，输入下列的命令执行增量编译
> run -td emulator/mips32_npc/generated-src

# 上述的sbt命令生成了CPU的verilog顶层模块
# 接下来我们要在另一个窗口中将verilog编译成cpp代码，再进一步编译成可执行文件用于仿真
cd emulator/mips32_npc
make
```

### 运行cputest

#### 手动运行一个cputest

将从am中编译好的一个cputest的.bin.txt文件复制到emulator/mips32_npc目录下，并重命名为bin.txt。
然后运行命令
```
./emulator +max-cycles=100000
```
其中+max-cycles=后跟的是运行的时钟周期数。

#### 批量运行cputest
```
make run-cputest
```

---

## FAQ

*如何开发调试，如何获取更多资源*: 请见doc目录

---

## TODO

* 按照scala规范进行命名，现在的命名十分混乱(Need help)
* 完成MIPS32-NEMU，支持crosscheck
* verilator仿真要支持更大的内存，不然跑不了am里面的microbench
* 完善外设仿真，争取能支持到AM的AsyncExt
* FPGA上板支持
