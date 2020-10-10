### Preface

最后决定放弃Gmail和Foxmail, 选用微软的outlook, 一个是长久易用, 一个是没有ADs.

以上

### 第三方客户端的配置

Foxmail 里面有这样的选择:

> + POP3/SMTP服务
> + IMAP/SMTP服务 
> + Exchange服务
> + CardDAV/CalDAV服务

+ POP3(Post Office Protocol - Version 3), 属于TCP/IP协议, 提供Https加密后变成 POPS(学生邮箱好像不允许?), POP3协议改进POP, 端口号110, 服务器上的邮件不会在转发后删除.[^1]
+ IMAP(Internet/Interactive Mail Access Protocol), 是一个应用层协议, 应用在 TCP/IP 协议之上, 斯坦福大学发明, 端口号143, 可以直接在客户端如对服务器的邮件进行操作.[^2]
+ SMTP(Simple Mail Transfer Protocol), 建立在FTP基础上, 默认端口号25, 用于系统之间的邮件系统传输, 提供来信的通知, 而SMTP可以挂月网络传输邮件, 也可以通过中继器或网关进行邮件的处理.[^3]
> SMTP是一个“推”的协议，它不允许根据需要从远程服务器上“拉”来消息。要做到这点，邮件客户端必须使用POP3或IMAP。另一个SMTP服务器可以使用ETRN在SMTP上触发一个发送。
+ Exchange Server是微软公司邮件服务组件。加入了一系列辅助功能(语音邮件、邮件过滤筛选、OWA(基于Web的电子邮件存取))[^4]
+ CardDAV/CalDAV: 前者是 远程地址簿信息访问（共享）协议, 用于客户端访问共享服务器上的联系人数据。后者是 允许客户端访问共享服务器上的日程信息。两者扩展了WebDav协议的规范， 并使用iCalendar格式的数据, 但是，国内的邮件系统基本不支持日程或者联系人的订阅服务. [^5]



[^1]: https://baike.baidu.com/item/POP3
[^2]: https://baike.baidu.com/item/imap
[^3]: https://baike.baidu.com/item/SMTP
[^4]: https://www.zhihu.com/question/24605584/answer/112250597
[^5]: https://blog.csdn.net/qq_36731677/article/details/82956977
