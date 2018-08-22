#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void getNext(const string& s, vector<int>& next)
{
	next.clear();
	next.resize(s.size());
	next.at(0) = -1;
	int i = 1;
	int len = -1;
	while (i<s.size() - 1) {//注意下面将next后移一位，所以只循环到size-2
		if (len == -1 || s.at(i) == s.at(len)) {
			++i;
			++len;
			next.at(i) = len;
		}
		else {
			len = next.at(len);
		}
	}
}

void getNext(char *s, int next[])
{
	int slen = strlen(s);
	next[0] = -1;//第一个赋值-1
	int i = 1;
	int len = -1;
	while (i<slen - 1) {
		if (len == -1 || s[i] == s[len]) {
			++i;
			++len;
			next[i] = len;//将next整个往右移了一位
		}
		else {
			len = next[len];
		}
	}
}



int KMP(const string& s, const string& subs)
{
	vector<int> next;
	getNext(subs, next);


	int i = 0;
	int len = 0;
	int slen = s.size();
	int subslen = subs.size();
	while (i<slen && len<subslen) {//size()返回的是无符号的size_t类型， -1不能与之比较
		if (len == -1 || s[i] == subs[len]) {
			i++;
			len++;

		}
		else {
			len = next[len];
		}
	}
	if (len == subs.size()) {
		return i - len;
	}
	else {
		return -1;
	}
}

int KMP(char* s, char* subs)
{
	int slen = strlen(s);
	int subslen = strlen(subs);
	int *next = (int *)malloc(sizeof(int) * subslen);
	getNext(subs, next);
	int i = 0;
	int len = 0;
	while (i<slen && len<subslen) {
		if (len == -1 || s[i] == subs[len]) {
			++i;
			++len;
		}
		else {
			len = next[len];
		}
	}
	free(next);
	if (len == subslen) {
		return i - len;
	}
	else {
		return - 1;
	}
}


int main()
{
	string s = "goodgoogle";
	string subs = "google";
	cout << "==========" << endl;
	cout << KMP(s, subs) << endl;


	const char* cs = "goodgoogle";
	const char* csubs = "google";
	cout << "==========" << endl;
	cout << KMP(cs, csubs) << endl;

	system("pause");
}