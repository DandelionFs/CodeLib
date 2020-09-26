---
title: '[Web]Two_try'
date: 2020-01-15 00:00:00
toc: true
---

## HTML（HyperText Markup Language）

一种用于创建网页的标准标记语言, 用于描述网页文档的一种工具。由 HTML 语言编写的文档，就是网页文档，这种文档可以被网页浏览器识别并解析，然后把网页效果呈现出来。

HTML 把不同类型的元素，如描述性元素 color、i 等和结构性元素 div、table 等，以及元素属性放在一起，为以后的维护和管理埋下隐患。

块状元素具有两个基本的特性。第一，块状元素默认宽度都是 100%，即块状元素会挤满一行显示。第二，块状元素的末尾都会隐藏一个换行符，当然是看不见它的。但是可以看到效果，也就是说，块状元素后面不能够再跟着显示其他行内元素或者块状元素。

行内显示行内显示没有块状显示的轮廓，因此可以形象地把它联想为一个皮纸袋子。如果为行内元素描一个边，有时显示的是不规则的。同时，行内元素正如它的名字所说的那样，多个行内元素并列显示在同一行内。行内元素也具有两个基本的特性。第一，行内元素没有高度和宽度，即使为它定义高度，但是浏览器在解析时也不会显示。第二，行内元素的呈现效果与块状元素存在很大区别，这不仅仅体现在宽和高方面，它们可以并列显示，随行移动。

行内块状显示行内块状显示是行内显示和块状显示的结合，拥有块状和行内元素的各自优势。但是默认状态下，元素不会显示该状态，需要使用 CSS 声明。

格显示表格也是一种块状元素，但是它还具有一些其他特性，如更严格的组织性，表格元素之间的严密协调性等。表格显示还包括表格、行、单元格、标题、列、组等不同的显示性质和效果。

 列表显示列表也属于块状元素，但是它拥有项目符号等一些其他特性。借助 CSS 可以为元素定义更多的显示效果，这里不再深入介绍，感兴趣的读者可以参阅 CSS 部分章节内容。

块状元素
在网页设计中，块状元素主要用来定义页面结构、布局网页、构建网页基本框架和结构。HTML 4 默认的块状元素包括以下方面。 html、body、frameset、frame、noframes、iframe：网页、框架基本结构块。 form、fieldset、legend：表单结构块。 div：布局结构块。 p：段落结构块。 h1、h2、h3、h4、h5、h6：标题结构块。 ol、ul、dl、dt、dd、menu、dir：列表结构块。 col、colgroup：表格列结构块。 center：居中结构块。 pre：预定义结构块。 address：引用结构块。 blockquote：特定信息结构块。 hr：结构装饰线。 isindex：交互提示框。 title：网页标题框。在上面结构块列表中，div 是网页布局最常用的元素，然后是段落、标题和列表元素，在网页布局中都是使用频率最高的元素。块状元素能够嵌套其他块状、行内等不同类型的元素，因此，它们主要负责网页结构的支撑和构建。

 提示：  hr、isindex 和 title 块状元素有点特殊，它们不直接参与到网页结构构建中。pre、address 和 blockquote 主要用于网页内容排版中。center 结构块虽然可以参与网页布局，但是可以使用 CSS 代替其功能，所以不建议选用元素。

行内元素
在网页设计中，行内元素主要用来定义特定语义信息。HTML 4 默认的行内元素包括以下方面。 span：行内包含框。 a、area：超链接和映射包含框。 img：图像包含框。 abbr、acronym、b、bdo、big、cite、code、del、dfn、em、font、i、ins、kbd、q、s、samp、small、strike、strong、sub、sup、tt、u、var：格式化信息包含框。 button、select、textarea、label：表单对象包含框。 applet、object：可执行的插件或对象包含框。 caption：表格标题包含框。 noscript：无脚本包含框。在行内元素中，使用最频繁的是 span 元素，该元素常用来作为修饰行内文本或对象的样式。
提示：  行内元素是不能用来进行网页结构构建的，虽然这样操作不会影响页面的解析效果，但是它不符合 HTML 结构嵌套规范，不建议使用。同时，也不建议在行内元素中包含其他块状元素，这样会严重破坏结构的逻辑关系。

