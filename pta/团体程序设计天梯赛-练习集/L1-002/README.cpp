#include<iostream>
#include<cmath>
#define r(i,a,b) for(int i=a;i<b;i++)
#define rr(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main() {
	char u;
	double n;
	cin >> n >> u;
	int ceng = sqrt((n + 1) / 2);
	//cout << ceng;
	r(ii, 0, ceng) {
		r(kk, 0, ii) cout << " ";
		for (int jj = 2 * (ceng - ii) - 1; jj > 0; jj--) cout << u;
		cout << endl;
	}
	r(ii, 1, ceng) {
		for (int kk = ceng - ii - 2; kk >= 0; kk--)cout << " ";
		r(jj, 0, 2 * ii + 1) {
			cout << u;
		}
		cout << endl;
	}
	cout << n - 2 * ceng * ceng + 1;
}
