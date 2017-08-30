#include <stdio.h>

// my solution - straightforward but takes a really long time for long numbers
int rangeBitwiseAnd(int m, int n) {
    if(m == 0 || n == 0) return 0;
    int res = m;
    for(int i = m; i <= n; i++) {
        res &= i;
    }
    return res;
}

// REAL SOLUTION - after researching google
int rangeBitwiseAnd(int m, int n) {
	while (m < n) {
		n &= n-1;
	}
	return n;
}

int main() {
	printf("%d\n", rangeBitwiseAnd(5, 7));
}