其他元素
除了块状元素和行内元素，常用的其他类型元素还包括以下几种。 头部区域隐藏元素 head：头部包含框。 base：URL 基础。 basefont：默认基础字体属性。 link：链接。 meta：元信息。 script：脚本。 style：样式。 行内块状元素 input：输入框。 optgroup：下拉项分组。 option：下拉项。 列表项元素 li：列表项。 结构内隐藏元素 map：图像映射包含框。 param：参数。 br：换行。 表格系列类型元素 table：表格框显示。 tr：表格行显示。 td：单元格显示。 th：表格标题显示。 tbody：表格行组显示。 tfoot：表格脚注组显示。 thead：表格标题组显示。

下面是一份在 HTML 4 Strict 和 XHTML 1.0 Strict 下必须遵守的标签嵌套规则（http://www.cs.tut.fi/~jkorpela/html/strict.html）

【技巧 1】 body 元素能够直接包含的元素有 ins、del、script 和 block 类型元素。 block 表示块状类型的元素，换句话说，body 元素能够直接包含任何块状元素。 script 是头部隐藏显示的脚本元素。也就是说除了头部网页信息区域外，网页中（body 元素内）能够包含脚本（script 元素），但是不能够包含任何样式（style 元素）。 ins 和 del 是两个行内元素，其中 ins 元素表示插入到文档中的文本，而 del 元素表示文本已经从文档中删除。也就是说除了这两个特殊的行内元素外，其他任何行内元素都不能够直接包含在 body 中。

【技巧 2】 ins 和 del 元素能够直接包含块状元素和行内元素等不同类型的元素，但是行内元素是禁止包含块状元素的。

【技巧 3】 p、h1、h2、h3、h4、h5 和 h6 元素可以直接包含行内元素和纯文本内容，但是不能够直接包含块状元素，这是很多设计师最容易忽视的问题，也是最常犯的错误。但是 p、h1、h2、h3、h4、h5 和 h6 元素可以间接包含块状元素，例如，object、map 和 button 行内元素中还可以包含块状元素。

form 元素不能够直接包含 input 元素。因为input 元素是行内元素，而 form 元素仅能够包含块状元素。例如，下面的结构是不允许的：但是要套div就可以



【技巧 7】 
table 元素能够直接包含 caption、colgroup、col、thead、tbody 和 tfoot，但是不能够包含 tr 以及其他元素。不过习惯于在 table 元素中直接包含 tr，浏览器一般都能够自动在 table 和 tr 之间嵌入 tbody 元素。不过，还是建议读者养成使用 thead、tbody 和 tfoot 元素的习惯。caption 元素只能够包含行内元素，这与 dt 元素使用规则类似。tr 元素中只能够包含 th 和 td 元素。而 th 和 td 元素能够包含任何元素。例如，下面是一个正确、完整的表格嵌套结构。


CSS Zen Garden（http://www.csszengarden.com/）是 Dave Shea 于 2003 年创建的 CSS 标准推广小站，但就是这么一个小站却闻名全球，获得众多奖项。站长 Dave Shea 是一位图像设计师，致力于推广标准 Web 设计，如图 4.2 所示。该站被台湾设计师薛良斌和李士杰汉化为中文繁体版（http://www.csszengarden.com/tr/chinese/）之后，于是就有人（台湾）把它称为 CSS 禅意花园，从此禅意花园就成了 CSS Zen Garden 网站的代名词。





 使用 HTML 5 的 DOCTYPE会触发浏览器以标准模式显示页面。众所周知，网页都有多种显示模式，如怪异模式（Quirks）、近标准模式（Almost Standards）和标准模式（Standards）。其中标准模式也被称为非怪异模式（no-quirks）。浏览器会根据 DOCTYPE 来识别该使用哪种模式，以及使用什么规则来验证页面。
 <meta charset="UTF-8"> 两种方法都有效，可以继续使用前面一种方式，即通过 content 元素的属性来指定。但是不能同时混合使用两种方式。在以前的网站代码中可能会存在下面代码所示的标记方式，但在 HTML 5 中，这种字符编码方式将被认为是错误的：

