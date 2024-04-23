#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAXSIZE 10


struct List {
	int* data;
	int length;
	int capacity;
}Mylist;

bool Initsize(List& l) {
	l.data = new int[MAXSIZE];
	l.capacity = MAXSIZE;
	if (l.data == NULL) {
		cout << "space false" << endl;
		return false;
	}
	l.length = 0;
	return true;
}

bool createrlist(List& l) {
	if (l.length >= l.capacity) {
		cout << "表满了" << endl;
		return false;
	}
	srand((time(0)));
	for (int i = 0; i < l.capacity ; i++) {
		int temp = rand() % 100 + 1;
		l.data[i] = temp;
		l.length++;
	}
	cout << "随机表创建成功" << endl;
	return true;
}

bool emptylsit(List& l) {
	if (l.length == 0) {
		cout << "list is empty" << endl;
		return true;
	}
	else {
		cout << "lsit is not empty" << endl;
		return false;
	}
}

void printlist(List l) {
	if (l.length == 0) {
		cout << "list is empty" << endl;
		return;
	}
	cout << "表中有:" ;
	for (int i = 0; i < l.length; i++) {
		cout << l.data[i] << " " ;
	}
	cout << endl;
	return;
}

void complement(List& l,int pos) {
	if (emptylsit(l) == true) {
		return;
	}
	for (int i = pos; i < l.length - 1; i++) {
		l.data[i] = l.data[i + 1];
	}
	l.length--;
	return;
}

int Q1(List& l) {
	if (emptylsit(l) == true) {
		return 0;
	}
	int cp = l.data[0], pos = -1;
	for (int i = 0; i < l.length; i++) {
		if (cp > l.data[i]) {
			cp = l.data[i];
			pos = i;
		}
	}
	l.data[pos] = l.data[l.length - 1];
	l.length--;
	return cp;
}

void Q2(List& l) {
	if (emptylsit(l) == true) {
		return;
	}
	int temp;
	for (int i = 0; i < l.length / 2; i++) {
		temp = l.data[i];
		l.data[i] = l.data[l.length - i - 1];
		l.data[l.length - i - 1] = temp;
	}
	return;
}

void Q3(List& l) {
	if (emptylsit(l) == true) {
		return;
	}
	cout << "input what you want to delete";
	int temp;
	cin >> temp;
	cout << endl;
	for (int i = 0; i < l.length; i++) {
		if (l.data[i] == temp) {
			complement(l, i);
			--i;
		}
	}
	return;
}

void Q4(List& l) {
	if (emptylsit(l) == true) {
		return;
	}
	int s, t;
	cout << "请输入起始值" << endl;
	cin >> s;
	cout << "请输入结束值" << endl;
	cin >> t;
	if (s < 0 || t>100) {
		cout << "范围不合理" << endl;
		return;
	}
	for (int i = 0; i < l.length; i++) {
		if (l.data[i] > s && l.data[i] < t) {
			l.data[i] = -1;
		}
	}
	return;
}


void Q5(List& l) {
	if (emptylsit(l) == true) {
		return;
	}
	int a;
	for (int i = 0; i < l.length; i++) {
		a = l.data[i];
		for (int j = i + 1;j<l.length ; j++) {
			if (l.data[j] == a) {
				complement(l, j);
				j--;
			}
		}
	}
	return;
}

List Q6(List& l1,List& l2) {
	List temp;
	Initsize(temp);
	temp.length = l1.length + l2.length;
	int j = 0, k = 0;
	for (int i = 0; i < temp.length; i++) {
		if (l1.data[j] <= l2.data[k] && j < l1.length) {
			temp.data[i] = l1.data[j];
			//cout<<"NUMj: "<< j << " NOW: " << temp.data[i] << endl; 用于检验当前值,无实际意义
			j++;
		}
		else if (l2.data[k] < l1.data[j] && k < l2.length) {
			temp.data[i] = l2.data[k];
			//cout<<"NUMk: "<< k << " NOW: " << temp.data[i] << endl; 用于检验当前值,无实际意义
			k++;
		}	
		else if (j == l1.length) {
			temp.data[i] = l2.data[k];
			k++;
		}
		else if (k == l2.length) {
			temp.data[i] = l1.data[j];
			j++;
		}
	}
	return temp;
}

