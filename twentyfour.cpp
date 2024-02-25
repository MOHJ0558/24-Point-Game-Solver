#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//int fac(int num) {
//	int sum=1;
//	for(int i=1;i<=num;i++){
//		sum*=i;
//	}
//	return sum;
//}
double clc(int op,double p, double q) {
	double ans1,ans2,ans3,ans4;
	ans1=p+q;
	ans2=p-q;
	ans3=p/q;
	ans4=p*q;
	if(op == 1) {
		return ans1;
	}else if(op == 2) {
		return ans2;
	}else if(op == 3) {
		return ans3;
	}else if(op == 4) {
		return ans4;
	}else {
		return 0;
	}
}
char disOp(int op) {
	if(op == 1) {
		return '+';
	}else if(op == 2) {
		return '-';
	}else if(op == 3) {
		return '/';
	}else if(op == 4) {
		return '*';
	}else {
		return ' ';
	}
}
double ttf(double a, double b, double c, double d, char idur[]) {
	//((ajb)kc)ld
	for(int j=1;j<=4;j++) {
		double an1 = clc(j,a,b);
		for(int k=1;k<=4;k++) {
			double an2=clc(k,an1,c);
			for(int l=1;l<=4;l++){
				double an3 = clc(l,an2,d);
				if(an3>=23.99&&an3<=24.01) {
					cout << ":[(" << a << disOp(j) << b << ')' << disOp(k) << c << ']' << disOp(l) << d << '=' << an3 << endl;
				}else if(strcmp(idur,"y")==0){
					cout << "[(" << a << disOp(j) << b << ')' << disOp(k) << c << ']' << disOp(l) << d << '=' << an3 << endl;
				}
			}
		}
	}
	//(ak(bjc))ld
	for(int j=1;j<=4;j++) {
		double bn1 = clc(j,b,c);
		for(int k=1;k<=4;k++) {
			double bn2=clc(k,a,bn1);
			for(int l=1;l<=4;l++){
				double bn3 = clc(l,bn2,d);
				if(bn3>=23.99&&bn3<=24.01) {
					cout << ":[" << a << disOp(k) << '(' << b << disOp(j) << c << ")]" << disOp(l) << d << '=' << bn3 << endl;
				}else if(strcmp(idur,"y")==0){
					cout << "[" << a << disOp(k) << '(' << b << disOp(j) << c << ")]" << disOp(l) << d << '=' << bn3 << endl;
				}
			}
		}
	}
	//al((bjc)kd)
	for(int j=1;j<=4;j++) {
		double cn1 = clc(j,b,c);
		for(int k=1;k<=4;k++) {
			double cn2=clc(k,cn1,d);
			for(int l=1;l<=4;l++){
				double cn3 = clc(l,a,cn2);
				if(cn3>=23.99&&cn3<=24.01) {
					cout << ":" << a << disOp(l) << "[(" << b << disOp(j) << c << ')' << disOp(k) << d << "]=" << cn3 << endl;
				}else if(strcmp(idur,"y")==0){
					cout << a << disOp(l) << "[(" << b << disOp(j) << c << ')' << disOp(k) << d << "]=" << cn3 << endl;
				}
			}
		}
	}
	//al(bk(cjd))
	for(int j=1;j<=4;j++) {
		double dn1 = clc(j,c,d);
		for(int k=1;k<=4;k++) {
			double dn2=clc(k,b,dn1);
			for(int l=1;l<=4;l++){
				double dn3 = clc(l,a,dn2);
				if(dn3>=23.99&&dn3<=24.01) {
					cout << ":" << a << disOp(l) << '[' << b << disOp(k) << '(' << c << disOp(j) << d << ")]=" << dn3 << endl;
				}else if(strcmp(idur,"y")==0){
					cout << a << disOp(l) << '[' << b << disOp(k) << '(' << c << disOp(j) << d << ")]=" << dn3 << endl;
				}
			}
		}
	}
	return 0;
}
int main(int argc, char *argv[]) {
	bg:
	double a[4];
	//isDisplayUselessResult
	char iDUR[]="n";
	if(argc != 1){
		strcpy(iDUR,argv[1]);
	}
	cout << "\nPlease enter four numbers separated by spaces\n> ";
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a,a+4);
//	for(int i=0;i<fac(4);i++){
//		ttf(a[0], a[1], a[2], a[3], iDUR);
//		next_permutation(a,a+4);
//	}
	do{
		ttf(a[0], a[1], a[2], a[3], iDUR);
//		cout << a[0] << a[1] << a[2] << a[3] << '\n';
	}while(next_permutation(a,a+4));
	char rp;
	cout << "\nAgain?[y/n]> ";
	cin >> rp;
	if(rp != 'n') {
		goto bg;
	}
	return 0;
}
