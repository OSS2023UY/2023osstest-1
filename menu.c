#include "CRUD.h"

void ResetMenu(){     //�޴� �ʱ�ȭ �Լ�, ������ ������ �ϱ� ������ �ѹ��� ȣ����

    strcpy(menu[0].foodName, "ChickenSkewer");
    menu[0].foodPrice = 4000;
    menu[0].count = 0;

    strcpy(menu[1].foodName, "Ramen");
    menu[1].foodPrice = 8500;
    menu[1].count = 0;

    strcpy(menu[2].foodName, "Gimbob");
    menu[2].foodPrice = 3000;
    menu[2].count = 0;

    strcpy(menu[3].foodName, "Tteokbokki");
    menu[3].foodPrice = 7000;
    menu[3].count = 0;
}
// ChickenSkewer | Ramen | Gimbob | Tteokbokki