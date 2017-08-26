#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* getRealNumber(char* num);
char* getImgNumber(char* num);

char* complexNumberMultiply(char* a, char* b) {
	int reOne = atoi(getRealNumber(a));
	int reTwo = atoi(getRealNumber(b));
	
	int imgOne = atoi(getImgNumber(a));
	int imgTwo = atoi(getImgNumber(b));

	//(a + bi)(c + di) = a*c + (a*d)i + (b*c)i - (b*d)
	int reTotal = (reOne*reTwo) - (imgOne*imgTwo);
	int imgTotal = (reOne*imgTwo) + (imgOne*reTwo);


	char* real_char = (char *)malloc(6);
	sprintf(real_char, "%d", reTotal);

	char* img_char = (char *)malloc(6);
	sprintf(img_char, "%d", imgTotal);

	char* res = (char *)malloc(13);
	res = real_char;
	strcat(res, "+");
	strcat(res, img_char);
	strcat(res, "i");

	return res;
}

char* getRealNumber(char* num){
	int sign_index;
	char * x = strrchr(num, '+');
	char * x_2 = strrchr(num, '-');
	if(x > x_2) {
		sign_index = (int)(x - num);
	}
	else {
		sign_index = (int)(x_2 - num);
		x = x_2;
	}
	
	char* res = (char *)malloc(sign_index * sizeof(char));
	memcpy(res, num, sign_index);
	
	return res;
}

char* getImgNumber(char* num){
	char sign;
	int sign_index;

	char * x = strrchr(num, '+');
	char * x_2 = strrchr(num, '-');
	if(x > x_2) {
		sign = '+';
		sign_index = (int)(x - num);

	}
	else {
		sign = '-';
		sign_index = (int)(x_2 - num);
		x = x_2;
	}

	x = x + 1;

	char* y = strchr(x, 'i');
	int i_i = (int)(y - x);
	char* res = (char *) malloc(i_i * sizeof(char));
	memcpy(res, x, i_i);
	
	char* res_sign = (char *)malloc(i_i * sizeof(char) + 1);
	res_sign[0] = sign;
	strcat(res_sign, res);
	return res_sign;
}

int main() {
	complexNumberMultiply("1+-1i", "1+-1i");
	return 0;
}