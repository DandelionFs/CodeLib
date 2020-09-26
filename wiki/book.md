https://sspai.com/post/47092	



说不清，俺只知道现在打开口令解不了，编辑限制可以移除；



http://www.sci666.com.cn/10914.html

是利用[PDF文档](https://www.baidu.com/s?wd=PDF文档&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)zd的漏洞造成系统内存溢出错误，然后出错处理过程中获得[root权限](https://www.baidu.com/s?wd=root权限&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)，修改boot模块而获得最终控制权。

一般存在于低专版本Acrobat 生成的[pdf文件](https://www.baidu.com/s?wd=pdf文件&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)中，比如Acrobat X 生成的[PDF文件](https://www.baidu.com/s?wd=PDF文件&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)就很困难了，所以基本上也只是9.0版本以前的加密破解

打开密码、远程认证很难破解，编属辑、打印等权限密码相对容易破解





https://blog.csdn.net/pdfMaker/article/details/1039046



# mobi, azw, azw3, epub 格式有什么区别

https://bookfere.com/post/27.html

刚接触 Kindle 的小伙伴经常会被 mobi、azw、azw3、epub  等常见的几个格式搞的很凌乱，它们都有哪些区别呢？又各有什么优缺点呢？哪个好一些呢？其实 Amazon  的电子书格式比这可多多了，完全可以单独写一篇文章来解释，但是太技术性的也没什么必要，我们只需要知道这几个常见格式的区别就可以了。笔者汇总了一些资料，为各位小伙伴们通俗地科普一下。

这几种电子书格式从本质上来说都是从 HTML 文档转换而来，大多数 HTML 标签和 CSS 样式表的特性它们都支持，它们之间的主要区别在于对排版及新特性的支持与否上，为了更方便清晰的理解，笔者将这几种格式分门别类地为各位小伙伴详细解释一下：

## 什么是 mobi、azw 格式

mobi 和 azw 格式的推手主要是 Amazon，这两种电子书格式的发展很大程度上依靠 Amazon 这个巨大的内容提供商及其电子书阅读器  Kindle 的流行普及。它们同属亚马逊的私有格式，没有本质的区别，可以简单的这样理解，mobi 是比较老的一种格式，而 azw 只是 mobi 的另一种形式而已，也可以理解为 mobi 加了个壳，亚马逊利用它对电子书做 DRM 版权保护。

目前市面上的 mobi  文件大部分是来自两种途径：epub、pdf 或者 txt 转换成的 mobi，从 Amazon 商店流出来的  mobi。前者没什么好说的，后者要么是 Amazon 官方制作，要么就是自出版作者通过 KDP (Kindle Direct  Publishing，作者可以绕过出版社直接在 Amazon 上发售电子书 )平台发布，通过 KDP 平台发布时，作者只需要上传 Word  文档，其他的事情也是 Amazon 官方来做，从而保证了 mobi 文件的规范程度。

## 什么是 azw3 格式

azw3 的本质是 KF8，是随着 2011 年 Amazon 推出 Kindle Fire 平板时一起推出的。它填补了 Mobi  对于复杂排版支持的缺陷，支持很多 HTML5（目前尚不支持 HTML5 的视频和音频标签）和 CSS3 的语法，这就大大改善了原来 mobi 或 azw 内容排版上的一些缺陷，单纯从读者的角度来讲，是不输 epub 格式的。目前从 Amazon 购买的书，大部分已经是 azw3  格式了，而以前主流的 mobi 格式则越来越少，它正逐渐取代 mobi 成为 Kindle 电子书的主流格式。

## 什么是 epub 格式

下面是维基百科对 epub 的一段定义：

> EPUB（Electronic Publication 的缩写，电子出版）是一种电子图书标准，由国际数字出版论坛（IDPF）提出；其中包括 3 种文件格式标准（文件的附文件名为 .epub），这个格式已取代了先前的 Open eBook 开放电子书标准。

epub 格式对于复杂的排版，图表，公式等元素的兼容性比 mobi 格式好很多，在脚本，公式，矢量图形的支持方面也强过 mobi 格式，现阶段 epub 格式的优势体现在图文混排、图片嵌入字体等，未来可预测的优势是 epub 格式对于声音，影像等多媒体内容互动的支持上。

epub 格式是开放标准，所以在开发工具上也会有更大的选择，像 Sigil、Calibre、Jutoh 等软件都可以让用户自助制作  epub 格式电子书，但因为良莠不齐的制作也导致一个问题：大量的 epub 文件其实是不符合标准，无法保证在所有支持 epub  的硬件和软件上都可以顺利阅读，这就和 iOS 系统和 Android 系统的区别有些相似。

## 亚马逊为什么不采用开放标准的 epub 格式呢？

为什么亚马逊不选择 epub 这种竞争对手（如  Google、苹果）和图书馆普遍采用的标准电子书格式呢？亚马逊解释说他们的创新速度很快，采用它们自己的标准格式，能够将创新成果迅速结合到产品中去。例如，Whispersync  技术（该技术通过无线接入互联网，将电子书阅读进度信息同步到各种阅读器上）以及字号放大缩小的技术。采用其他格式的电子书阅读器，以后也能把这些功能结合进来。但是，我们在提高产品性能上动作十分迅速。采用自己的格式是非常有利的，因为不用等第三方格式跟进之后再动手。

对于我们普通读者来说，其实只需要知道越新的格式其支持的特性多，更能改善、提升我们的阅读体验就可以了。这样也就不难理解为什么再用 Calibre 等工具将 azw3 转换成 mobi 后会产生丢失格式的问题了，毕竟新的特性一般都不会被老格式兼容。

# JEL分类系统

**JEL分类系统**，是美国经济学会《[经济文献杂志](https://zh.wikipedia.org/w/index.php?title=经济文献杂志&action=edit&redlink=1)》（Journal of Economic Literature）所创立的对[经济学](https://zh.wikipedia.org/wiki/经济学)文献的主题分类系统，并被现代西方经济学界广泛采用。该分类方法主要采用开头的一个[英文](https://zh.wikipedia.org/wiki/英文)[字母](https://zh.wikipedia.org/wiki/字母)与随后的两位[阿拉伯数字](https://zh.wikipedia.org/wiki/阿拉伯数字)一起对经济学各部类进行“辞书式”编码分类。

例如，C71为“C：数理和数量方法”类中，“C7博弈论与讨价还价理论”中的有关“C71：合作博弈”的内容。

- **A**: [经济学总论和教学](https://zh.wikipedia.org/w/index.php?title=经济学总论和教学&action=edit&redlink=1) (General Economics and Teaching)
- **B**: [经济学思想流派和方法论](https://zh.wikipedia.org/w/index.php?title=经济学思想流派和方法论&action=edit&redlink=1) (Schools of Economic Thought and Methodology)
- **C**: [数理和数量方法](https://zh.wikipedia.org/w/index.php?title=数理和数量方法&action=edit&redlink=1) (Mathematical and Quantitative Methods)
- **D**: [微观经济学](https://zh.wikipedia.org/wiki/微观经济学) (Microeconomics)
- **E**: [宏观和货币经济学](https://zh.wikipedia.org/w/index.php?title=宏观和货币经济学&action=edit&redlink=1) (Macroeconomics and Monetary Economics)
- **F**: [国际经济学](https://zh.wikipedia.org/wiki/国际经济学) (International Economics)
- **G**: [金融经济学](https://zh.wikipedia.org/wiki/金融经济学) (Financial Economics)
- **H**: [公共经济学](https://zh.wikipedia.org/wiki/公共經濟學) (Public Economics)
- **I**: [卫生，教育和福利](https://zh.wikipedia.org/w/index.php?title=卫生，教育和福利&action=edit&redlink=1) (Health, Education and Welfare)
- **J**: [劳动和人口经济学](https://zh.wikipedia.org/w/index.php?title=劳动和人口经济学&action=edit&redlink=1) (Labour and Demographic Economics)
- **K**: [法律和经济学](https://zh.wikipedia.org/w/index.php?title=法律和经济学&action=edit&redlink=1) (Law and Economics)
- **L**: [产业组织](https://zh.wikipedia.org/w/index.php?title=产业组织&action=edit&redlink=1) (Industrial Organization)
- **M**: [企业管理和商务经济学](https://zh.wikipedia.org/w/index.php?title=企业管理和商务经济学&action=edit&redlink=1)；[市场学](https://zh.wikipedia.org/wiki/市場學)；[会计学](https://zh.wikipedia.org/wiki/会计学) (Business Administration and Business Economics; Marketing; Accounting)
- **N**: [经济史](https://zh.wikipedia.org/wiki/经济史)（Economic History）
- **O**: [经济发展](https://zh.wikipedia.org/wiki/經濟發展)，[技术变迁和增长](https://zh.wikipedia.org/w/index.php?title=技术变迁和增长&action=edit&redlink=1) (Economic Development,innovation， Technological Change, and Growth)
- **P**: [经济系统](https://zh.wikipedia.org/w/index.php?title=经济系统&action=edit&redlink=1) (Economic Systems)
- **Q**: [农业和自然资源经济学](https://zh.wikipedia.org/w/index.php?title=农业和自然资源经济学&action=edit&redlink=1) (Agricultural and Natural Resource Economics)
- **R**: [城市，农村和区域经济学](https://zh.wikipedia.org/w/index.php?title=城市，农村和区域经济学&action=edit&redlink=1) (Urban, Rural and Regional Economics)
- **Z**: [其他专题](https://zh.wikipedia.org/w/index.php?title=其他专题&action=edit&redlink=1) (Other Special Topics)

以上所列为对开头字母的一级部门分类，具体的细致分类请参照**外部链接**中有关美国经济学会《经济文献杂志》分类系统的连接。



## 外部链接

- [美国经济学会 (American Economic Association) ](http://www.vanderbilt.edu/AEA/)（英文）
- [《经济文献杂志》分类系统（*Journal of Economic Literature* Classification System）](http://www.aeaweb.org/journal/jel_class_system.html)（英文）
