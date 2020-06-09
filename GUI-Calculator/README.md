# 图形界面计算器

#### Table of Contents

   * [图形界面计算器](#图形界面计算器)
      * [功能介绍](#功能介绍)
      * [开发环境](#开发环境)
      * [实现效果](#实现效果)
         * [图形化界面](#图形化界面)
         * [计算演示](#计算演示)
      * [核心实现](#核心实现)
         * [界面](#界面)
         * [语法糖](#语法糖)
         * [转换为后缀表达式](#转换为后缀表达式)
         * [计算后缀表达式](#计算后缀表达式)
      * [关于作者](#关于作者)
      * [项目结构](#项目结构)

------

## 功能介绍

- [x] 点击按钮输入表达式
- [x] 运算符包括（+、-、*、/、（、））
- [x] 通过后缀表达式求解表达式的值
- [x] 显示计算结果
- [x] 输入表达式过长时动态切换字体大小
- [x] 连续计算

- [ ] <br/>

## 开发环境

- **操作系统**
  - **开发环境**：macOS Catalina 10.15.4
- **IDE**：Visual Studio Code 1.45.1
- **开发语言**:
  - HTML5
  - CSS3
  - JavaScript

<br/>

## 实现效果

### 图形化界面

- 基础grid布局

  <img src="https://upload-images.jianshu.io/upload_images/12014150-fe2cf257c9ec2daa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200607234246437" width="60%;" />

- 拟态风格计算器

  <img src="https://upload-images.jianshu.io/upload_images/12014150-065b2a7659c9db1c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200607235446812" width="60%;" />

### 计算演示

- 普通表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-089249913df210c0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182204118" width="80%;" />

- 带括号的表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-dc6b03a041226804.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182329624" width="30%;" />

  <img src="https://upload-images.jianshu.io/upload_images/12014150-53acaab78412b460.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182438278" width="80%;" />

- 错误表达式

  <img src="https://upload-images.jianshu.io/upload_images/12014150-755e3582a123fa8a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240" alt="image-20200609182402538" width="80%;" />

<br/>

## 核心实现

### 界面

```html
<div class="calculator">
  <div id="result" class="result" style="grid-area: result;">
    0
  </div>
  <button id="ac" style="grid-area: ac;">AC</button>
  <button style="grid-area: left-bracket;">(</button>
  <button style="grid-area: right-bracket;">)</button>
  <button style="grid-area: add;">+</button>
  <button style="grid-area: subtract;">-</button>
  <button style="grid-area: multiply;">*</button>
  <button style="grid-area: divide;">/</button>
  <button id="equal" style="grid-area: equal;">=</button>

  <button style="grid-area: number-1;">1</button>
  <button style="grid-area: number-2;">2</button>
  <button style="grid-area: number-3;">3</button>
  <button style="grid-area: number-4;">4</button>
  <button style="grid-area: number-5;">5</button>
  <button style="grid-area: number-6;">6</button>
  <button style="grid-area: number-7;">7</button>
  <button style="grid-area: number-8;">8</button>
  <button style="grid-area: number-9;">9</button>
  <button style="grid-area: number-0;">0</button>
</div>
```

```css
.calculator {
    --button-width: 80px;
    --button-height: 80px;
    display: grid;
    grid-template-areas: 
        "result result result result"
        "ac left-bracket right-bracket divide"
        "number-7 number-8 number-9 multiply"
        "number-4 number-5 number-6 subtract"
        "number-1 number-2 number-3 add"
        "number-0 equal equal equal";
    grid-template-columns: repeat(4, var(--button-width));
    grid-template-rows: repeat(6, var(--button-height));

    box-shadow: -8px -8px 16px -10px rgba(255, 255, 255, 1), 8px 8px 16px -10px rgba(0, 0, 0, .15);
    padding: 24px;
    border-radius: 20px;
}
```

### 语法糖

```js
function $(id){
    return document.getElementById(id);
}
```

```js
document.querySelectorAll("button:not(#ac):not(#equal)").forEach(function(elem, index){
  elem.onclick = function(){
    appendChar(elem.innerHTML);
  };
});
```

### 转换为后缀表达式

```js
function toPostfix(exp){
    let op_stack = [];
    _current = 0;

    exp += "#";
    op_stack.push("#");

    let postfix_exp = [];

    let elem = getNextContent(exp);
    while(op_stack.length !== 0) {
        let ch = elem.value
        if(elem.type === "number") {
            postfix_exp.push(elem);
            elem = getNextContent(exp);
        } else if(elem.type === "operator"){
            let topch = op_stack[op_stack.length-1];
            if(isp(topch) < icp(ch)) {
                op_stack.push(ch);
                elem = getNextContent(exp);
            } else if (isp(topch) > icp(ch)) {
                postfix_exp.push({
                    type: "operator",
                    value: op_stack.pop()
                });
            } else {
                if(op_stack[op_stack.length-1] === '(') {
                    elem = getNextContent(exp);
                }
                op_stack.pop();
            }
        }
    }

    return postfix_exp;
}
```

### 计算后缀表达式

```js
function calulatePostfixExpression(postfix_exp){
    let num_stack = [];
    postfix_exp.forEach(function(elem){
        if(elem.type === "number"){
            num_stack.push(elem.value);
        } else {
            let right = num_stack.pop();
            let left = num_stack.pop();
            if(isNaN(parseInt(right)) || isNaN(parseInt(left))){
                return "ERROR";
            }

            let buf = null;
            try {
                buf = parseInt(eval(left + elem.value + right));
            } catch (e) {
                return "ERROR";
            } finally {
                num_stack.push(buf);
            }
        }
    });
    return num_stack.pop();
}
```

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

```
.
├── README.md
├── calculator.html
├── doc
│   └── 图形界面计算器说明文档.pdf
└── static
    ├── css
    │   └── calculator.css
    └── js
        ├── calculator.js
        ├── stack.js
        └── util.js
```