void Q2010(int a[],int p) {
	int temp;
	for (int i = 0; i < MAXSIZE/2; i++) {
		temp = a[i];
		a[i] = a[MAXSIZE - 1 - i];
		a[MAXSIZE - 1 - i] = temp;
	}
	//cout << endl;
	//cout << "第一次逆置数组为: ";
	//for (int i = 0; i < MAXSIZE; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	for (int j = 0; j < (MAXSIZE - p)/2; j++) {
		temp = a[j];
		a[j] = a[MAXSIZE - p - 1 - j];
		a[MAXSIZE - p - 1 - j] = temp;
	}
	//cout << "第二次逆置数组为: ";
	//for (int i = 0; i < MAXSIZE; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	for (int k =0; k < p/2; k++) {
		temp = a[k+ MAXSIZE-p];
		a[k + MAXSIZE - p] = a[MAXSIZE - 1 - k];
		a[MAXSIZE - 1 - k] = temp;
	}

	return;
}

int Q2011(int a[],int b[],int L) {
	int temp, p = 0, q = 0;
	for (int i = 0; i < L + 1 ; i++) {
		if (a[p] <= b[q]&&p != L) {
			temp = a[p];
			cout << "1" << endl;
			p++;
		}
		else if (a[p] > b[q] && q != L) {
			temp = b[q];
			cout << "2" << endl;
			q++;
		}
		else if (p == L) {
			temp = b[q];
			cout << "3" << endl;
			q++;
		}
		else if (q == L) {
			temp = a[p];
			cout << "4" << endl;
			p++;
		}
	}
	
	return temp;
}

int Q2013(int a[]) {
	int temp,time1 = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		temp = a[i];
		for (int j = i; j < MAXSIZE; j++) {
			if (a[j] == temp) {
				time1++;
			}
		}
		if (time1 > (MAXSIZE / 2)) {
			return temp;
		}
		time1 = 0;
	}
	return -1;
}

int Q2018(int a[]) { //maxsize即为n
	int min = 0,max = 0,s=0;
	int b[MAXSIZE];
	for (int o = 0; o < MAXSIZE; o++) {
		b[o] = 0;
	}
	for (int i = 0; i < MAXSIZE; i++) {
		if (a[i] > 0 && a[i] <= MAXSIZE) {
			b[a[i]-1] = 1;
		}
	}
	for (int a = 0; a < MAXSIZE; a++) {
		cout << b[a] << ",";
	}
	for (int e = 0; e < MAXSIZE; e++) {
		if (b[e] == 0) {
			return e+1;
		}
	}
		return MAXSIZE + 1;
}




int main() {
	List l;
	Initsize(l);


	//createrlist(l);
	//printlist(l);
	
	
	
	
	//Q1
	//cout << "被删元素是"<< Q1(l) << endl;

	//Q2
	//Q2(l);

	//Q3
	//Q3(l);

	//Q4
	//Q4(l);

	//Q5
	//Q5(l);

	//Q6
	//l.data[0] = 1;
	//l.data[1] = 3;
	//l.data[2] = 4;
	//l.data[3] = 7;
	//l.data[4] = 14;
	//l.length = 5;
	//List p;
	//Initsize(p);
	//p.data[0] = 1;
	//p.data[1] = 4;
	//p.data[2] = 14;
	//p.data[3] = 15;
	//p.data[4] = 19;
	//p.length = 5;
	//printlist(Q6(l,p));

	//Q2010
	//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//Q2010(a, 4);
	//cout << "转变后数组为: ";
	//for (int i = 0; i < MAXSIZE; i++) {
	//	cout << a[i] << " ";
	//}
	
	//Q2011
	/*int L = 5;
	int a[5] = { 1,2,3,4,11 };
	int b[5]= { 6,7,8,9,10 };
	cout<<"中位数是: "<< Q2011(a, b, L)<<endl;*/


	//Q2013
	//int a[10] = { 3,1,1,2,1,1,2,1,4,6 };
	//cout<<"主元素是: "<<Q2013(a)<<endl;

	//Q2018
	int a[10] = { 1,2,3,4,5,6,7,8,9,11 };
	cout << "最小正整数: " << Q2018(a) << endl;


	return 0;
}