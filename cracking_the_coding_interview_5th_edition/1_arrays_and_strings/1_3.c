#include <assert.h>
#include <stdio.h>
#include <string.h>

/**
 * Determines if one string is a permutation of the other
 */
int isPermutation(char *, char *);

int numberOfOccurrences(char c, char *str) {
	int i = 0; char *ptr = str;
	while ((ptr = strchr(ptr, c)) != NULL) {
		ptr++;
		i++;
	}
	return i;
}

int main() {
	assert( isPermutation("", "") ); // empty strings
	assert( isPermutation("hello world", "hello world") ); // equal strings
	assert( isPermutation("abc", "cba") ); // reverse
	assert( isPermutation("world hello", "hello world") );
	assert( ! isPermutation("abc", "abcd") ); // different length
	assert( ! isPermutation("abc", "cbc") ); // different occurrences
	assert( ! isPermutation("world hellO", "hello world") ); // an apper-case symbol O
}

int isPermutation(char *mut, char *orig) {
	if (strlen(mut) != strlen(orig)) {
		return 0;
	}
	int i = 0;
	while (*(mut + i)) {
		char c = *(mut + i);
		if (numberOfOccurrences(c, mut) != numberOfOccurrences(c, orig)) {
			return 0;
		}
		i++;
	}
	
	return 1;
}


