#Python 可以同一行显示多条语句，方法是用分号 ; 分开，如：
help(print)
a = 8
b = 3
print(a)
print(b)
print(a, b)
c = a // b  # 表示整除
d = a / b  # 表示保留小数的除法
print(c, "&", d)
e = 8
f = 3
print(e**f)  # 表示e的f次方
if (e == f):
    print("true")
else:
    print('false')
if e is not f:  # 两种效果等效-> is (not) & ==,!=
    print('true')
else:
    print('false')

print(a and b)
ai = [1, 2, 3, 4, 5, 6]
bi = ai * 2  # 重复序列
ai += bi  # 连接序列
print(bi, '&', ai)
#  字符串
stri = 'son of bitch!'
print('\\\'\"\b\000\n\v\t\r\f\012\x0a')
print('over\n')
print(stri[-2:-1])
if ('f ' in stri):
    print("stri, Yes!!!")
# #####################formay######################
# I decide to sell my soul to this dirty world beacause there're no thing is perfect, also everything about me. Maybe it would be a sigh in the end but damn right, haha.
print("{}" "{}".format("Hello", "World"))
print("{1} + {0} + {1}".format("hello", "world"))
print("Hello:{name}".format(name='lufenghua'))
print("pd={:.2f}".format(3.1415926))
print("{:0>5d}".format(10))
print("{value:#x}".format(value=25))  # HEX
# ######################list########################
l = list()
p = list(l)
pi = []
li = [1001, 211, 388, 404]
x = input()  # 输入字符串
# ###调用第三方库import sys sys.stdin（）; address: https://blog.csdn.net/shuwenting/article/details/79711869
l.append(x)
print(l)
l.insert(1, 3)
l.remove(3)
print(l)
l.pop()
print(l)
li.sort()
print(li)
# #####################range##########################
# r=range(10)
# r=range(5,15)
# r=range(0,10,2)
r = range(100, 10, -2)
lii = list(range(100, 150, 5))
print(lii)
# ####################dict############################
# 键值对集合
# d = dict
# d = {}
# d = dict(one=1, two=2, three=3)
d = {'one': 1, 'two': 2, 'three': 3}
l2 = list(d)
l2 = list(d.values())
print(d)
print(l2)
# ##################Tuple Set#########################
t = (1, 2)
# t=tuple(1,2,3,3,4,5)
# 一个不可变的列表 函数多返回值,dict的键
s = {1, 2, 3}
sa = set(s)
sa.add(4)
saa0 = s & sa
print(saa0)
saa1 = s | sa
print(saa1)
saa2 = sa - s
print(saa2)
# #######################异常##########################
try:
    i=int('a')
except Exception as e:
    print(e)
import errno
import os


def mkdir_p(path):
    try:
        os.makedirs(path)
    except OSError as e:
        if e.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else:
            raise
