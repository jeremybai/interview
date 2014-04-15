
#include <stdio.h>
#define MAX   33
#define LIMIT 1000000000

/*
    f[i][j] represent how many kinds of sequence there are, with i zeros and j ones
    f[i][j] = f[i-1][j] + f[i][j-1], i > 0, j > 0
              1                    , i == 0 && j != 0 || i != 0 && j == 0
              0                    , i == 0 && j == 0
*/
long long f[MAX + 1][MAX + 1];
void init()
{
    int i, j;

    f[0][0] = 0;
    for(i = 1; i <= MAX; ++i) f[i][0] = f[0][i] = 1;
    for(i = 1; i <= MAX; ++i){
        for(j = 1; j <= MAX; ++j){
            if(i + j > MAX) break;//don't need to count this
            f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
}

int getKthZeroOneSequence(char s[], int countOfZeros, int countOfOnes, int K)
{
    //check if input matches conditions
    if(!(countOfZeros >= 0                 &&
         countOfOnes >= 0                  &&
         countOfZeros + countOfOnes >= 2   &&
         countOfZeros + countOfOnes <= MAX &&
         K >= 1                            &&
         K <= LIMIT                        &&
         K <= f[countOfZeros][countOfOnes]
         )
       ) return 0;

    //recursively determine the first element of the substring
    int i = 0;
    for(; countOfZeros > 0 && countOfOnes > 0; ++i){
        if(K <= f[countOfZeros - 1][countOfOnes]){
            s[i] = '0';
            --countOfZeros;
        }
        else{
            s[i] = '1';
            K -= f[countOfZeros - 1][countOfOnes];
            --countOfOnes;
        }
    }
    //fill up with zeros or ones left
    for(; countOfZeros > 0; --countOfZeros) s[i++] = '0';
    for(; countOfOnes > 0; --countOfOnes) s[i++] = '1';
    s[i] = '\0';

    return 1;
}

int main()
{
    int T;
    int N, M, K;
    char s[MAX + 1];

    init();
    for(scanf("%d", &T); T > 0; --T){
        //input
        scanf("%d%d%d", &N, &M, &K);
        //parse
        if(getKthZeroOneSequence(s, N, M, K)) puts(s);
        else puts("Impossible");
    }

    return 0;
}