可以省略标记的元素在 HTML 5 中，元素的标记可以省略。具体来说，元素的标记分为 3 种类型：不允许写结束标记、可以省略结束标记、开始标记和结束标记全部可以省略。下面简单介绍这 3 种类型各包括哪些 HTML 5 新元素。
第一，不允许写结束标记的元素有 area、base、br、col、command、embed、hr、img、input、keygen、link、meta、param、source、track、wbr。
第二，可以省略结束标记的元素有 li、dt、dd、p、rt、rp、optgroup、option、colgroup、thead、tbody、tfoot、tr、td、th。
第三，可以省略全部标记的元素有 html、head、body、colgroup、tbody。
提示：  不允许写结束标记的元素是指，不允许使用开始标记与结束标记将元素括起来的形式，只允许使用 < 元素/> 的形式进行书写。例如，<br>...</br> 的书写方式是错误的，正确的书写方式为 <br/>。当然，HTML 5 之前的版本中 <br> 这种写法可以被沿用。可以省略全部标记的元素是指，该元素可以完全被省略。注意，即使标记被省略了，该元素还是以隐式的方式存在的。例如，将 body 元素省略不写时，但它在文档结构中还是存在的，可以使用 document.body 进行访问。


具有布尔值的属性对于具有 boolean 值的属性，如 disabled 与 readonly 等，当只写属性而不指定属性值时，表示属性值为 true；如果想要将属性值设为 false，可以不使用该属性。另外，要想将属性值设定为 true 时，也可以将属性名设定为属性值，或将空字符串设定为属性值。例如：



 省略引号属性值两边既可以用双引号，也可以用单引号。HTML 5 在此基础上做了一些改进，当属性值不包括空字符串、<、>、=、单引号、双引号等字符时，属性值两边的引号可以省略。例如，下面写法都是合法的。
<input type="text">     <input type='text'>     <input type=text>

1．新增的结构元素HTML 5 定义了一组新的语义化标记来描述元素的内容。虽然语义化标记也可以使用 HTML 标记进行替换，但是它可以简化 HTML 页面设计，并且将来搜索引擎在抓取和索引网页的时候，也会利用到这些元素的优势。在目前主流的浏览器中已经可以用这些元素了，新增的语义化标记元素如表 5.2 所示。


根据 HTML 5 效率优先的设计理念，它推崇表现和内容的分离，所以在 HTML 5 的实际编程中，开发人员必须使用 CSS 来定义样式。【示例】  在本示例中分别使用 HTML 5 提供的各种语义化结构标记重新设计一个网页，在没有 CSS 的情况下显示效果如图 5.2 所示。



HTML 5 新增功能元素 

hgroup 元素：用于对整个页面或页面中一个内容区块的标题进行组合。例如：    <hgroup>...</hgroup> 在 HTML 4 中表示为：    <div>...</div>  figure 元素：表示一段独立的流内容，一般表示文档主体流内容中的一个独立单元。使用 figcaption 元素为 figure 元素组添加标题。例如：

在 HTML 5 中废除了 HTML 4 过时的元素，简单介绍如下。 

