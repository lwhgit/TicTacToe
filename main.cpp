#include <stdio.h>

int main() {
    int map[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int turn = 1;                                                                       // 현재 턴인 사람, 1일때 O, 2일때 X 로 둠

    while (true) {
        int x = 0;                                                                      // 입력 받을 좌표
        int y = 0;

        printf("Turn: player %d\n", turn);
        scanf_s("%d %d", &x, &y);                                                       // 입력 받기

        if ((x >= 0) && (x < 3) && (y >= 0) && (y < 3)) {                               // 입력 받은 좌표가 범위안에 있는가 (3 * 3 크기안에 있는가)
            if (map[x][y] == 0) {                                                       // 입력 받은 좌표가 비어있는가 (아무도 선택한적 없는가)

                map[x][y] = turn;                                                       // 입력 받은 좌표에 현재 턴의 것임을 표시 (O 또는 X 표시 했다고 봄)

                int xCount = 0;                                                         // 가로, 세로, 대각선이 다 채워졌는가를 확일 할 변수들
                int yCount = 0;
                int dig1Count = 0;
                int dig2Count = 0;

                for (int i = 0; i < 3; i++) {                                           // 체크하는 부분
                    if (map[i][y] == turn) {
                        xCount++;
                    }
                    if (map[x][i] == turn) {
                        yCount++;
                    }
                    if (map[i][i] == turn) {
                        dig1Count++;
                    }
                    if (map[i][2 - i] == turn) {
                        dig2Count++;
                    }
                }

                if (xCount == 3 || yCount == 3 || dig1Count == 3 || dig2Count == 3) {   // 하나라도 3개 이상 이어진 구간이 있으면 끝
                    printf("player %d win!\n", turn);
                    break;
                }

                if (turn == 1) {                                                        // 턴 교체
                    turn = 2;
                } else if (turn == 2) {
                    turn = 1;
                }
            } else {
                printf("Cannot put there.\n");
                continue;
            }
        } else {
            printf("Wrong coord!\n");
            continue;
        }
    }
}
