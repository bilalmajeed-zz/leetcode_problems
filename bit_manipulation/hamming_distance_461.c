#include <stdio.h>

int hammingDistance(int x, int y){
    int ans = x ^ y;
	int count = 0;
    while (ans) {
        count++;
        ans &= ans - 1;
    }
    return count;
}

int main() {
	int res = hammingDistance(1577962638, 1727613287);
	printf("%d\n", res);
	return 0;
}