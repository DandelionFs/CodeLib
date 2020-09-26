#include<iostream>
#include<algorithm>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int filtrate[11];
int main() {
	int k = 0;
	char p[12];
	cin.getline(p, 12);
	_for(i, 0, 12) {
		bool flag = false;
		_for(j, 0, k) if (filtrate[j] == (p[i] - '0')) flag = true;
		if (flag) continue;
		else  filtrate[k++] = p[i] - '0';
	}
	filtrate[k--] = '\0';
	/*
	18013820100
	这里调试一下发现第6个值出现了-48，但是k这个时候是6，应该存在5个值才对，最后一个值是从哪里来的就有待商榷了……
	*/
	sort(filtrate, filtrate + k, cmp);
	cout << "int[] arr = new int[]{";
	_for(i, 0, k - 1)cout << filtrate[i] << ",";
	cout << filtrate[k - 1] << "};\n";
	cout << "int[] index = new int[]{";
	_for(i, 0, 10) {
		_for(j, 0, k) {
			if (filtrate[j] == p[i] - '0') cout << j << ",";
		}
	}
	_for(i, 0, k) if (filtrate[i] == p[10] - '0') {
		cout << i << "};";
		break;
	}
}