能使用 CSS 替代的元素对于 basefont、big、center、font、s、strike、tt、u 这些元素，由于它们的功能都是表现文本效果，而 HTML 5 中提倡把呈现性功能放在 CSS 样式表中统一编辑，所以将这些元素废除了，并使用编辑 CSS、添加 CSS 样式表的方式进行替代。其中 font 元素允许由「所见即所得」的编辑器来插入，s 元素、strike 元素可以由 del 元素替代，tt 元素可以由 CSS 的 font-family 属性替代。 不再使用 frame 框架对于 frameset 元素、frame 元素与 noframes 元素，由于 frame 框架对网页可用性存在负面影响，在 HTML 5 中已不支持 frame 框架，只支持 iframe 框架，或者用服务器方创建的由多个页面组成的复合页面的形式，同时将以上这 3 个元素废除。







### 框架格局


```html
<!DOCTYPE html><!--浏览器得知自己要处理的是HTML-->
<html lang="en"><!--文档中HTML的开始，Chrome中谷歌翻译识别的原文本由此而来-->
<head>
    <meta charset="UTF-8"><!--是一个网页的标签  mata元数据，在HTML5中新加入的一种新的编码方式另外的iso的编码-->
    <title>Title</title><!--标签页显示的标题-->
</head><!--提供有关文档内容和标注信息的（头元素）-->
<body><!--面向内容--><!--用Ctrl+/可以添加注释-->
</body>
</html>
```


注意：


### 解析


**meta**


两种属性，不同属性又有不同的参数值


1. name属性主要用于描述网页，与之对应的属性是content，content中的内容，主要便于搜索引擎机器人查找信息和分类信息用的 。
1. http-equiv顾名思义，相当于http的文件头作用，它可以向浏览器传回一些有用的信息，以帮助正确和精确的显示网页内容，与之对应的属性为content，content中的内容其实就是各个参数的变量值。
```html
<meta http-equiv="Refresh" content="2"> #每隔2秒刷新界面
   <link rel="icon" href="https://common.cnblogs.com/favicon.ico">#做网页上面的小图标
```


**body**


```html
<hn>:n的取值是1~6；从大到小，用来表示标题。
<p>：段落标签，包裹的内容被换行，并且也上下内容之间有一行空白
<b> <strong>:加粗标签
<s><strike>：为文字加上一条中线
<em>：文字变成斜体
<sup> 和<sub>：上角标和下角标
<br>：换行（可以单独使用）
<hr>：水平线
<u>: 下划线 是过时的保留 在CSS里面也可以设置</u><!--颜色要用CSS调整-->
<div> <span>两个在html中没有实质性作用，只是配合css的使用。div是块级的，而span是内联的
```

2. 块级标签和内联标签：
```html
块级标签：<p> <h1> <table> <ol> <ul> <form> <div>
```

   1. block（块）元素的特点：
      1. 总是在新行上开始
      1. 高度，行高以及外边框和内边距都可控制
      1. 宽度缺省是它的容器的100%，除非设定一个宽度
      1. 它可以容纳内联元素和其他块元素
```html
内联标签：<a> <input> <img> <sub> <sup> <textarea> <span>
```

   1. lnline元素的特点：
      1. 和其他元素都在一行上
      1. 高，行高以及外边距和内边距不可改变
      1. 宽度就是它的文字或图片的宽度，不可改变
      1. 内联元素只能容纳文本或者其他内联元素
   2. 对行内元素注意如下：
      1. 设置宽度width无效，
      1. 设置高度height无效，可以通过line-height设置，
      1. 设置margin只有左右margin无效，上下无效。
      1. 特殊字符：<>"©®　　<>"©®　　对应的字符



**图形标签**


```html
src：要显示图片的路径
alt：图片没有加载成功时的提示
title：鼠标悬浮时的提示信息
width：图片的宽
height：图片的高（宽高两个属性只用一个会自动等比缩放）
```


**超链接标签**`<a>`


