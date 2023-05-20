#include "CRUD.h"
#include <string.h>



void printMenu() {
    printf("�޴�:\n");
     for (int i = 0; i < 4; i++) 
    printf("%d. %s - %d��\n", i + 1, menu[i].foodName, menu[i].foodPrice);
}


// ���� �߰�
void addSeat(int mm, int dd, int tableNumber, char guestName[], int guestPhone, int reservationDuration, int menuChoice, int menuCount, int time) {
    // ��¥ �ε��� ���
    int m = mm-1;
    int d =dd-1;

    // ��¥ Ȯ��
    
        // ��¥�� ���� á���� Ȯ��
        if (dates[m][d].isFull == 1) {
            printf("�ش� ��¥�� ������ ��� á���ϴ�.\n");
            return;
        }

            // ���̺� ��ȣ Ȯ��
            if (tableNumber >= 0 && tableNumber < 16) {
                // ���̺��� ���� á���� Ȯ��
                if (dates[m][d].tables[tableNumber].isFull == 1) {
                    printf("�ش� ���̺��� �̹� ������ ���� á���ϴ�.\n");
                    return;
                }

                //������ �ð��� ���� ������ �� Ȯ��
            for(int i=time-1; i<reservationDuration+time-1; i++){
                if (dates[m][d].tables[tableNumber].customer[i].full !=0) {
                    printf("�ش� �ð����� ������ �̹� �ֽ��ϴ�.\n");
                    return;
                }
            }

            //�������� �Է� ���� - ������ �̸��� ������
            for (int i =time-1; i < reservationDuration+time-1; i++) {
                strcpy(dates[m][d].tables[tableNumber].customer[i].name, guestName);
                dates[m][d].tables[tableNumber].customer[i].phoneNum = guestPhone;
                dates[m][d].tables[tableNumber].customer[i].full = 1;
                strcpy(dates[m][d].tables[tableNumber].customer[i].Menu, menu[menuChoice-1].foodName);
                dates[m][d].tables[tableNumber].customer[i].price = menu[menuChoice-1].foodPrice * menuCount;
                dates[m][d].tables[tableNumber].customer[i].people = menuCount;
            }
            

            //
            int count=0;
            for(int i=0; i<12; i++){
                if( dates[m][d].tables[tableNumber].customer[i].full == 1)
                count++;
            }
            if(count == 12) {
                dates[m][d].tables[tableNumber].isFull = 1;
            }
                    printf("������ �߰��Ǿ����ϴ�.\n");
                    return;
                    
            }else{
                 printf("���̺� ��ȣ�� �߸� �Է��ϼ̽��ϴ�. \n");
                 return;
            }
           
        
    
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteSeat(int mm,int dd, int tableNumber, char guestName[], int Phone) {
// ��¥ �ε��� ���
    int m = mm-1;
    int d =dd-1;
    int count =0;


        for (int i = 0; i < 12; i++) {
              
            if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
                dates[m][d].tables[tableNumber].customer[i].name[0] = '\0';
                dates[m][d].tables[tableNumber].customer[i].phoneNum = 0;
                dates[m][d].tables[tableNumber].customer[i].price = 0;
                dates[m][d].tables[tableNumber].customer[i].full = 0;
                dates[m][d].tables[tableNumber].isFull = 0;

                dates[m][d].isFull = 0;
                count++;

                
            }

        }
        if(count >0) {
            printf("������ �����Ǿ����ϴ�.\n");
            return;
        }
        printf("�ش� �մ��� ������ ã�� �� �����ϴ�.\n");
    

}

