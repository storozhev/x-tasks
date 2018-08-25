#include <string.h>
#include <assert.h>

/**
 * Reverses a null-terminated string
 */
void reverse(char *);

int main() {
	char s0[] = ""; // empty string 
	char s1[] = "."; // 1 character
	char s2[] = "abc"; // 3 characters
	char s3[] = "hello world!"; // 12 characters
	
	reverse(s0);
	reverse(s1);
	reverse(s2);
	reverse(s3);
	
	assert(strcmp("", s0) == 0);
	assert(strcmp(".", s1) == 0);
	assert(strcmp("cba", s2) == 0);
	assert(strcmp("!dlrow olleh", s3) == 0);

	return 0;
}

void reverse(char *str) {
	size_t len = strlen(str);
	if (len <= 1) {
		return;
	}
	int i = 0;
	while (i <= (len-1)/2) {
		char c_begin = *(str + i);
		char c_end = *(str + len - 1 - i);
		*(str + i) = c_end;
		*(str + len - 1 - i) = c_begin;
		i++;
	}
}


