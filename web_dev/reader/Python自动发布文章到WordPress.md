# 【SEO流量贩子】Python自动发布文章到WordPress

[地址](https://www.imahui.com/design/138.html)

这篇是Bigway同学的投稿，一个用py实现wp自动发文的小脚本.

**解决思路**

> 1、利用post向wordpress提交表单
>
> 2、通过wordpress_xmlrpc模块，有轮子不用想干啥
>
> 3、通过mysqldb直接插入数据库，有服务器、不需远程，直接把py脚本放在服务器跑

我们这次要用轮子拼一台摩托车！，宝马、、自己动手吧

**开始动手：**

需自行安装的模块requests，xmlrpc；windows系统、linux安装如下，土豪随意：

```
pip install requests
pip install python-wordpress-xmlrpc
```

Python采集文件 **caiji.py** 代码

```
#encoding=utf-8
'''练手可以找wp博客来采集，这个脚本就是针对wp博客来做下手采集的'''
import re,requests,time,random,urllib,threading
from wordpress_xmlrpc import Client, WordPressPost
from wordpress_xmlrpc.methods.posts import GetPosts, NewPost

'''登录'''
try:
 wp=Client('http://www.example.com/xmlrpc.php','wp的账号','wp的密码')
except Exception, e:
 wp=Client('http://www.example.com/xmlrpc.php','wp的账号','wp的密码')
post=WordPressPost()

'''针对单站url重复采集问题'''
f=open('url.txt','a+')
urls=f.read()
url_list=[m.strip() for m in open('url.txt').readlines()]
daili_list=[]

'''过滤html标签'''
def filter_tags(htmlstr):
 re_cdata=re.compile('//<!\[CDATA\[[^>]*//\]\]>',re.I) #匹配CDATA
 re_script=re.compile('<\s*script[^>]*>[^<]*<\s*/\s*script\s*>',re.I)#Script
 re_style=re.compile('<\s*style[^>]*>[^<]*<\s*/\s*style\s*>',re.I)#style re_br=re.compile('<br\s*?/?>')#处理换行
 re_br=re.compile('<br />')
 re_h=re.compile('</?\w+[^>]*>')#HTML标签
 re_comment=re.compile('<!--[^>]*-->')#HTML注释
 s=re_cdata.sub('',htmlstr)#去掉CDATA
 s=re_script.sub('',s) #去掉SCRIPT
 s=re_style.sub('',s)#去掉style
 s=re_br.sub('\n',s)#将br转换为换行
 s=re_h.sub('',s) #去掉HTML 标签
 s=re_comment.sub('',s)#去掉HTML注释
 blank_line=re.compile('\n+')#去掉多余的空行
 s=blank_line.sub('\n',s)
 return s

'''轮换user-agent'''
def getUA():
 uaList = [
 'Mozilla/4.0+(compatible;+MSIE+6.0;+Windows+NT+5.1;+SV1;+.NET+CLR+1.1.4322;+TencentTraveler)',
 'Mozilla/4.0+(compatible;+MSIE+6.0;+Windows+NT+5.1;+SV1;+.NET+CLR+2.0.50727;+.NET+CLR+3.0.4506.2152;+.NET+CLR+3.5.30729)',
 'Mozilla/5.0+(Windows+NT+5.1)+AppleWebKit/537.1+(KHTML,+like+Gecko)+Chrome/21.0.1180.89+Safari/537.1',
 'Mozilla/4.0+(compatible;+MSIE+6.0;+Windows+NT+5.1;+SV1)',
 'Mozilla/5.0+(Windows+NT+6.1;+rv:11.0)+Gecko/20100101+Firefox/11.0',
 'Mozilla/4.0+(compatible;+MSIE+8.0;+Windows+NT+5.1;+Trident/4.0;+SV1)',
 'Mozilla/4.0+(compatible;+MSIE+8.0;+Windows+NT+5.1;+Trident/4.0;+GTB7.1;+.NET+CLR+2.0.50727)',
 'Mozilla/4.0+(compatible;+MSIE+8.0;+Windows+NT+5.1;+Trident/4.0;+KB974489)',
 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.101 Safari/537.36',
 'Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.101 Safari/537.36',
 ]
 ua = random.choice(uaList)
 return ua

'''提取正则'''
def search(re_url,html):
 re_Data=re.findall(re_url,html)
 if re_Data:
 return re_Data[0]
 else:
 return 'no'

'''轮换ip'''
def ip():
 for x in open('daili.txt'):
 x = x.strip()
 daili_list.append(x)
 newip = random.choice(daili_list)
 return newip

'''获取html'''
def gethtml(url,headers):
 while 1:
 try:
 newip=ip() 
 proxies={"http":"http://%s"%newip.strip()} 
 pages=requests.post(url,headers,proxies,timeout=10)
 html=pages.content
 code=pages.status_code
 if '404' '302 Found' in html or code != 200 in html:
 print u'代理失效重试'
 continue
 elif 'verify' in html:
 print u'出验证码，重试'
 continue
 else:
 return html
 except Exception, e:
 # print e
 continue

'''正则用以提取列表页上的url，需根据实际情况来调整'''
re_url=re.compile(r'<a rel="nofollow" target="_blank" href="https://www.imahui.com/go.php?url=KGh0dHA6Ly93d3dcLmV4YW1wbGVcLmNvbS8uKj9cZCtcLmh0bWwp"')

'''正则用以提取内页上的title和正文内容content，当然也可以使用readability模块，正则需根据实际情况做修改'''
re_title_content=re.compile(r'<h1 class="entry-title">(.*?)</h1>[\s\S]*?<div class="entry-content">([\s\S]*?)<div class="clear">')

'''成功通过wordpress-xmlrpc模块自动发布文章到wordpress'''
def getData(url):
 headers={'User-Agent':'%s'%getUA(),} 
 html=gethtml(url,headers)
 re_Data=re.findall(re_url,html)
 mutex.acquire()
 for i in re_Data:
 i=i.strip()
 print i
 if i not in url_list and i not in urls:
 url_list.append(i)
 f.write(i+'\n')
 page=gethtml(i,headers)
 page_Data=re.findall(re_title_content,page)
 for n in page_Data:
 # print type(n)
 try:
 title=n[0]
 content=filter_tags(n[1]) 
 except:
 title=0
 content=0
 if title and content:
 # print title,content
 '''发布到wp'''
 post.title=title
 post.content=content
 post.post_status = 'publish'
 wp.call(NewPost(post))
 print 'Updates'
 else:
 pass
 else:
 print 'Noposts updates'
 continue 
 mutex.release()

def getRange(l, r):
 for i in url_list[l:r]:
 getData(i)

'''将列表页放到list的数据类型当中'''
url_list = []
for line in range(1,15):
 line = 'http://www.example.com/page/%d'%line
 word = line.strip()
 url_list.append(word)

'''多线程'''
totalThread = 5 
gap = (len(url_list) - 1) / totalThread 
mutex = threading.Lock()
for i in range(1, len(url_list),gap): 
 t = threading.Thread(target=getRange,args=(i, i+gap,))
 t.start()

f.close()
```

设置采集内容到哪个默认目录，可以在wp后台设置，从代码上做修改也可以；

具体可以看看xmlrpc官方文档：http://python-wordpress-xmlrpc.readthedocs.io/en/latest/overview.html

另外可以通过命令crontab -e 让脚本按需自动跑起来！







SEO: Search,engine,optionization