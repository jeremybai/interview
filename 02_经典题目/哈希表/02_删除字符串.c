/**
 * @brief   两个字符串A、B。从A中剔除存在于B中的字符。
 * @note   比如A=“hello world”,B="er"，那么剔除之后A变为"hllowold"。空间复杂度要求是O(1)，时间复杂度越优越好。
 * @method 由B字符串构造Hash表，对A剔除时直接查找Hash表。
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Num 52
#define LEN 100

int HashChar[Num];

int Hash(char c) {
		if(!isalpha(c)) return -1;
		if(islower(c)) return c - 'a';
		return c - 'A' + 26;
}
void InitialHash(char *B) {
		int i;
		int pos;
		for(i = 0;B[i];i++) {
				pos = Hash(B[i]);
				if(pos == -1) {
						perror("B contains illegal characters\n");
				}
				else HashChar[pos] = 1;
		}
}
void DelSameStr(char *A, char *B) {
		int i, j;
		int pos;
		i = 0;
		while(A[i]) {
				pos = Hash(A[i]);
				if(HashChar[pos]) {
						for(j = i;A[j];j++) {
								A[j] = A[j + 1];
						}
				}
				else i++;
		}
}
int main() {
		char A[LEN], B[LEN];
		printf("A = ");
		gets(A);
		printf("B = ");
		gets(B);
		InitialHash(B);
		DelSameStr(A, B);
		printf("after coping...");
		puts(A);

		return 0;
}
