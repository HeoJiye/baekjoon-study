#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int N, M;
    char answerA, answerB;
    int minCountA = 32, minCountB = 32;
    int countA = 0, countB = 0;

    //�� �޾ƿ���

    scanf("%d %d", &N, &M);

    while (getchar() != '\n');

    char** arr;
    arr = (char)malloc(sizeof(char) * N);
    for (int i = 0; i < N; i++)
        arr[i] = (char)malloc(sizeof(char) * M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%c", &arr[i][j]);
            if (arr[i][j] == '\n')
                scanf("%c", &arr[i][j]);
        }

    //while (getchar() != '\n');

    answerA = 'B';
    answerB = 'W';
    // 8x8 ũ�⸸ŭ �����̱�
    for (int i = 0; i <= N - 8; i++)
        for (int j = 0; j <= M - 8; j++) {
            for (int a = i; a < i + 8; a++) {
                for (int b = j; b < j + 8; b++) {
                    if (answerA != arr[a][b])
                        countA++;

                    if (answerB != arr[a][b])
                        countB++;

                    answerA = answerA == 'B' ? 'W' : 'B';
                    answerB = answerB == 'B' ? 'W' : 'B';
                }
                answerA = answerA == 'B' ? 'W' : 'B';
                answerB = answerB == 'B' ? 'W' : 'B';
            }

            if (countA < minCountA) // ���� count�� ���� count���� �۴ٸ�
                minCountA = countA;
            if (countB < minCountB) // ���� count�� ���� count���� �۴ٸ�
                minCountB = countB;

            countA = countB = 0;
        }

    printf("%d", minCountA > minCountB ? minCountB : minCountA);

    return 0;
}