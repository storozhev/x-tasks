#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * Replaces all spaces in the passed string to the specified sequence of characters
 */
void replaceSpace(char*, const char*);

int main() {
	char s1[20] = "hello oh world!";
	char s2[28] = " space in the start";
	char s3[26] = "space in the end ";
	char s4[8] = "nospace";
	char s5[4] = " ";

	replaceSpace(s1, "%20");
	replaceSpace(s2, "%20");
	replaceSpace(s3, "%20");
	replaceSpace(s4, "%20");
	replaceSpace(s5, "%20");

	assert( strcmp("hello%20oh%20world!", s1) == 0 );
	assert( strcmp("%20space%20in%20the%20start", s2) == 0 );
	assert( strcmp("space%20in%20the%20end%20", s3) == 0 );
	assert( strcmp("nospace", s4) == 0 );
	assert( strcmp("%20", s5) == 0 );

	return 0;
}

void replaceSpace(char *str, const char *replace) {
	char *srch = " ",
		 *ptr = str;

	int shift = 0,
		shift_chnk = strlen(replace) - strlen(srch);

	while ((ptr = strstr(ptr, srch)) != NULL) {
		ptr++;
		shift += shift_chnk;
	}

	ptr = str + strlen(str);

	while (*(--ptr) != 0 && shift != 0) {
		if (ptr == strstr(ptr, srch)) {
			shift -= shift_chnk;
			for (int i = 0; i < strlen(replace); i++) {
				*(str + (ptr-str+shift+i)) = *(replace+i);
			}
			continue;
		}

		*(str + (ptr-str+shift)) = *ptr;
	}
}
