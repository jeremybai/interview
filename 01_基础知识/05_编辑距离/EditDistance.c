#include<iostream>
 
using std::cout;
using std::endl;
 
int min(int a, int b, int c)
{
    int small = a;
    if(b < small)
        small = b;
    if(c < small)
        small = c;
    return small;
}
 
int main()
{
    char s[] = "David_and_Sophia";          // the last character is '\0'
    char d[] = "Dadiudiu_and_Xiaodiugirl";      // the last character is '\0'
 
    int len_s = strlen(s);              // 16
    int len_d = strlen(d);              // 24
    int dist[len_s + 1][len_d + 1];
 
    cout << len_s << endl;
    cout << len_d << endl;
 
    for(int i = 0; i <= len_s; i++)
        dist[i][0] = i;
    for(int i = 0; i <= len_d; i++)
        dist[0][i] = i;
 
    for(int i = 1; i <= len_s; i++)
        for(int j = 1; j <= len_d; j++)
            dist[i][j] = min((dist[i - 1][j] + 1), dist[i][j - 1] + 1, dist[i - 1][j - 1] + (s[i - 1] == d[j - 1] ? 0 : 1));
 
    cout << dist[len_s][len_d] << endl;
 
    return 0;
}