void updateSeat(int mm,int dd, int tableNumber, char guestName[]) {
    // ��¥ �ε��� ���
    int m = mm-1;
    int d =dd-1;
    char names[100];
    int newPhone;
    int menuChoice;
    int menuCount;
    int customerIndex = -1; // ���� �մ��� �ε���

// ���� �մ��� �ε��� ã��
         for (int i = 0; i < 12; i++) {
        if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex != -1) {
        printf("���ο� �մ� �̸��� �Է��ϼ���: ");
        scanf("%s", names);

        printf("���ο� �մ� ��ȭ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &newPhone);

        printMenu();
        printf("���ο� �޴��� �����ϼ��� (1-3): ");
        scanf("%d", &menuChoice);

        printf("���ο� ������ �����ϼ��� (1-3): ");
        scanf("%d", &menuCount);

         // ���� �մ��� ���� ����
        for (int i = 0; i < 12; i++) {
        if (dates[m][d].tables[tableNumber].customer[i].full == 1 && strcmp(dates[m][d].tables[tableNumber].customer[i].name, guestName) == 0) {
             strcpy(dates[m][d].tables[tableNumber].customer[i].name, names);
        dates[m][d].tables[tableNumber].customer[i].phoneNum = newPhone;
        strcpy(dates[m][d].tables[tableNumber].customer[i].Menu, menu[menuChoice - 1].foodName);
        dates[m][d].tables[tableNumber].customer[i].price = menu[menuChoice - 1].foodPrice * menuCount;
        dates[m][d].tables[tableNumber].customer[i].people = menuCount;
        }
    }

        // ���� �մ��� ���� ����
       
        

        printf("\n������ �����Ǿ����ϴ�.\n");
    } else {
        printf("�ش� �մ��� ������ ã�� �� �����ϴ�.\n");
    }
    
}


void listSeat(int mm, int dd) {
    // ��¥ �ε��� ���
    int m = mm - 1;
    int d = dd - 1;

    // ��¥ Ȯ��
    if (m >= 0 && m < 12 && d >= 0 && d < 31) {
        // ��¥�� ���� á���� Ȯ��

        printf("��¥: %d�� %d��\n", mm, dd);
        printf("�մ� ���:\n");

        for (int i = 0; i < 16; i++) {
            // ���̺��� ���� á���� Ȯ��

            for (int j = 0; j < 12; j++) {
                // ������ �ִ� ��쿡�� ���
                if (dates[m][d].tables[i].customer[j].full == 1 && strcmp(dates[m][d].tables[i].customer[j].name, dates[m][d].tables[i].customer[j-1].name) != 0 && dates[m][d].tables[i].customer[j].phoneNum != dates[m][d].tables[i].customer[j-1].phoneNum) {

                    printf("���̺� ��ȣ: %d, �մ� �̸�: %s, �մ� ��ȭ��ȣ: %d, �޴�: %s, ����: %d��\n",
                           i, dates[m][d].tables[i].customer[j].name,
                           dates[m][d].tables[i].customer[j].phoneNum,
                           dates[m][d].tables[i].customer[j].Menu,
                           dates[m][d].tables[i].customer[j].price);
                }
            }
           
        }
    } else {
        printf("��ȿ���� ���� ��¥�Դϴ�.\n");
    }
}





void search(int mm, int dd, char guestName[]) {
    // ��¥ �ε��� ���
    int m = mm-1;
    int d =dd-1;
    int found = 0; // �� ���� ã�Ҵ��� ���θ� ��Ÿ���� ����

    
        printf("��¥: %d�� %d��\n", mm,dd);
        printf("�˻� ���:\n");

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 12; j++) {
                if (dates[m][d].tables[i].customer[j].full == 1 && strcmp(dates[m][d].tables[i].customer[j].name, guestName) == 0) {
                     printf("���̺� ��ȣ: %d, �մ� �̸�: %s, �մ� ��ȭ��ȣ: %d,  ���ҿ���: %d, ������ ����: %d��\n",
                       i, dates[m][d].tables[i].customer[j].name, dates[m][d].tables[i].customer[j].phoneNum,
                       dates[m][d].tables[i].customer[j].isPaid,
                       dates[m][d].tables[i].customer[j].price);
                       found = 1; // �� ������ ã������ ǥ��
                       break;
                }
            }
        }
    if (!found) {
        printf("�ش� �մ��� ������ ã�� �� �����ϴ�.\n");
    }
}