```html
<a href="002.html" >2、LFH的第二个网页</a></p><!--默认是self刷新-->
<a href="002.html" target="_blank">2、1 LFH的第二个网页</a></p>
<a href="002.html" target="_parent">2、2 LFH的第二个网页</a></p>
<a href="002.html" target="_self">2、3 LFH的第二个网页</a></p>
<a href="002.html" target="_top">2、4 LFH的第二个网页</a></p>
```

2. 有 4 个保留的目标名称用作特殊的文档重定向操作：
   1. target的属性–>_blank：浏览器总在一个新打开、未命名的窗口中载入目标_
   1. target的属性–>_parent：这个目标使得文档载入父窗口或者包含来超链接引用的框架的框架集。如果这个引用是在窗口或者在顶级框架中，那么它与目标 _self 等效。
   1. target的属性–>_self：这个目标的值对所有没有指定目标的 [ 标签是默认目标，它使得目标文档载入并显示在相同的框架或者窗口中作为源文档。这个目标是多余且不必要的，除非和文档标题  标签中的 target 属性一起使用。]()
   1. target的属性–>_top：这个目标使得文档载入包含这个超链接的窗口，用 _top 目标将会清除所有被包含的框架并将文档载入整个浏览器窗口。--><!--标签的 target 属性规定在何处打开链接文档。
   1. 插入图片 在img标签里面只设置宽，不设置高，图片就会等比例缩放。



**列表标签**


```html
<ul>:无序列表
<ol>：有序列表
<li>：列表中的每一项
```
```html
<dl>：定义列表
<dt>：列表标题
<dd>：列表项
```

3. reversed ：倒序列表属性



**表格标签(table)**


```html
border：表格边框
cellpadding:内边框
cellspacing：外边框
width:像素百分比（最好是通过css来设置长宽）
<tr>：table row
<th><thead>：table head cell
<td>:table data cell
rowspan：单元格竖跨多少行
colspan：单元格横跨多少列
```


**表单标签`<form>`:（29种）**


1. 表单用于向服务器传输数据，比如文本字段、复选框、单选框、提交按钮等等。HTML表单用于接收不同类型的用户输入，用户提交表单时向服务器传输数据，从而实现用户与web服务器的交互。表单标签，要提交的所有内容都应该在该标签中。
1. `<form>`
1. `<input>`（自动断掉）
   1. **name**：表单提交项的键，注意和id的区别；name属性是和服务器通信时使用的名称，而id属性是浏览器端使用的名称，该属性主要是为了方便客户端编程。
   1. Type
      1. text:
         1. size：拓宽单行文本
         1. value：显式占位，表单提交项的值 , 对于不同的输入类型，value属性的用法也不同
         1. placeholder：隐式占位
         1. maxlength：最大长度
         1. readonly：文本属性
      2. password：密码
      2. textarea：多行文本框
         1. rows
         1. cols
      4. submit:
         1. method：表单的提交方式post、get默认取值就是get（信封）
            1. get：1、提交的键值对，放在地址栏中url后面。2、安全性相对较差。3、对提交的内容的长度有限制
            1. post：1、提交的键值对不在地址栏。2、安全性相对较差。3、对提交内容的长度理论上无限制。
         2. action：表单提交到哪，一般指向服务器端一个程序，程序接收到表单提交过来的数据（即表单元素值）作相应处理.
      5. button:
         1. Button > input button > input submit
      6. range
      6. file:
         1. multiple：一次允许上传多个文件
         1. required：一次只可以上传一个文件
   3. Name
   3. textarea
   3. select
   3. fieldset
   3. label



**嵌入图片和创建分区式响应**


1. `map`：响应图的关键元素
1. `area`：图片可被点击的元素
   1. 指定URL：href  和  Alt
   1. shape和coords 属性，共同起作用
      1. shape值：
         1. rect：四个逗号相隔的左上右下的四个区域
         1. circle：三个逗号相隔的左右边缘到圆心的距离和圆的半径
         1. poly：多边形，至少六个逗号，代表一个顶点（6个数值，实际是三个坐标，完成之后是一个三角形）
         1. dafault：代表默认区域，也就是说覆盖整个图片。不需要coords值。



