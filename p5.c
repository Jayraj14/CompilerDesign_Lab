#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pm();
void plus();
void division();

int i, ch, j, l, addr = 100;
char ex[10], exp_1[10], exp_2[10], exp_3[10], id1[5], op[5], id2[5];

int main()
{
    while (1)
    {
        printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter the choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the expression with an assignment operator:");
            scanf("%s", exp_1);
            l = strlen(exp_1);
            exp_3[0] = '\0';
            i = 0;
            while (exp_1[i] != '=')
            {
                i++;
            }
            strncat(exp_3, exp_1, i);
            strrev(exp_1);
            exp_2[0] = '\0';
            strncat(exp_2, exp_1, l - (i + 1));
            strrev(exp_2);
            printf("Three address code:\ntemp=%s\n%s=temp\n", exp_2, exp_3);
            break;

        case 2:
            printf("\nEnter the expression with an arithmetic operator:");
            scanf("%s", ex);
            strcpy(exp_1, ex);
            l = strlen(exp_1);
            exp_2[0] = '\0';
            for (i = 0; i < l; i++)
            {
                if (exp_1[i] == '+' || exp_1[i] == '-')
                {
                    if (exp_1[i + 2] == '/' || exp_1[i + 2] == '*')
                    {
                        pm();
                        break;
                    }
                    else
                    {
                        plus();
                        break;
                    }
                }
                else if (exp_1[i] == '/' || exp_1[i] == '*')
                {
                    division();
                    break;
                }
            }
            break;

        case 3:
            printf("Enter the expression with a relational operator:");
            scanf("%s %s %s", id1, op, id2);
            if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 || strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
            {
                printf("%d\tif %s %s %s goto %d\n", addr, id1, op, id2, addr + 3);
                addr++;
                printf("%d\tT := 0\n", addr);
                addr++;
                printf("%d\tgoto %d\n", addr, addr + 2);
                addr++;
                printf("%d\tT := 1\n", addr);
            }
            else
            {
                printf("Expression is an error\n");
            }
            break;

        case 4:
            exit(0);
        }
    }

    return 0;
}

void pm()
{
    strrev(exp_1);
    j = l - i - 1;
    strncat(exp_2, exp_1, j);
    strrev(exp_2);
    printf("Three address code:\ntemp=%s\ntemp1=%c%c temp\n", exp_2, exp_1[j + 1], exp_1[j]);
}

void division()
{
    strncat(exp_2, exp_1, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c temp\n", exp_2, exp_1[i + 2], exp_1[i + 3]);
}

void plus()
{
    strncat(exp_2, exp_1, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c temp\n", exp_2, exp_1[i + 2], exp_1[i + 3]);
}
