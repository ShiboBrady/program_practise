#include <stdio.h>
#include <string.h>

void Reverse(char* pBegin, char* pEnd) {
	if (NULL == pBegin || NULL == pEnd || *pBegin == 0 || *pEnd == 0 || pBegin >= pEnd) {
		return;
	}
	while (pBegin < pEnd) {
		char cTemp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = cTemp;
		++pBegin, --pEnd;
	}
}

void ReverseSentence (char* str) {
    if (NULL == str || *str == 0) {
        return;
    }
    char* pBegin = str;
    char* pEnd = str;

    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            ++pBegin, ++pEnd;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, pEnd - 1);
            pBegin = pEnd;
        } else {
            ++pEnd;
        }
    }
}

int main() {
    char str[] = "This is a macbool.";
    ReverseSentence(str);
    printf("%s\n", str);
    return 0;
}
