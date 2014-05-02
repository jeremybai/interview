#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//Matrix[I][J]代表I个零以及J个一能够组成的不同排列的个数
//递推关系：matrix[N][M] = matrix[N-1][M] + matrix[N][M-1];
int matrix[30][30];


//将递归计算的到的matrix的值存入matrix矩阵，以减少运算。
int SetNumMatrix(int N, int M)
{
	if(N == 0 || M == 0){
		matrix[N][M] = 1;
	}
	else if(matrix[N][M] == 0){
		int Val1 = matrix[N - 1][M] == 0 ? SetNumMatrix(N - 1, M) : matrix[N - 1][M];
		int Val2 = matrix[N][M - 1] == 0 ? SetNumMatrix(N, M - 1) : matrix[N][M - 1];
		matrix[N][M] = Val1 + Val2;
	}
	return matrix[N][M];
}


//递归打印符合要求的字符序列。
void printfRecursive(int N, int M, int K)
{
	if(N == 0)
		for(int i = 0; i < M; i++) putchar('1');
	else if(M == 0)
		for(int i = 0; i < N; i++) putchar('0');
	
	else if(K <= matrix[N-1][M]){
		putchar('0');
		printfRecursive(N-1, M, K);
	}
	else{
		putchar('1');
		printfRecursive(N, M-1, K - matrix[N-1][M]);
	}
}


//matrix[N][M] = matrix[N-1][M] + matrix[N][M-1];
void printK(int N, int M, int K)
{
	if(K > matrix[N][M])
		printf("Impossible");
	else
		printfRecursive(N,M,K);
	putchar('\n');
}


int main()
{
	int n;
	int N, M, K;

	//初始化Matrix数组用于查询。
	SetNumMatrix(15, 15);

	int maxNum, tmp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &N, &M, &K);
		printK(N, M, K);
	}
	return 0;
}
