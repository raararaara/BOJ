#include <iostream>
#include <cmath>
using namespace std;
typedef long long lint;

int main() {
	int local, birth, order;
	int checksum = 0;
	char c;
	int n, i;
	scanf("%6d", &local);
	scanf("%8d", &birth);
	scanf("%3d", &order);
	scanf("%1c", &c);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == local) break;
	}
	if (i == n || order == 0) {
		printf("I\n");
		return 0;
	}

	int year = birth / 10000;
	if (year < 1900 || year > 2011) {
		printf("I\n");
		return 0;
	}
	int month = (birth % 10000) / 100, date = (birth % 10000) % 100;
	bool flag = false, leap;
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0) leap = false;
		else leap = true;
	}

	//평년
	if (month >= 1 && month <= 12) {
		if (month <= 7) {
			if (month % 2 == 1) {
				if (date >= 1 && date <= 31)
					flag = true;
			}
			else {
				if (month == 2) {
					if (!leap && date >= 1 && date <= 28)
						flag = true;
					else if (leap && date >= 1 && date <= 29)
						flag = true;
				}
				else {
					if (date >= 1 && date <= 30)
						flag = true;
				}
			}
		}
		else {
			if (month % 2 == 0) {
				if (date >= 1 && date <= 31)
					flag = true;
			}
			else {
				if (date >= 1 && date <= 30)
					flag = true;
			}
		}
	}
	if (!flag) {
		printf("I\n");
		return 0;
	}
	flag = false;
	int localarr[6], birtharr[8], orderarr[3];
	int tmplocal = local, tmpbirth = birth, tmporder = order;
	for (i = 0; i < 6; i++) {
		localarr[5-i] = tmplocal % 10;
		checksum += localarr[5-i] * (int)pow(2, 12 + i);
		tmplocal /= 10;
	}
	for (i = 0; i < 8; i++) {
		birtharr[7 - i] = tmpbirth % 10;
		checksum += birtharr[7 - i] * (int)pow(2, 4 + i);
		tmpbirth /= 10;
	}
	checksum = checksum + (tmporder / 100) * 8 + ((tmporder % 100) / 10) * 4 + (tmporder % 10) * 2;

	for (i = 0; i < 11; i++) {
		if ((i + checksum) % 11 == 1) break;
	}
	if (i == 10 && c == 'X')
		flag = true;
	else if (i == c - '0')
		flag = true;

	if (!flag) {
		printf("I\n");
		return 0;
	}
	if (order % 2) printf("M\n");
	else printf("F\n");

	return 0;
}
