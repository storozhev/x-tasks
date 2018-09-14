#include <string.h>
#include <assert.h>

/** 
 * Determines if all symbols in the received string are unique
 * Strings contain only ASCII characters
 */ 
int isAllSymbolsUnique(const char *); 

int main() {
	assert(isAllSymbolsUnique(""));
	assert(isAllSymbolsUnique("string"));
	assert(!isAllSymbolsUnique("string s"));
	assert(!isAllSymbolsUnique("hello world!"));
	return 0;
}

int isAllSymbolsUnique(const char *str) {
	if (strlen(str) > 256) {
		return 0;
	}
	while(*str) {
		if(strchr(str, *str) != strrchr(str, *str)) {
			return 0;
		}
		str++;
	}
	return 1;
} 


