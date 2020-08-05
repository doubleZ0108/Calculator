# 计算器

* [图形界面计算器](#图形界面计算器)
   * [功能介绍](#功能介绍)
   * [实现效果](#实现效果)
      * [图形化界面](#图形化界面)
      * [计算演示](#计算演示)
* [控制台计算器](#控制台计算器)
   * [功能介绍](#功能介绍-1)
   * [实现效果](#实现效果-1)
* [开发环境](#开发环境)
* [关于作者](#关于作者)

------

## 图形界面计算器

[图形界面计算器](https://github.com/doubleZ0108/Calculator/tree/master/GUI-Calculator)

### 功能介绍

- [x] 点击按钮输入表达式
- [x] 运算符包括（+、-、*、/、（、））
- [x] 通过后缀表达式求解表达式的值
- [x] 显示计算结果
- [x] 输入表达式过长时动态切换字体大小
- [x] 连续计算

### 实现效果

#### 图形化界面

- 基础grid布局

  <img src="https://upload-images.jianshu.io/upload_images/12014150-fe2cf257c9ec2daa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200607234246437" width="60%;" />

- 拟态风格计算器

  <img src="https://upload-images.jianshu.io/upload_images/12014150-065b2a7659c9db1c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200607235446812" width="60%;" />

#### 计算演示

- 普通表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-089249913df210c0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182204118" width="80%;" />

- 带括号的表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-dc6b03a041226804.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182329624" width="30%;" />

  <img src="https://upload-images.jianshu.io/upload_images/12014150-53acaab78412b460.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182438278" width="80%;" />

- 错误表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-755e3582a123fa8a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182402538" width="80%;" />

<br/>

## 控制台计算器

[控制台计算器](https://github.com/doubleZ0108/Calculator/tree/master/Console-Calculator)

### 功能介绍

- [x] 计算表达式的值（支持括号）: `math [expression]`
- [x] 对表达式进行美化: `math -beauty [expression]`
- [x] 将中缀表达式转换为后缀表达式: `math -rev [expression]`
- [x] 检测表达式是否有非法字符
- [x] 检测表达式括号是否匹配
- [x] 查看帮助信息: `help`
- [x] 提示未找到该指令

### 实现效果

- 计算表达式的值

  <img src="https://upload-images.jianshu.io/upload_images/12014150-087b99d1d990ddb6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135434749" width="50%;" />

- 对表达式进行美化

  <img src="https://upload-images.jianshu.io/upload_images/12014150-7411762899f8f960.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135509630" width="50%;" />

- 将中缀表达式转换为后缀表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-61d0952aec1943c7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135546892" width="50%;" />

- 表达式中含有非法字符

  <img src="https://upload-images.jianshu.io/upload_images/12014150-df33fc69969ccf5d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135607226" width="50%;" />

- 表达式括号不匹配

  <img src="https://upload-images.jianshu.io/upload_images/12014150-a4072d645a8d1b61.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135625680" width="50%;" />

- 帮助信息

  <img src="https://upload-images.jianshu.io/upload_images/12014150-85dc6c4f6c11a878.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135709321" width="50%;" />

- 未找到该指令

  <img src="https://upload-images.jianshu.io/upload_images/12014150-75d571030d107cd0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609135724460" width="50%;" />

- 退出Cherry Calculator

  <img src="https://upload-images.jianshu.io/upload_images/12014150-5bf214981874894d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609140632311" width="50%;" />

<br/>

## 开发环境

- **操作系统**
  - **开发环境**：macOS Catalina 10.15.4
  - **打包环境**：Windows 10
- **IDE**
  - CLion 2019.3.3
  - Visual Studio 1.45.1
- **开发语言**: C | HTML5 | CSS3 | JavaScript

<br/>

## 关于作者

| Item            | Info                                                |
| --------------- | --------------------------------------------------- |
| **Name**        | 张喆                                                |
| **ID**          | 1754060                                             |
| **Academy**     | 软件学院                                            |
| **Course Name** | 2020人工智能微专业 - 数据结构                       |
| **Email**       | [dbzdbz@tongji.edu.cn](mailto:dbzdbz.tongji.edu.cn) |