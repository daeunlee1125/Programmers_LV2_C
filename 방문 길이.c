#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
문제 설명
게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

U: 위쪽으로 한 칸 가기

D: 아래쪽으로 한 칸 가기

R: 오른쪽으로 한 칸 가기

L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.
명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.

제한사항
dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
dirs의 길이는 500 이하의 자연수입니다.
*/

// 26.01.22 16:11
typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
}Edge;

int solution(const char* dirs) {
    int answer = 0;
    Edge visited[300];
    int now[2] = {0, 0};
    int vcnt = 0;
    
    for (int i = 0; i < strlen(dirs); i++) {
        int newX = now[0];
        int newY = now[1];
        int plusf = 0;
        switch (dirs[i]) {
            case 'U': newY++; plusf++; break;
            case 'D': newY--; break;
            case 'R': newX++; plusf++; break;
            case 'L': newX--; break;
        }
        if (newX>5 || newX<-5 || newY>5 || newY<-5) continue;
        
        int flag = 0;
        int sx, sy, bx, by;
        if (plusf == 1) {
            sx = now[0]; sy = now[1]; bx = newX; by = newY;
        } else {
            sx = newX; sy = newY; bx = now[0]; by = now[1];
        }
        
        for (int i = 0; i < vcnt; i++) {
            if (visited[i].x1==sx && visited[i].y1==sy && visited[i].x2==bx && visited[i].y2==by) {
                flag = 1;
                break;
            }
        }
        
        if (flag==0) {
            answer++;
            visited[vcnt].x1 = sx;
            visited[vcnt].y1 = sy;
            visited[vcnt].x2 = bx;
            visited[vcnt++].y2 = by;
        }
        now[0] = newX;
        now[1] = newY;
    }
    
    return answer;
}