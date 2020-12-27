
# CSS

**层叠样式表**（英语：**C**ascading **S**tyle **S**heets，缩写：**CSS**；又称**串样式列表**、**级联样式表**、**串接样式表**、**阶层式样式表**）是一种用来为结构化文档（如HTML文档或XML应用）添加样式（字体、间距和颜色等）的计算机语言，由W3C定义和维护。当前最新版本是CSS2.1，为W3C的推荐标准。CSS现在已被大部分现代浏览器支持，而下一版的CSS4仍在开发中。

THX FOR:
- https://www.w3school.com.cn/cssref/css_colors_legal.asp
- [查询 130 种颜色移步](https://www.w3school.com.cn/cssref/css_colornames.asp)
1. MDN CSS https://developer.mozilla.org/zh-CN/docs/Web/CSS
2. MSD js https://developer.mozilla.org/zh-CN/docs/Web/JavaScript

## CSS基础元素


1. Style元素
   1. 全局属性
2. Font-size设置文本大小的属性
2. Color 设置文本颜色的属性

制作一个初级的CSS设计


1. 元素内嵌样式表
2. 文档内嵌样式表
3. 外部样式表



以上三者的优先级逐递减，随着控制范围的提高而使得自己的操作权限减少，体现了一种中庸的思想。


## 使用CSS基本选择器


选择器一般存在于2.2和2.3，对2.1不太感冒。


1. 选择所有元素
    ```html
    <style type="text/css">
            *{
                font-size: 50px;
                color: blueviolet;
            }/*所有元素的选择*/
    </style>
    ```
2. 根据类型选择元素
    ```html
    <style type="text/css">
        p{
                font-size: large;
                color: beige;
        }
    </style>
    ```
3. 根据类选择元素
    类是一个全局概念，意思是所有的元素都有累的属性
    ```html
    <style type="text/css">
    .class1 {
                font-size: 40px;
                color: aqua;
            }
    </style>
    ```
4. 根据ID选择元素
    和类相同，一个区别是不要用点，而是#；另一个区别是id是唯一身份的标识(不推荐这样使用)，而类可以使多个成员的归类。
    ```html
    <style type="text/css">
    #12345{
                font-size: xx-large;
                color: dodgerblue;
            }
    </style>
    ```
5. 根据属性选择元素
    ```html
    <style type="text/css">
    [href]{
                font-size: 40px;
                color: aqua;
            }
    </style>
    ```
6. 其他选择器



## 选择器

```html
<style type="text/css">
a:hover{
  		font-size: 40px;
  	   	color: darkblue;
         }
</style>
```


### 定义简单边框和背景设置


```html
 <style type="text/css">
        .class2{
            border-width:5px;
            border-style: dashed;
            border-color: aqua;
            border-bottom-color: blueviolet;
            border-bottom-style: dashed;
            border-left-color: darkblue;
            border-right-style: hidden;
            border-right-color: #ffc244;
            border-left-style: dotted;
            border-radius:20px/15px
        }
    </style>
```


`border-style: dashed;`这个有多种属性，测试后总结如下


## border简写属性

```html
<style type="text/css">
        .class2{
            border: 5px solid red;
        }
    </style>
```


## CSS文本样式

1. 对齐文本`Text-align` `center`&&`left`&&`right`
    ```html
    <style type="text/css">
        .class4{
            text-align: center;
        }
    </style>
    <body>
    <p class="class4" align="center">我是最帅的</p>
    </body>
    ```

2. 文字方向`Direction`:`ltr`&&`rtl`
2. 指定字母间距，单词间距，行高`Letter-spacing,word-spacing,line-height`
    ```html
    <style type="text/css">
        .class4{
            text-align: center;
            letter-spacing: 10px;
            word-spacing: 10px;
            line-height: 100px;
        }
    </style>
    ```
4. 首行缩进`Text-indent`
    ```html
    <style type="text/css">
        .class4{
            text-indent: 50px;
        }
    </style>
    ```
5. 文本装饰`Text-decoration`
    ```html
    <style type="text/css">
        .class4{
            text-decoration: overline;
            /*text-decoration: underline;*/
            /*text-decoration:line-through;*/
        }
    </style>
    ```
6. 文本大小写转换`Text-transform`
    ```html
    <style type="text/css">
        .class4{
            text-transform: capitalize;/*首字母大写*/
        /*  text-transform: uppercase;
            text-transform: lowercase;*/
        }
    </style>
    ```
7. 字体名称`Font-family`
8. 字体大小`Font-size`
9. 字体样式`Font-style`
   1. `italic`:斜体&&`oblique(拉伸)`
10. 指定字母是否以小型大写字母显示`Font-variant`
11. 字体粗细`Font-weight`
12. 文本阴影`Font-shadow`
    ```html
        <style type="text/css">
            .class5{
                font-family: 微软雅黑;
                font-size: 40px;
                font-style: oblique;
                font-variant: small-caps;/*小型大写转换（和text-transform不同的地方）*/
                font-weight: 200;/*(bold,bolder)*/
                text-shadow: 10px 10px 10px red;(左右，上下，模糊程度)
            }
        </style>
    ```


### CSS过渡

```html
<style type="text/css">
        p{
            width: 100px;
            height: 100px;
            background-color: bisque;
        }
        p:hover{
            width: 150px;
            height: 150px;
            background-color: aqua;
            transition-delay: 150ms;
            transition-duration: 250ms;
            /*-webkit-transition-duration: ;
            -o-transition-duration: ;
            -moz-transition-duration: ;*/
            transition-property: width,height;
        }/*指定动作*/
    </style>
```


### CSS动画
- 贝塞尔曲线
- `ease`、`eaae-in(前慢)`、`ease-out（后慢）`、`ease-in-out（前后都慢）`


```html
<style type="text/css">
    p{
            width: 100px;
            height: 100px;
            background-color: bisque;
        }
    p:hover{
        	width: 150px;
            height: 150px;
            background-color: aqua;
            transition-delay: 150ms;
        transition-timing-function: ease-in;
    }
```


和过渡相比动画演示完成以后会回到初始状态，但是过渡动画不同，它会随着鼠标的停留而动画停留


```html
<meta charset="UTF-8">
    <title>CSS动画</title>
    <style type="text/css">
        p{
            width: 100px;
            height: 100px;
            background-color: orange;
        }
        p:hover{
            animation-duration: 500ms;/*动画的过渡时间*/
            animation-delay: 200ms;
            animation-name: lfh;
            animation-iteration-count: infinite;
            animation-direction: alternate;/*变大之后变小*/
        }
        @keyframes lfh {
            from{
                width: 125px;
                height: 125px;
                background-color: #ffc244;
            }
            50%{
                width: 150px;
                height: 150px;
                background-color: #ffc244;
            }
            75%{
                width: 175px;
                height: 175px;
                background-color: #ffc244;
            }
            to{
                width: 200px;
                height: 200px;
                background-color: #ffc244;
            }
        }
    </style>
```

## Color

### Num

- 十六进制 : \#RRGGBB
- RGB : rgb(red, green, blue) (0 ~ 255 / 0% ~ 100%) : 256\*256\*256 = 16,777,216
- RGBA ( alpha , 0.0 - 1.0 )
- HSL : hsl ( hue, saturation, lightness ) (颜色柱面坐标表示法)
  - Hue : 0 / 360 红，120 绿，240 蓝
  - Saturation 百分比值；0% 灰， 100% 全彩
  - Lightness 百分比值；0% 黑，100% 白
- HSLA :hsla(hue, saturation, lightness, alpha) ( alpha 同上 )
- 预定义/跨浏览器



### Name

规范中定义了 147 中颜色名（17 种标准颜色加 130 种其他颜色）

> 17 种标准色是 aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive, orange, purple, red, silver, teal, white, yellow。

**[延拓] :** 
-  **“网络安全色”** : 多年前，当电脑只支持最多 256 种颜色时，**216 种“网络安全色”列表被定义为 Web 标准**，并保留了 40 种固定的系统颜色。


css



## CSS边框样式

该`border-style`属性指定要显示的边框类型。

允许以下值：

- `dotted` -定义虚线边框
- `dashed` -定义虚线边框
- `solid` -定义实线边框
- `double` -定义一个双边框
- `groove`-定义3D沟槽边框。效果取决于边框颜色值
- `ridge`-定义3D棱形边框。效果取决于边框颜色值
- `inset`-定义3D嵌入边框。效果取决于边框颜色值
- `outset`-定义3D起始边框。效果取决于边框颜色值
- `none` -没有边界
- `hidden` -定义一个隐藏的边框

该`border-style`属性可以具有一到四个值（用于顶部边框，右侧边框，底部边框和左侧边框）。

### 

## CSS边框宽度

该`border-width`属性指定四个边框的宽度。

可以将宽度设置为特定大小（以px，pt，cm，em等表示），也可以使用以下三个预定义值之一：薄，中或厚：