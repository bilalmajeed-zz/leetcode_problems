#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if(n < 0) return 0;
    int x = n;
    int count = 0;
    while(x) {
        x &= (x - 1);
        count++;
    }
    
    if(count == 1) return 1;
    return 0;
}

int main(){
	printf("%d\n", isPowerOfTwo(6));
}