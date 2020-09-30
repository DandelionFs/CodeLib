#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);++i)
const int N = 10000000;
struct TS {
	int a, b, c;
};
inline bool cmp(const TS& t1, const TS&t2) {
	if (t1.a != t2.a)return t1.a < t2.a;
	if (t1.b != t2.b)return t1.b < t2.b;
	return t1.c < t2.c;
}
int cmp4qsort(const void* a, const void* b) {
	TS* t1 = (TS*)a, * t2 = (TS*)b;
	if (t1->a != t2->a)return t1->a - t2->a;
	if (t1->b != t2->b)return t1->b - t2->b;
	return t1->c - t2->c;
}
struct cmpFunctor {
	inline bool operator()(const TS& t1, const TS& t2) {
		if (t1.a != t2.a)return t1.a < t2.a;
		if (t1.b != t2.b)return t1.b < t2.b;
		return t1.c < t2.c;
	}
};
TS tss[N];
void genData() {
	_for(i, 0, N) {
		tss[i].a = rand();
		tss[i].b = rand();
		tss[i].c = rand();
	}
}
int main() {
	srand(time(NULL));

	genData();
	clock_t start = clock();
	sort(tss, tss + N, cmp);
	printf("sort by functor pointer: %ld\n", clock() - start);

	genData();
	start = clock();
	sort(tss, tss + N, cmpFunctor());
	printf("sort by functor: %ld\n", clock() - start);

	genData();
	start = clock();
	qsort(tss, N, sizeof(TS), cmp4qsort);
	printf("qsort by functor pointer: %ld\n", clock() - start);

	return 0;
}
