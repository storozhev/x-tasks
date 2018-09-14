#include <stdio.h>
#include <string.h>

char* pack_str(char*);

int main() {
	char *original = "aaaccbjj";
	char *packed = pack_str(original);
	printf("original: %s\n", original);
	printf("packed: %s\n", packed);
}

char* pack_str(char *str) {
	if (strlen(str) == 0) {
		return str;
	}
	
	char packed[50] = ""; // todo

	unsigned short n = 1, i;
	char cur_char, prev_char;

	for(i = 1; i <= strlen(str); i++) {
		cur_char = *(str + i);
		prev_char = *(str + i - 1);
		
		if (cur_char == prev_char) {
			n++;
			continue;
		}

		n = 1;

		packed[strlen(packed)] = prev_char;
	}

	if (strlen(packed) < strlen(str)) {
		str = packed;
	}

	return str;	
}

