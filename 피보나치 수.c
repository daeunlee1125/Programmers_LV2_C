#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
문제 설명
피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2) 가 적용되는 수 입니다.

예를들어

F(2) = F(0) + F(1) = 0 + 1 = 1
F(3) = F(1) + F(2) = 1 + 1 = 2
F(4) = F(2) + F(3) = 1 + 2 = 3
F(5) = F(3) + F(4) = 2 + 3 = 5
와 같이 이어집니다.

2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.

제한 사항
n은 2 이상 100,000 이하인 자연수입니다.
*/

// 2026.01.17 15:20
long fibo(int n, long* f) {
    if (f[n] != -1) return f[n];
    f[n] = (fibo(n-1, f) + fibo(n-2, f))%1234567;
    return f[n];
}

int solution(int n) {
    long* f = malloc((n+1) * sizeof(long));
    f[0] = 0; f[1] = 1;
    for (long i = 2; i < n+1; i++) f[i] = -1;
    return fibo(n, f);
}