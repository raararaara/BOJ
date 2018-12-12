#include <iostream>
#include <string.h>
using namespace std;
#define Max 1000
namespace FIO {
	const size_t BUFFER_SIZE = 524288;
	char buffer[BUFFER_SIZE];
	char* ptr = buffer + BUFFER_SIZE;

	inline char readByte() {
		if (ptr == buffer + BUFFER_SIZE) {
			fread(buffer, 1, BUFFER_SIZE, stdin);
			ptr = buffer;
		}
		return *(ptr++);
	}

	unsigned int readUnsigned() {
		unsigned int ret = 0;
		char c = readByte();
		while (!('0' <= c && c <= '9')) {
			c = readByte();
		}
		while ('0' <= c && c <= '9') {
			ret = ret * 10 + (c - '0');
			c = readByte();
		}
		return ret;
	}
};
int tot, T, N, cnt[Max][2];
void init() {
	memset(cnt, 0, sizeof(cnt));
	tot = 0;
}

int main() {
    T = FIO::readUnsigned();
	while(T--) {
		N = FIO::readUnsigned();
	    for (int i = 0; i < N; ++i) {
		    cnt[i][0] = cnt[i][1] = 0;
	    }
	    for (int i = 0; i < N; ++i) {
    		for (int j = i + 1; j < N; ++j) {
	    		int v = FIO::readUnsigned();
		    	cnt[i][v] += 1;
    			cnt[j][v] += 1;
	    	}
	    }
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += cnt[i][0] * cnt[i][1];
		tot = N * (N - 1)*(N - 2);
		tot /= 6; sum /= 2;

		printf("%d\n", tot- sum);
	}
	return 0;
}
