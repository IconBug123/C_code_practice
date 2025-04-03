#define _CRT_SECURE_NO_WARNINGS 1

#include "head.h"


//1 静态版本 Max 100 
//2 动态版本 data里的数量可以改变
//3 文本版本

void menu() {
    printf("***************************************\n");
    printf("***** 1. add           2. del          ********\n");
    printf("***** 3. search      4. modify    ********\n");
    printf("***** 5. show        6. sort        ********\n");
    printf("***** 0. exit                             ********\n");
    printf("***************************************\n");
}


int main()
{
    int input = 0;
    Contact con;
    InitContact(&con);  //initialize this contact  用地址，从而可以修改，还可以提高效率由于是结构体变量
    do {
        menu();
        printf("Please choose:> ");
        scanf("%d", &input);
        switch (input) {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            SaveContact(&con);
            DestroyContact(&con);
            printf("Sign out.....\n");
            break;
        default:
            printf("Error Choosing.....\n");
            break;
        }
    } while (input);
    return 0;
}
