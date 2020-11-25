## Linux 安全吗[^1][^2]

如果有人觉得 Linux 不会受到恶意软件的攻击，或者不存在所谓的 Linux 恶意软件，那就是大错特错。 随着使用 Gnome 桌面环境的 Linux 操作系统日益流行，恶意软件编写者对 Linux 的兴趣日益增强。网络后台驻留程序中的漏洞也可以被蠕虫病毒利用。

最近，出现了一些 可以同时在 Windows 和 Linux 环境中运行的跨平台威胁，例如： [Perl.BadBunny](http://www.symantec.com/security_response/writeup.jsp?docid=2007-052400-3656-99)、 [SB.BadBunny](http://www.symantec.com/security_response/writeup.jsp?docid=2007-052303-2513-99)、 [IRC.BadBunny](http://www.symantec.com/security_response/writeup.jsp?docid=2007-052303-3350-99)、 [Ruby.BadBunny](http://www.symantec.com/security_response/writeup.jsp?docid=2007-052400-4529-99) 等。 当您阅读电子邮件或上网冲浪时，恶意软件内容也可能会被下载或发送给您。 此外，还应定期扫描 SAMBA 和 NFS 服务器，以检查它们是否受到感染。

## 种类

**恶意软件**

恶意软件 (Malware)  是具有恶意的软件 (malicious software) 的缩写，用作一个术语来指代病毒、间谍软件、蠕虫等。恶意软件的设计目的是损害独立计算机或联网电脑。所以无论恶意软件术语被用于何处，它都指一个以损害您的计算机为目的的程序，它可能是病毒、蠕虫或特洛伊木马。

**病毒**

病毒是一个为进入您的计算机并损坏/更改您的文件/数据而编写的程序。病毒可能会损坏或删除计算机上的数据。病毒也可以自我复制。计算机病毒比计算机蠕虫更危险，因为它会更改或删除您的文件，而蠕虫只会自我复制，但不更改您的文件/数据。

**病毒的例子包括：**
**W32.Sfc!mod
ABAP.Rivpas.A
Accept.3773**

病毒能够以图像附件、问候语或音频/视频文件的形式进入到您的计算机。病毒也通过互联网下载而进入。它们可以隐藏在您下载的免费/试用版软件或其他文件中。

所以，在从互联网下载任何东西之前，务必首先检查其安全性。几乎所有病毒都附加于可执行文件，这意味着您的计算机上可能存在病毒，但实际上，除非您运行或打开恶意程序，否则它无法感染您的计算机。重要的是要注意，病毒无法在没有人为行为的情况下传播，例如运行被感染程序让病毒一直传播。
**间谍软件**

间谍软件是经过或未经过您许可的情况下安装在个人计算机上的一种程序，其目的是收集关于用户、用户的计算机或浏览习惯的信息，在您毫不知情的情况下跟踪您所做的每件事情并将其发送给远程用户。它也可以从互联网下载其他恶意程序，并将其安装在计算机上。间谍软件的工作方式与广告软件类似，但它通常是一个独立程序，会在您安装另一个免费软件类型的程序或应用程序时不知不觉地安装。

**特洛伊木马**

特洛伊木马不是病毒。它是看起来像正版应用程序的破坏性的程序。与病毒不同，特洛伊木马不会自我复制，但它们具有同样大的破坏力。特洛伊木马还会在您的计算机上打开一个后门入口，使恶意用户/程序能够访问您的系统，窃取保密信息和个人信息。

示例： - JS.Debeski.Trojan

特洛伊木马根据其感染系统的方式及其造成的损害进行分类。七种主要的特洛伊木马类型包括：

• 远程访问特洛伊木马 
• 数据发送特洛伊木马 
• 破坏型特洛伊木马 
• 代理特洛伊木马 
• FTP 特洛伊木马 
• 安全软件禁用特洛伊木马 
• 拒绝服务攻击特洛伊木马

**蠕虫**

蠕虫是在本地驱动器、网络共享等位置一次次进行自我复制的恶意程序。蠕虫的唯一目的是一次次地进行自我复制它不会损坏计算机上的任何数据/文件。与病毒不同的是，它不需要将自己附加于现有程序。蠕虫通过利用操作系统中的漏洞来传播

蠕虫的例子有：

W32.SillyFDC.BBY
Packed.Generic.236 
W32.Troresba

因为蠕虫具有复制性质，因此它会占用大量硬盘驱动器空间并消耗更多的 CPU 资源，从而让电脑运行非常缓慢，而且还会消耗更多网络带宽。

**以下是不同类型的文件型病毒：**这种类型的病毒通常会感染 .exe、.com、.bat 等程序文件。一旦这种病毒驻留在内存中，它就会尝试感染所有加载到内存的程序。

**宏病毒：** 这些类型的病毒会感染 Word、Excel、PowerPoint、Access 和其他数据文件。这些文件一旦受到感染就很难修复。

**主引导记录文件：** MBR 病毒是内存驻留型病毒，它将其自身复制到用于分区表或操作系统加载程序的存储设备的第一个扇区。MBR 病毒会感染存储设备的这个特定区域而不是普通文件。删除 MBR 病毒的最简单方法是清理 MBR 区域。

**引导扇区病毒：** 引导扇区病毒会感染硬盘或软盘的引导扇区。这些病毒的性质也是内存驻留型。在计算机启动之后，它将被引导扇区感染。 清理这种病毒非常困难。

**多型病毒：** 引导病毒和程序/文件病毒的混合体。它们会感染程序文件，当感染的程序被执行时，这些病毒会感染引导记录。下次启动计算机时，引导记录中的病毒会在内存中加载，然后开始感染磁盘上的其他程序文件

**多态病毒：** 一种可以以不同方式加密其代码，使其在每次感染中具有不同的形态的病毒。这些病毒更难检测。

**隐藏病毒：** 这些类型的病毒使用不同种类的技术来躲避检测。它们会将磁盘头重定向为读取另一个扇区而不是其驻留的扇区，它们也可能会改变目录列表中显示的被感染文件大小的读数。例如，Whale 病毒向被感染文件添加 9216 个字节；然后该病毒从目录中给出的大小中减去相同数量的字节 (9216)。

**广告软件**

一般而言，广告软件是一种在任何程序运行时显示广告横幅的软件应用程序。广告软件可以在您浏览任何网站时自动下载到您的系统，并可以通过弹出窗口或通过自动显示在电脑屏幕上的横条来让人们看到。公司会使用广告软件进行营销。

**跟踪 Cookie**

Cookie 是存储在您的计算机上的 Cookie 文件夹中的纯文本文件，它会存储有关浏览会话的数据。Cookie 被许多网站用于跟踪访问者信息。跟踪 Cookie 是 Cookie 的一种，它可以跟踪您的所有浏览信息，而黑客和公司也可以使用它来了解您的银行帐户详情、信用卡信息等所有个人信息，而这非常危险。

**垃圾邮件**

垃圾邮件发送是通过相同邮件的副本来对互联网进行洪水攻击的一种方法大多数垃圾邮件是发送给用户的毫无用处的电子邮件商业广告。垃圾邮件也被称为电子垃圾邮件或垃圾新闻组帖子。这些垃圾邮件非常让人讨厌，因为它每天不请自来，装满您的邮箱。

**误导性应用程序**

误导性应用程序为您提供错误的计算机安全状态，并显示您的计算机被某些恶意软件感染，您必须下载工具才能消除威胁。当您下载该工具时，它会在您的计算机上显示一些威胁。而要将这些威胁删除，您必须购买要求提供某些个人信息（如信用卡信息）的产品，而这非常危险。


## Cookie
> 什么是cookie？    

Cookie是由计算机上的网页存储的少量信息。    

> 为什么网页使用cookies？    

网页没有内存。 如果您在网站上从一个页面浏览到另一个页面，则不会将其识别为同一用户。 Cookie允许网页识别您的浏览器。 因此，Cookie基本上用于记住您选择的选项.Cookie还确保当您再次访问网页时，它可以识别您。    

> 所有的cookies都有相同的功能吗？

不，有不同类型的Cookie，它们用于不同的目的。 Cookie可以按功能，持续时间和谁存储在网页中进行区分    

> cookies类型？

我们的网站使用以下类型的Cookie : 

1. 技术性cookies：我们尽力为用户提供先进且易于使用的网页，以自动适应他们的需求和愿望。 为了达到这个目的，我们使用技术cookies向您展示我们的网站，使其正常工作，创建您的用户帐户，开始您的会话并管理您的预订。 这些技术性cookies对于我们的网站正常运作是绝对必要的。
2. 分析性cookie：我们使用这些cookie来了解用户如何使用网站，检测哪些有效，哪些无效，优化和改进网站，并确保我们的用户继续认为我们的网站有趣且相关。 我们只获取匿名信息，因此我们永远不会知道您是谁。 我们针对此类Cookie的合作者包括：Google，Hotjar，ABTasty和autopix.gnuinux.c
3. 广告Cookie：我们使用它们向您展示其他网站上的Goldcar.es广告。 这种形式的广告称为“重定向”，主要基于您在我们页面上的活动，例如您搜索过的目的地或您咨询过的住宿。 我们与此类Cookie的合作者包括：Google，Criteo，Tradedoubler，CJ Affiliate，Trabber，Bing，Yandex，Kayak，Skyscanner，YouTube，Facebook，Doubleclick，Trustpilot，Tutiempo.net和yahoo.com。    Cookie的管理    您可以通过配置计算机上安装的浏览器选项来允许，阻止或删除计算机上安装的Cookie。        


### 为何访问一些网站总出现在下方的提示条

> European Union laws require you to give European Union visitors information about cookies used and data collected on your blog. In many cases, these laws also require you to obtain consent. Out of courtesy, we have added a notice on your blog to explain Google's use of certain Blogger and Google cookies, including use of Google Analytics and AdSense cookies, and other data collected by Google. You are responsible for confirming that this notice actually works for your blog, and that it displays. If you employ other cookies, for example by adding third-party features, this notice may not work for you. If you include functionality from other providers there may be extra information collected from your users.

欧盟法律要求您向欧盟访问者提供有关所用Cookie和博客上收集的数据的信息。 在许多情况下，这些法律还要求您获得同意。

出于礼貌，我们在您的博客上添加了一条通知，以解释Google对某些Blogger和Google cookie的使用，包括对Google Analytics（分析）和AdSense cookie的使用以及Google收集的其他数据。

您有责任确认此通知确实适用于您的博客并显示。 如果您使用其他cookie（例如通过添加第三方功能），则此通知可能对您不起作用。 如果您包括其他提供商的功能，则可能从您的用户那里收集了更多信息。


+ Firefox浏览器的更多信息请访问: http://support.mozilla.org/es/products/firefox/cookies
+ Chrome浏览器的更多信息，请访问: http://support.google.com/chrome/bin/answer.py?hl=zh_CN&answer=95647
+ Explorer浏览器浏览器的更多信息：http://windows.microsoft.com/eses/windows7/how-to-manage-cookies-in-internet-explorer-9
+ Safari浏览器的更多信: 请访问http://support.apple.com/kb/ph5042
+ Opera浏览器http://help.opera.com/Windows/12.00/esES/cookies.html



## 保护自己的IP地址

Cookie的實際作用就是伺服器暫存在你電腦上的一個小檔案，記錄你輸入的資料或是文字，當你下次再到這個頁面時，就可以直接利用這個小檔案來辨識你的身份，讀取這個小檔案取代你的手動輸入或是操作。因此，無痕模式清除Cookie的目的，是讓日後使用同一台電腦的人，不會因為Cookie的作用而意外獲得只有你才知道怎麼輸入的資料，而不是不讓網站追蹤你。

不過，也因為「隱私」、「無痕」這類的名詞讓很多人容易誤解，也證明真的有很多人需要真正的隱私的需求，因此像是Firefox，就另外有「追蹤保護」的功能，

Firefox的追蹤保護功能，就比較符合那些不想要被網站追蹤監控者的需求，它的原理是利用封鎖清單，來封鎖常見的一些追蹤器。又有基礎保護清單以及嚴格保護清單兩種：

- 基礎保護清單將封鎖常見的分析追蹤器、社群分享追蹤器、以及廣告追蹤器。然而，基礎保護清單將允許部分內容追蹤器以避免網頁毀損。 

- 嚴格保護清單將封鎖所有已知的追蹤器包括分析、追蹤、社群分享、廣告追蹤器，也包含內容追蹤器。嚴格保護清單將破壞某些影片、照片幻燈秀、以及部分社群網站的功能。  

不過，這些追蹤保護能夠做的功能，最明顯的效果就是讓特定廣告不會如影隨形的跟著你。比方說，你今天可能瀏覽了某個網站上關於首爾的資訊，甚至可能訂了張去東京的機票，接下來你可能無論上FB、新聞網站、入口網站，永遠都會看到這些相關的廣告，這些是可以改變的。但是，如果你要防止因為「誤闖」了危險的色情網站，導致被灌入惡意程式之類的危險，依然還是沒辦法的，這些可能還是要靠防毒軟體或是防火牆的幫忙才行。

因此，瀏覽器的隱私模式並不是萬靈丹，也不會讓你百毒不侵。如果你今天上了一個駭客特製的網站，這個網站的目的就是要竊取你的資料，那麼你不管是用隱私模式或是追蹤保護，都一樣無法阻擋。





[^1]:https://www.websecurity.digicert.com/zh/cn/security-topics/do-we-really-need-antivirus-linux
[^2]:https://www.websecurity.digicert.com/zh/cn/security-topics/what-are-malware-viruses-spyware-and-cookies-and-what-differentiates-them#
[^3]:

