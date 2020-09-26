windows方法：win键+r键输入cmd调出命令行

输入：

查看MD5值：

certutil -hashfile 文件名  MD5

查看 SHA1

certutil -hashfile 文件名  SHA1 

查看SHA256

certutil -hashfile 文件名  SHA256


例子：

D:\Android_world\workspace\>certutil -hashfile log MD5
MD5 哈希(文件 log):
ff b3 9c 91 11 20 6c 84 07 11 2f e4 88 07 57 cf
CertUtil: -hashfile 命令成功完成。


LINUX方法，进入文件目录

输入：

md5sum 文件名


例子：

md5sum log