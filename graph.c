#include "setting.h"
#include "CRUD.h"

void showGraph(int mm) {
    printf("%d�� ���� ���� (����: ����)\n", mm);

    // ���� ���� �׷��� ���
    int weekly_profit[5] = {0, 0, 0, 0, 0};  // �ֺ� ���� �迭 �ʱ�ȭ

    for (int j = 0; j < 31; j++) {
        // �ش� ���� ���� ���
        int week = j / 7;

        // ���� �մ��� �������� ������ ��� �ǳʶٱ�
        for (int n = 0; n < 16; n++) {
            for (int m = 0; m < 12; m++) {
                if (strcmp(dates[mm - 1][j].tables[n].customer[m].name, dates[mm - 1][j].tables[n].customer[m + 1].name) == 0) {
                    m++;  // ���� �մ����� �ǳʶٱ�
                } else {
                    weekly_profit[week] += dates[mm - 1][j].tables[n].customer[m].price;
                }
            }
        }
    }

    // �׷��� ���
    for (int i = 0; i < 5; i++) {
        printf("���� %d |", i + 1);
        for (int j = 0; j < weekly_profit[i]; j += 10000) {  // ���� ����
            printf("��");
        }
        printf("|");
        printf(" %d\n", weekly_profit[i]);
    }
}
