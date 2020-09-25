# GCD&LCM

## 辗转相除法（欧几里德算法）（Euclidean algorithm）

Greatest common divisor&least common multiple10.29[·](https://blog.csdn.net/qq_42504734/article/details/88369780)

基于一个定理：两个正整数a和b（a>b），它们的最大公约数等于a除以b的余数c和b之间的最大公约数。但是当数字比较大的时候a%b的性能会变差也是理所当然。

```c++
int cdivisor(int m, int n) {
	int a, b, r;
	a = (m > n) ? m : n;
	b = (m > n) ? n : m;
	r = b;
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
```



## 更相减损术

出自《九章算术》，也是一种求最大公约数的算法。两个正整数a和b（a>b），它们的最大公约数等于a-b的差值c和较小数b的最大公约数。（可以用递归实现）

```c++
int cdivisor(int a, int b) {
	while (a != b) {
		if (a > b)a -= b;
		else b -= a;
	}
	return a;
}
```





## Reference

1. https://blog.csdn.net/qq_42504734/article/details/88369780