#include <stdio.h>
#include <stdlib.h>

int containsNine(int x) {
	int d;
	while (x != 0)
	{
		d = x % 10; 
		x = x / 10;   
		if (d == 9) return 1;
	}
	return 0;
}

int newInteger(int n) {
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(containsNine(i)) {
			count++;
			n++;
		}
	}
	return n;
}

int main() {
	printf("%d\n", newInteger(100));
	return 0;
}