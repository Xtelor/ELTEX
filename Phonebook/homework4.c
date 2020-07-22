#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define n 10

struct phonebook
{
    char name[n];
    char surname[n];
    char number[n];
};

int main()
{
    setlocale (LC_ALL, "Rus");

    int option = 0;
    int i = 0, c;
    char phone[10];

    struct phonebook contacts[n];

    for(i = 0; i < n; i++)
    {
        contacts[i].name[i] = 0;
        contacts[i].surname[i] = 0;
        contacts[i].number[i] = 0;
    }

    printf("Добро пожаловать в абонентский справочник! \n");

    while(option != 5)
    {
        printf("\nВыберите опцию: \n");
        printf("Добавить контакт - введите 1 \n");
        printf("Поиск по номеру телефона - введите 2 \n");
        printf("Удалить контакт - введите 3 \n");
        printf("Посмотреть контакты - введите 4 \n");
        printf("Выйти из справочника - введите 5 \n");
        scanf("%d", &option);

        if(option != 1 && option != 2 && option != 3 && option !=4 && option !=5)
        {
            printf("\nВы выбрали неверную опцию, повторите попытку. \n");
        }

        if(option == 1)
        {
            i = 0;
            while(i < n)
            {
                printf("%d) \n", i+1);
                printf("Имя: ");
                scanf("%s", &contacts[i].name);
                printf("Фамилия: ");
                scanf("%s", &contacts[i].surname);
                printf("Номер: ");
                scanf("%s", &contacts[i].number);
                i++;
            }
        }

        if(option == 2)
        {
            i = 0;
            c = 0;
            printf("\nВведите номер: ");
            scanf("%s", &phone);

            for(i = 0; i < n; i++)
            {
                if(strcmp(phone,contacts[i].number) == 0)
                {
                    printf("\nИмя: ");
                    printf("%s \n", contacts[i].name);
                    printf("Фамилия: ");
                    printf("%s \n", contacts[i].surname);
                    printf("Номер: ");
                    printf("%s \n", contacts[i].number);
                    printf("\n");
                }
                else
                {
                    c++;
                }
            }
            if(c == n)
            {
                printf("\nНабранный номер не найден.\n");
            }
        }

        if(option == 3)
        {
            c = 0;
            i = 0;
            printf("\nВведите номер: ");
            scanf("%s", &phone);

            for(i = 0; i < n; i++)
            {
                if(strcmp(phone,contacts[i].number) == 0)
                {
                    memset(contacts[i].name,0,n);
                    memset(contacts[i].surname,0,n);
                    memset(contacts[i].number,0,n);
                }
                else
                {
                    c++;
                }
            }
            if(c == n)
            {
                printf("\nНабранный номер не найден.\n");
            }
        }

        if(option == 4)
        {
            c = 0;
            for(i = 0; i < n; i++)
            {
                if(contacts[i].name[i] == 0 && contacts[i].surname[i] == 0 && contacts[i].number[i] == 0)
                {
                    c++;
                }
            }

            if(c == n)
            {
                printf("\nВаш список контактов пустой. \n \n");
            }
            else
            {
                for(i = 0; i < n; i++)
                {
                    printf("\n%d)", i+1);
                    printf("Имя: ");
                    printf("%s \n", contacts[i].name);
                    printf("  Фамилия: ");
                    printf("%s \n", contacts[i].surname);
                    printf("  Номер: ");
                    printf("%s \n", contacts[i].number);
                }
            }
          }

        if(option == 5)
        {
            printf("\nВсего доброго.\n");
        }
    }
  return 0;
}
