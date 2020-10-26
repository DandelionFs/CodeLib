**[LINK]** https://segmentfault.com/a/1190000015131017
1. [Scrapy](https://scrapy.org/)  一个为了爬取网站数据，提取结构性数据而编写的应用框架。 可以应用在包括数据挖掘，信息处理或存储历史数据等一系列的程序中。
2. [PySpider](https://github.com/binux/pyspider)  能在浏览器界面上进行脚本的编写，功能的调度和爬取结果的实时查看，后端使用常用的数据库进行爬取结果的存储，还能定时设置任务与任务优先级等。
3. [Crawley](http://project.crawley-cloud.com/)   高速爬取对应网站的内容，支持关系和非关系数据库，数据可以导出为JSON、XML等。
4. [Portia](https://github.com/scrapinghub/portia)  开源可视化爬虫工具，可让您在不需要任何编程知识的情况下爬取网站！简单地注释您感兴趣的页面，Portia将创建一个蜘蛛来从类似的页面提取数据。
5. [Newspaper](https://github.com/codelucas/newspaper)  可以用来提取新闻、文章和内容分 析。使用多线程，支持10多种语言等。
6. [Beautiful Soup](https://www.crummy.com/software/BeautifulSoup/bs4/doc/)  一个可以从HTML或XML文件中提取数据的Python库.它能够通过你喜欢的转换器实现惯用的文档导航,查找,修改文档的方式.Beautiful Soup会帮你节省数小时甚至数天的工作时间。
7. [Grab](https://docs.grablib.org/en/latest/#grab-spider-user-manual.)  构建各种复杂的网页抓取工具，从简单的5行脚本到处理数百万个网页的复杂异步网站抓取工具。Grab提供一个API用于执行网络请求和处理接收到的内容，例如与HTML文档的DOM树进行交互。
8. [Cola](https://github.com/qinxuye/cola)  一个分布式的爬虫框架，只需编写几个特定的函数，而无需关注分布式运行的细节。任务会自动分配到多台机器上，整个过程对用户是透明的。

## 简单的爬虫架构

爬R构(=大模块)

- 爬虫调度端(启动/停止)
- URL管理器(URL队列管理防止重复爬取)
  网页下载器(网页内容下载)
- 网页解析器(提取新的待爬URL, 获取待爬的URL)
- 价值数据(提取价值数据)










