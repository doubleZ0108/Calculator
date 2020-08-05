# 控制台计算器(Cherry-Calculator)

* [功能介绍](#功能介绍)
* [开发环境](#开发环境)
* [实现效果](#实现效果)
* [核心实现](#核心实现)
   * [对表达式进行美化](#对表达式进行美化)
   * [优先级](#优先级)
   * [将中缀表达式转换为后缀表达式](#将中缀表达式转换为后缀表达式)
   * [获取下一内容](#获取下一内容)
* [关于作者](#关于作者)
* [项目结构](#项目结构)

------

## 功能介绍

- [x] 计算表达式的值（支持括号）: `math [expression]`
- [x] 对表达式进行美化: `math -beauty [expression]`
- [x] 将中缀表达式转换为后缀表达式: `math -rev [expression]`
- [x] 检测表达式是否有非法字符
- [x] 检测表达式括号是否匹配
- [x] 查看帮助信息: `help`
- [x] 提示未找到该指令

<br/>

## 开发环境

- **操作系统**
  - **开发环境**：macOS Catalina 10.15.4
  - **打包环境**：Windows 10
- **IDE**
  - CLion 2019.3.3
  - Visual Studio 2017
- **开发语言**: C语言

<br/>

## 实现效果

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

## 核心实现

### 对表达式进行美化

由于用户输入的表达式中可能出现任意数量的空格，因此在获取下一个操作项上要花更多精力进行判断。因此首先将用户输入的字符串进行美化

```c
/**
 * Beaurify for the origin expression
 * @param origin_exp: origin input expression
 * @param exp: expression after beautify
 */
void beautify(char* origin_exp, char* exp){
    int pos = 0;
    for (int i = 0; i < strlen(origin_exp); ++i) {
        if (isOperator(origin_exp[i])) {
            exp[pos] = ' ';
            ++pos;
            exp[pos] = origin_exp[i];
            ++pos;
            exp[pos] = ' ';
            ++pos;
        }
        else if (isDigit(origin_exp[i])) {
            exp[pos] = origin_exp[i];
            ++pos;
        }
    }
}
```

### 优先级

左括号的栈外优先数最高，它一来到立即进栈，但当它进入栈中后，其栈内优先数变得极低，以便括号内的其他操作符进栈。其他操作符进入栈中后优先数都升1，这样可体现在中缀表达式中相同优先级的操作符从左向右计算的要求，让位于栈顶的操作符先退栈听输出。操作符优先数相等的情况只出现在括号配对或栈顶的‘#’号与输入流最后的‘#’号配对时。前者将见徐退出位于栈顶的操作符，直到遇到左括号为止。然后将左括号退栈以对消括号，后者将结束算法。

```c
/*============ 优先级 ============*/
/**
 * 栈内优先级
 */
int isp(char ch)
{
    switch (ch)
    {
        case '#':return 0;
        case '(':return 1;
        case '*':case '/':return 5;
        case '+':case '-':return 3;
        case ')':return 6;
    }
}

/**
 * 栈外优先级
 */
int icp(char ch)
{
    switch (ch)
    {
        case '#':return 0;
        case '(':return 6;
        case '*':case '/':return 4;
        case '+':case '-':return 2;
        case ')':return 1;
    }
}
```

### 将中缀表达式转换为后缀表达式

<img src="https://upload-images.jianshu.io/upload_images/12014150-f910636d2eaa62b5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609140201006" width="70%;" />

```c
num_stack_clear();  // 初始化操作数栈
op_stack_clear();   // 初始化操作符栈
_current = 0;

struct Data result[100];
int index = 0;

addTail(exp); // 在表达式尾部添加结束标识符

op_stack_push('#');
struct Data elem = NextContent(exp);
while (!isempty_op_stack()) {
  char ch = elem.data;

  if (elem.flag == 1) {        //如果是操作数, 直接读入下一个内容
    result[index] = elem;
    index++;
    elem = NextContent(exp);
  }
  else if (elem.flag == 0) {    //如果是操作符,判断ch的优先级icp和当前栈顶操作符的优先级isp
    char topch = op_stack_top();
    if (isp(topch) < icp(ch)) {        //当前操作符优先级大,将ch压栈,读入下一个内容
      op_stack_push(ch);
      elem = NextContent(exp);
    }
    else if (isp(topch) > icp(ch)) {    //当前优先级小,推展并输出到结果中
      struct Data buf;
      buf.data = op_stack_pop();
      buf.flag = 0;
      result[index] = buf;
      index++;
    }
    else {
      if (op_stack_top() == '(') {    //如果退出的是左括号则读入下一个内容
        elem = NextContent(exp);
      }
      op_stack_pop();
    }
  }
}
```

### 获取下一内容

<img src="https://upload-images.jianshu.io/upload_images/12014150-c2303cafe8daea5f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609140359174" width="70%;" />

<br/>

## 关于作者

| Item            | Info                                                |
| --------------- | --------------------------------------------------- |
| **Name**        | 张喆                                                |
| **ID**          | 1754060                                             |
| **Academy**     | 软件学院                                            |
| **Course Name** | 2020人工智能微专业 - 数据结构                       |
| **Email**       | [dbzdbz@tongji.edu.cn](mailto:dbzdbz.tongji.edu.cn) |

<br/>

## 项目结构

```c
.
├── CMakeLists.txt					// CLion cmake文件
├── Console-Calculator.exe	// 可执行程序
├── Console-Calculator.sln	// Visual Studio2017 工程
├── README.md
├── doc
│   └── 控制台计算器说明文档.pdf
└── src
    ├── header
    │   ├── calculator.h
    │   ├── calculator_stack.h
    │   ├── interface.h
    │   └── util.h
    └── main.c
```