**video**


1. src
1. height
1. width
1. autoplay
1. preload
1. controls
1. loop
1. poster
1. muted





## CSS


**层叠样式表**（英语：**C**ascading **S**tyle **S**heets，缩写：**CSS**；又称**串样式列表**、**级联样式表**、**串接样式表**、**阶层式样式表**）是一种用来为结构化文档（如HTML文档或XML应用）添加样式（字体、间距和颜色等）的计算机语言，由W3C定义和维护。当前最新版本是CSS2.1，为W3C的推荐标准。CSS现在已被大部分现代浏览器支持，而下一版的CSS4仍在开发中。


### 一、CSS基础元素


1. Style元素
   1. 全局属性
2. Font-size设置文本大小的属性
2. Color 设置文本颜色的属性



二、制作一个初级的CSS设计


1. 元素内嵌样式表
1. 文档内嵌样式表
1. 外部样式表



以上三者的优先级逐递减，随着控制范围的提高而使得自己的操作权限减少，体现了一种中庸的思想。


### 二、使用CSS基本选择器


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



四、：选择器


```html
<style type="text/css">
a:hover{
  		font-size: 40px;
  	   	color: darkblue;
         }
</style>
```


### 三、定义简单边框和背景设置


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


六、border简写属性


```html
<style type="text/css">
        .class2{
            border: 5px solid red;
        }
    </style>
```


七、定义简单背景


八、Background简写属性


### 四、CSS文本样式


1. 对齐文本`Text-align`
`center`&&`left`&&`right`
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
7. 字体大小`Font-size`
7. 字体样式`Font-style`
   1. `italic`:斜体&&`oblique(拉伸)`
10. 指定字母是否以小型大写字母显示`Font-variant`
10. 字体粗细`Font-weight`
10. 文本阴影`Font-shadow`
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


### 五、CSS过渡


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


### 六、CSS动画


贝塞尔曲线


`ease`、`eaae-in(前慢)`、`ease-out（后慢）`、`ease-in-out（前后都慢）`


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

### 七、CSS使用变换





### Color

#### Num

- 十六进制 : \#RRGGBB
- RGB : rgb(red, green, blue) (0 ~ 255 / 0% ~ 100%) : 256\*256\*256 = 16,777,216
- RGBA ( alpha , 0.0 - 1.0 )
- HSL : hsl ( hue, saturation, lightness ) (颜色柱面坐标表示法)
  - Hue : 0 / 360 红，120 绿，240 蓝
  - Saturation 百分比值；0% 灰， 100% 全彩
  - Lightness 百分比值；0% 黑，100% 白
- HSLA :hsla(hue, saturation, lightness, alpha) ( alpha 同上 )
- 预定义/跨浏览器

**[延拓] :** https://www.w3school.com.cn/cssref/css_colors_legal.asp





#### Name

规范中定义了 147 中颜色名（17 种标准颜色加 130 种其他颜色）

> 17 种标准色是 aqua, black, blue, fuchsia, gray, green, lime, maroon, navy, olive, orange, purple, red, silver, teal, white, yellow。

**[延拓] :** 

1. 查询 130 种颜色移步 https://www.w3school.com.cn/cssref/css_colornames.asp
2. **“网络安全色”** : 多年前，当电脑只支持最多 256 种颜色时，**216 种“网络安全色”列表被定义为 Web 标准**，并保留了 40 种固定的系统颜色。



## Reference

[1]. MDN Web 开发技术 https://developer.mozilla.org/zh-CN/docs/Web

[2]. MDN HTML https://developer.mozilla.org/zh-CN/docs/Web/HTML

[3]. MDN CSS https://developer.mozilla.org/zh-CN/docs/Web/CSS

[4]. MSD js https://developer.mozilla.org/zh-CN/docs/Web/JavaScript

[5].




