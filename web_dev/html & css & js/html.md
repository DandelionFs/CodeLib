# HTML(HyperText Markup Language)
简单记录要点.

HTML, 网页文档的标准标记语言, 但是 HTML 把不同类型的元素，如 **描述性元素 color、i 等** 和 **结构性元素 div、table** 等，以及元素属性放在一起，为以后的维护和管理埋下隐患。

THX FOR:
- [W3schools.com](https://www.w3schools.com/)
- [MDN Web 开发技术](https://developer.mozilla.org/zh-CN/docs/Web)
- [MDN HTML](https://developer.mozilla.org/zh-CN/docs/Web/HTML) 
- [一份在 HTML 4 Strict 和 XHTML 1.0 Strict 下必须遵守的标签嵌套规则](http://www.cs.tut.fi/~jkorpela/html/strict.html)
- [网页直接加QQ群/QQ好友](https://blog.csdn.net/qq_28975017/article/details/72898385)-coder丶赵 
- [想把文件直接放至服务器，通过http的url下载](https://blog.csdn.net/weixin_36586564/article/details/78774035?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)-严的博客
- [提高网页打开速度的一些小技巧 [问题点数：100分]]( https://bbs.csdn.net/topics/230010297 )

## 结构

- **块(block)状元素**: 在网页设计中，块状元素主要用来定义页面结构、布局网页、构建网页基本框架和结构。块状元素能够嵌套其他块状、行内等不同类型的元素，因此，它们主要负责网页结构的支撑和构建。HTML 4 
  - html、body、frameset、frame、noframes、iframe：网页、框架基本结构块
  - form、fieldset、legend：表单结构块
  - div：布局结构块
  - p：段落结构块 
  - h1、h2、h3、h4、h5、h6：标题结构块。 
  - ol、ul、dl、dt、dd、menu、dir：列表结构块
  - col、colgroup：表格列结构块
  - center：居中结构块。虽然可以参与网页布局，但是可以使用 CSS 代替其功能，所以不建议选用元素
  - pre：预定义结构块
  - address：引用结构块
  - blockquote：特定信息结构块
    - pre、address 和 blockquote 主要用于网页内容排版
  - hr：结构装饰线
  - isindex：交互提示框
  - title：网页标题框
  - 表格系列类型元素 
    - table：表格框显示
    - tr：表格行显示
    - td：单元格显示
    - th：表格标题显示
    - tbody：表格行组显示
    - tfoot：表格脚注组显示
    - thead：表格标题组显示
    - border：表格边框
    - cellpadding:内边框
    - cellspacing：外边框
    - width:像素百分比（最好是通过css来设置长宽）
    - rowspan：单元格竖跨多少
    - colspan：单元格横跨多少列
    - ---
    - hr、isindex 和 title 块状元素有点特殊，它们不直接参与到网页结构构建中
  - **性质**
    - 默认宽度都是 100%，即块状元素会挤满一行显示
    - 末尾都会隐藏一个换行符，看不见,但有效果，也就是说，块状元素后面不能够再跟着显示其他行内元素或者块状元素
    - 列表显示列表也属于块状元素，但是它拥有项目符号等一些其他特性。借助 CSS 可以为元素定义更多的显示效果，这里不再深入介绍，感兴趣的读者可以参阅 CSS 部分章节内容
    - 总是在新行上开始
    - 高度，行高以及外边框和内边距都可控制
    - 宽度缺省是它的容器的100%，除非设定一个宽度
    - 它可以容纳内联元素和其他块元素
  - 内联标签


- **行内元素**(内联标签): **定义特定语义信息**。行内元素是不能用来进行网页结构构建的，虽然这样操作不会影响页面的解析效果，但是它不符合 HTML 结构嵌套规范，不建议使用。同时，也不建议在行内元素中包含其他块状元素，这样会严重破坏结构的逻辑关系。 HTML4
  - span：行内包含框。 
  - a、area：超链接和映射包含框。
    -  有 4 个保留的目标名称用作特殊的文档重定向操作：
       - target的属性–>_blank：浏览器总在一个新打开、未命名的窗口中载入目标_
       - target的属性–>_parent：这个目标使得文档载入父窗口或者包含来超链接引用的框架的框架集。如果这个引用是在窗口或者在顶级框架中，那么它与目标 _self 等效。
       - target的属性–>_self：这个目标的值对所有没有指定目标的 [ 标签是默认目标，它使得目标文档载入并显示在相同的框架或者窗口中作为源文档。这个目标是多余且不必要的，除非和文档标题  标签中的 target 属性一起使用。]()
       - target的属性–>_top：这个目标使得文档载入包含这个超链接的窗口，用 _top 目标将会清除所有被包含的框架并将文档载入整个浏览器窗口。--><!--标签的 target 属性规定在何处打开链接文档。

  - img：图像包含框你插入图片 在img标签里面只设置宽，不设置高，图片就会等比例缩放。
    - src：要显示图片的路径
    - alt：图片没有加载成功时的提示
    - title：鼠标悬浮时的提示信息
    - width：图片的宽
    - height：图片的高（宽高两个属性只用一个会自动等比缩放）
  - abbr、acronym、b、bdo、big、cite、code、del、dfn、em、font、i、ins、kbd、q、s、samp、small、strike、strong、sub、sup、tt、u、var：格式化信息包含框。 
  - button、select、textarea、label：表单对象包含框。 
  - applet、object：可执行的插件或对象包含框。 caption：表格标题包含框。 
  - noscript：无脚本包含框。在行内元素中，使用最频繁的是 span 元素，该元素常用来作为修饰行内文本或对象的样式。
  - 行内块状元素 
    - input：输入框
    - optgroup：下拉项分组
    - option：下拉项
    - 列表项元素 li：列表项
    - 结构内隐藏元素 map：图像映射包含框
    - param：参数
    - br：换行
  - 性质:
    - 行内显示 显示没有块状显示的轮廓，因此可以形象地把它联想为一个皮纸袋子。如果为行内元素描一个边，有时显示的是不规则的。同时，行内元素正如它的名字所说的那样，多个行内元素并列显示在同一行内。
    - 行内元素没有高度和宽度，即使为它定义高度，但是浏览器在解析时也不会显示
    - 行内元素的呈现效果与块状元素存在很大区别，这不仅仅体现在宽和高方面，它们可以并列显示，随行移动。
    - 和其他元素都在一行上
    - 高，行高以及外边距和内边距不可改变
    - 宽度就是它的文字或图片的宽度，不可改变
    - 内联元素只能容纳文本或者其他内联元素
  - 对行内元素注意如下：
    -  设置宽度width无效，
    -  设置高度height无效，可以通过line-height设置
    -  设置margin只有左右margin无效，上下无效。
    -  特殊字符：`<>"©®　　<>"©®　　`对应的字符

  - 行内块状显示: 默认状态下，元素不会显示该状态，需要使用 CSS 声明。
  - 格显示表格也是一种块状元素，但是它还具有一些其他特性，如更严格的组织性，表格元素之间的严密协调性等。表格显示还包括表格、行、单元格、标题、列、组等不同的显示性质和效果。

- **其他元素**
  - 头部区域隐藏元素 head：头部包含框。 base：URL 基础。 
  - basefont：默认基础字体属性。 
  - link：链接。 
    - ```html
      <link rel="icon" href="https://common.cnblogs.com/favicon.ico">#做网页上面的小图标
      ```
  - **meta**(元信息)
    - name属性主要用于描述网页，与之对应的属性是content，content中的内容，主要便于搜索引擎机器人查找信息和分类信息用的 。
    - http-equiv(=http的文件头): 它可以向浏览器传回一些有用的信息，以帮助正确和精确的显示网页内容，与之对应的属性为content，content中的内容其实就是各个参数的变量值。
    ```html
    <meta htt p-equiv="Refresh" content="2"> #每隔2秒刷新界面
    ```
    - [Viewport](https://www.w3schools.com/css/css_rwd_viewport.asp): take control over the viewport
    - ```html
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      ```
      - The `width=device-width` part sets the width of the page to follow the screen-width of the device (which will vary depending on the device). 即调整页面宽度
      - The `initial-scale=1.0` part sets the initial zoom level when the page is first loaded by the browser. 即调整缩放比例.

  - script：脚本。 
  - style：样式。 

### 表单

**表单标签`<form>`:（29种）**

1. 表单用于向服务器传输数据，比如文本字段、复选框、单选框、提交按钮等等。HTML表单用于接收不同类型的用户输入，用户提交表单时向服务器传输数据，从而实现用户与web服务器的交互。表单标签，要提交的所有内容都应该在该标签中。
2. `<form>`
3. `<input>`（自动断掉）
   1. **name**：表单提交项的键，注意和id的区别；name属性是和服务器通信时使用的名称，而id属性是浏览器端使用的名称，该属性主要是为了方便客户端编程。
   2. Type
      1. text:
         1. size：拓宽单行文本
         2. value：显式占位，表单提交项的值 , 对于不同的输入类型，value属性的用法也不同
         3. placeholder：隐式占位
         4. maxlength：最大长度
         5. readonly：文本属性
      2. password：密码
      3. textarea：多行文本框
         1. rows
         2. cols
      4. submit:
         1. method：表单的提交方式post、get默认取值就是get（信封）
            1. get：1、提交的键值对，放在地址栏中url后面。2、安全性相对较差。3、对提交的内容的长度有限制
            2. post：1、提交的键值对不在地址栏。2、安全性相对较差。3、对提交内容的长度理论上无限制。
         2. action：表单提交到哪，一般指向服务器端一个程序，程序接收到表单提交过来的数据（即表单元素值）作相应处理.
      5. button:
         1. Button > input button > input submit
      6. range
      7. file:
         1. multiple：一次允许上传多个文件
         2. required：一次只可以上传一个文件
   3. Name
   4. textarea
   5. select
   6. fieldset
   7. label

### 嵌入图片和创建分区式响应


1. `map`：响应图的关键元素
1. `area`：图片可被点击的元素
   1. 指定URL：href  和  Alt
   1. shape和coords 属性，共同起作用
      1. shape值：
         1. rect：四个逗号相隔的左上右下的四个区域
         1. circle：三个逗号相隔的左右边缘到圆心的距离和圆的半径
         1. poly：多边形，至少六个逗号，代表一个顶点（6个数值，实际是三个坐标，完成之后是一个三角形）
         1. dafault：代表默认区域，也就是说覆盖整个图片。不需要coords值。
## video
1. src
1. height
1. width
1. autoplay
1. preload
1. controls
1. loop
1. poster
1. muted


## 实例

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
<!--body-->
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

<!--**超链接标签**`<a>`-->
<a href="002.html" >2、LFH的第二个网页</a></p><!--默认是self刷新-->
<a href="002.html" target="_blank">2、1 LFH的第二个网页</a></p>
<a href="002.html" target="_parent">2、2 LFH的第二个网页</a></p>
<a href="002.html" target="_self">2、3 LFH的第二个网页</a></p>
<a href="002.html" target="_top">2、4 LFH的第二个网页</a></p>

<ul>:无序列表
<ol>：有序列表
<li>：列表中的每一项

<dl>：定义列表
<dt>：列表标题
<dd>：列表项

<tr>：table row
<th><thead>：table head cell
<td>:table data cell

```


## SKILLS

### Some inters
+ 唤起QQ: 加QQ群的话在QQ客户端就可以申请到链接，操作即可，或者在[这里](https://qun.qq.com/join.html)找到。
```html
<body>
        <h1>jsdafjk</h1>
        <a href="http://wpa.qq.com/msgrd?v=3&amp;uin=1551728654&amp;site=qq&amp;menu=yes">1551728654</a>
        <br/>
        <a href="tencent://AddContact/?fromId=50&fromSubId=1&subcmd=all&uin=1551728654">1551728654</a>
</body>
```
+ 跳转邮箱
```html
<a href="mailto:lfh010618@gmail.com">lfh010618@gmail.com</a>
```
+ 生成网页的下载链接：


### Html Speed

互联网带宽越来越宽，似乎让网页的加载速度得到了质的飞跃。其实不然，因为随着带宽的提高，网页上的对象也越来越多，因此加快网页打开速度还是一个重要的课题。加快网页的打开速度，有三个路径，一是提高网络带宽，二是用户在本机做优化，三是网站设计者对网页做一定的优化。这篇文章站在一个网站设计者的角度，分享一些优化网页加载速度的小技巧。

#### 优化图片

如果你经历过56K猫（拨号上网，B站可以搜到的两个号码：96167，16300）的年代，你一定不会很喜欢有大量图片的网站。因为加载那样一个网页会花费大量的时间。即使在现在，网络带宽有了很多的提高，56K猫逐渐淡出，优化图片以加快网页速度还是很有必要的。优化图片包括减少图片数、降低图像质量、使用恰当的格式。

1. 减少图片数：去除不必要的图片。
2. 降低图像质量：如果不是很必要，尝试降低图像的质量，尤其是jpg格式，降低5%的质量看起来变化不是很大，但文件大小的变化是比较大的。
3. 使用恰当的格式：请参阅下一点。因此，在上传图片之前，你需要对图片进行编辑，如果你觉得photoshop太麻烦，可以试试一些在线图片编辑工具。懒得编辑而又想图片有特殊的效果？可以试试用过调用javascript来实现图片特效。

### 图像格式的选择

一般在网页上使用的图片格式有三种，jpg、png、gif。三种格式的具体技术指标不是这篇文章探讨的内容，我们只需要知道在什么时候应该使用什么格式，以减少网页的加载时间。

1. JPG：一般用于展示风景、人物、艺术照的摄影作品。有时也用在电脑截屏上。2、
2. GIF：提供的颜色较少，可用在一些对颜色要求不高的地方，比如网站logo、按钮、表情等等。当然，gif的一个重要的应用是动画图片。就像用Lunapic制作的倒映图片。3、
3. PNG：PNG格式能提供透明背景，是一种专为网页展示而发明的图片格式。一般用于需要背景透明显示或对图像质量要求较高的网页上。三、优化CSSCSS叠层样式表让网页加载起来更高效，浏览体验也得到提高。有了CSS，表格布局的方式可以退休了。但有时我们在写CSS的时候会使用了一些比较罗嗦的语句，比如这句：
  ```css
  margin-top: 10px;
  margin-right: 20px;
  margin-bottom: 10px;
  margin-left: 20px;
  ```
​		你可以将它简化为：
  ```css
  margin: 10px 20px 10px 20px;
  ```
​		又或者这句：
  ```html
  <p class="decorated">A paragraph of decorated text</p>
  <p class="decorated">Second paragraph</p>
  <p class="decorated">Third paragraph</p>
  <p class="decorated">Forth paragraph</p>
  ```
​		可以用div来包含：
  ```html
  <div class="decorated">
  <p>A paragraph of decorated text</p>
  <p>Second paragraph</p>
  <p>Third paragraph</p>
  <p>Forth paragraph</p>
  </div>
  ```
​		简化CSS能去除冗余的属性，提高运行效率。如果你写好CSS后懒得去做简化，你可以使用一些在线的简化CSS工具，比如CleanCSS。

### 网址后加斜杠

有些网址，比如"www.yoursites.com/220"，当服务器收到这样一个地址请求的时候，它需要花费时间去确定这个地址的文件类型。如果220是一个目录，不妨在网址后多加一个斜杠，让其变成www.yoursite.com/220/，这样服务器就能一目了然地知道要访问该目录下的index或default文件，从而节省了加载时间。

### 标明高度和宽度

这点很重要，但很多人由于懒惰或其它原因，总是将其忽视。当你在网页上添加图片或表格时，你应该指定它们的高度和宽度，也就是height和width参数。如果浏览器没有找到这两个参数，它需要一边下载图片一边计算大小，如果图片很多，浏览器需要不断地调整页面。这不但影响速度，也影响浏览体验。下面是一个比较友好的图片代码：

  ```html
  <img id="moon" height="200" width="450" src="http://www.kenengba.com/moon.png" alt="moon image" />
  ```

当浏览器知道了高度和宽度参数后，即使图片暂时无法显示，页面上也会腾出图片的空位，然后继续加载后面的内容。从而加载时间快了，浏览体验也更好了。

### 减少http请求

当浏览者打开某个网页，浏览器会发出很多对象请求（图像、脚本等等），视乎网络延时情况，每个对象加载都会有所延迟。如果网页上对象很多，这可以需要花费大量的时间。因此，要为http请求减负。如何减负？1、去除一些不必要的对象。2、将临近的两张图片合成一张。3、合并CSS看看下面这段代码，需要加载三个CSS：

```html
<link rel="stylesheet" type="text/css" href="/body.css" /><link rel="stylesheet" type="text/css" href="/side.css" /><link rel="stylesheet" type="text/css" href="/footer.css" />
```

我们可以将其合成一个：

```html
<link rel="stylesheet" type="text/css" href="/style.css" />
```

从而减少http请求。

</br>

### 其它小技巧（译者添加）

1. 去除不必要加载项。
2. 如果在网页上嵌入了其它网站的widget，如果有选择余地，一定要选择速度快的。
3. 尽量用图片代替flash，这对SEO也有好处。
4. 有些内容可以静态化就将其静态化，以减少服务器的负担。
5. 统计代码放在页尾。  


```
1. body 元素能够直接包含的元素有 ins、del、script 和 block 类型元素。 block 表示块状类型的元素，换句话说，body 元素能够直接包含任何块状元素。 script 是头部隐藏显示的脚本元素。也就是说除了头部网页信息区域外，网页中（body 元素内）能够包含脚本（script 元素），但是不能够包含任何样式（style 元素）。 ins 和 del 是两个行内元素，其中 ins 元素表示插入到文档中的文本，而 del 元素表示文本已经从文档中删除。也就是说除了这两个特殊的行内元素外，其他任何行内元素都不能够直接包含在 body 中。
2. ins 和 del 元素能够直接包含块状元素和行内元素等不同类型的元素，但是行内元素是禁止包含块状元素的。
3. p、h1、h2、h3、h4、h5 和 h6 元素可以直接包含行内元素和纯文本内容，但是不能够直接包含块状元素，这是很多设计师最容易忽视的问题，也是最常犯的错误。但是 p、h1、h2、h3、h4、h5 和 h6 元素可以间接包含块状元素，例如，object、map 和 button 行内元素中还可以包含块状元素。
   form 元素不能够直接包含 input 元素。因为input 元素是行内元素，而 form 元素仅能够包含块状元素。例如，下面的结构是不允许的：但是要套div就可以
4. table 元素能够直接包含 caption、colgroup、col、thead、tbody 和 tfoot，但是不能够包含 tr 以及其他元素。不过习惯于在 table 元素中直接包含 tr，浏览器一般都能够自动在 table 和 tr 之间嵌入 tbody 元素。不过，还是建议读者养成使用 thead、tbody 和 tfoot 元素的习惯。caption 元素只能够包含行内元素，这与 dt 元素使用规则类似。tr 元素中只能够包含 th 和 td 元素。而 th 和 td 元素能够包含任何元素。例如，下面是一个正确、完整的表格嵌套结构。

- 网页都有多种显示模式，如怪**异模式（Quirks）、近标准模式（Almost Standards）和标准模式（Standards）**。其中标准模式也被称为非怪异模式（no-quirks）。浏览器会根据 DOCTYPE 来识别该使用哪种模式，以及使用什么规则来验证页面。

  - ` <meta charset="UTF-8"> `两种方法都有效，可以继续使用前面一种方式，即通过 content 元素的属性来指定。但是不能同时混合使用两种方式。在以前的网站代码中可能会存在下面代码所示的标记方式，但在 HTML 5 中，这种字符编码方式将被认为是错误的：

    可以省略标记的元素在 HTML 5 中，元素的标记可以省略。具体来说，元素的标记分为 3 种类型：不允许写结束标记、可以省略结束标记、开始标记和结束标记全部可以省略。下面简单介绍这 3 种类型各包括哪些 HTML 5 新元素。

   1. 不允许写结束标记的元素有 area、base、br、col、command、embed、hr、img、input、keygen、link、meta、param、source、track、wbr。
   2. 可以省略结束标记的元素有 li、dt、dd、p、rt、rp、optgroup、option、colgroup、thead、tbody、tfoot、tr、td、th。
   3. 可以省略全部标记的元素有 html、head、body、colgroup、tbody。
   4. 提示：  不允许写结束标记的元素是指，不允许使用开始标记与结束标记将元素括起来的形式，只允许使用 < 元素/> 的形式进行书写。例如，<br>...</br> 的书写方式是错误的，正确的书写方式为 <br/>。当然，HTML 5 之前的版本中 <br> 这种写法可以被沿用。可以省略全部标记的元素是指，该元素可以完全被省略。注意，即使标记被省略了，该元素还是以隐式的方式存在的。例如，将 body 元素省略不写时，但它在文档结构中还是存在的，可以使用 document.body 进行访问。


具有布尔值的属性对于具有 boolean 值的属性，如 disabled 与 readonly 等，当只写属性而不指定属性值时，表示属性值为 true；如果想要将属性值设为 false，可以不使用该属性。另外，要想将属性值设定为 true 时，也可以将属性名设定为属性值，或将空字符串设定为属性值。例如：


 省略引号属性值两边既可以用双引号，也可以用单引号。HTML 5 在此基础上做了一些改进，当属性值不包括空字符串、<、>、=、单引号、双引号等字符时，属性值两边的引号可以省略。例如，下面写法都是合法的。
<input type="text">     <input type='text'>     <input type=text>

1．新增的结构元素HTML 5 定义了一组新的语义化标记来描述元素的内容。虽然语义化标记也可以使用 HTML 标记进行替换，但是它可以简化 HTML 页面设计，并且将来搜索引擎在抓取和索引网页的时候，也会利用到这些元素的优势。在目前主流的浏览器中已经可以用这些元素了，新增的语义化标记元素如表 5.2 所示。


根据 HTML 5 效率优先的设计理念，它推崇表现和内容的分离，所以在 HTML 5 的实际编程中，开发人员必须使用 CSS 来定义样式。【示例】  在本示例中分别使用 HTML 5 提供的各种语义化结构标记重新设计一个网页，在没有 CSS 的情况下显示效果如图 5.2 所示。



HTML 5 新增功能元素 

hgroup 元素：用于对整个页面或页面中一个内容区块的标题进行组合。例如：    <hgroup>...</hgroup> 在 HTML 4 中表示为：    <div>...</div>  figure 元素：表示一段独立的流内容，一般表示文档主体流内容中的一个独立单元。使用 figcaption 元素为 figure 元素组添加标题。例如：

在 HTML 5 中废除了 HTML 4 过时的元素，简单介绍如下。 

能使用 CSS 替代的元素对于 basefont、big、center、font、s、strike、tt、u 这些元素，由于它们的功能都是表现文本效果，而 HTML 5 中提倡把呈现性功能放在 CSS 样式表中统一编辑，所以将这些元素废除了，并使用编辑 CSS、添加 CSS 样式表的方式进行替代。其中 font 元素允许由「所见即所得」的编辑器来插入，s 元素、strike 元素可以由 del 元素替代，tt 元素可以由 CSS 的 font-family 属性替代。 不再使用 frame 框架对于 frameset 元素、frame 元素与 noframes 元素，由于 frame 框架对网页可用性存在负面影响，在 HTML 5 中已不支持 frame 框架，只支持 iframe 框架，或者用服务器方创建的由多个页面组成的复合页面的形式，同时将以上这 3 个元素废除。
```
