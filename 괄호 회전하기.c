#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
문제 설명
다음 규칙을 지키는 문자열을 올바른 괄호 문자열이라고 정의합니다.

(), [], {} 는 모두 올바른 괄호 문자열입니다.
만약 A가 올바른 괄호 문자열이라면, (A), [A], {A} 도 올바른 괄호 문자열입니다. 예를 들어, [] 가 올바른 괄호 문자열이므로, ([]) 도 올바른 괄호 문자열입니다.
만약 A, B가 올바른 괄호 문자열이라면, AB 도 올바른 괄호 문자열입니다. 예를 들어, {} 와 ([]) 가 올바른 괄호 문자열이므로, {}([]) 도 올바른 괄호 문자열입니다.
대괄호, 중괄호, 그리고 소괄호로 이루어진 문자열 s가 매개변수로 주어집니다. 이 s를 왼쪽으로 x (0 ≤ x < (s의 길이)) 칸만큼 회전시켰을 때 s가 올바른 괄호 문자열이 되게 하는 x의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
s의 길이는 1 이상 1,000 이하입니다.
*/

// 2026.01.17 19:13 (20분)
bool right(char* cpy) {
    if (cpy[0] == ']' || cpy[0] == '}' || cpy[0] == ')') return false;
    char* stack = malloc(sizeof(char) * (strlen(cpy)+1));
    int st = -1; int clen = strlen(cpy);
    
    for (int i = 0; i < clen; i++) {
        stack[++st] = cpy[i];
        if (st>=1 && ((stack[st] == ']' && stack[st-1] == '[') || (stack[st] == '}' && stack[st-1] == '{') || (stack[st] == ')' && stack[st-1] == '('))) {
            st -= 2;
        }
    }
    if (st == -1) return true;
    else return false;
}

int solution(const char* s) {
    int answer = 0;
    char* cpy = malloc(sizeof(char) * (strlen(s)+1));
    strcpy(cpy, s);
    
    if (right(s)) answer++;
    for (int i = 1; i < strlen(s); i++) {
        // 회전
        char tmp = cpy[0];
        for (int j = 0; j < strlen(s)-1; j++) {
            cpy[j] = cpy[j+1];
        }
        cpy[strlen(s)-1] = tmp;
        
        // 비교
        if (right(cpy)) answer++;
    }
    
    return answer;
}