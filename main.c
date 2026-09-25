#include <stdio.h>

void inverter_maiusculas(char *p);
void deslocar(char *p, int deslocamento);



int main()
{
    int n;
    char str_input[10001];
    scanf("%10000[^\n]%*c", str_input);

    while (1)
    {
        scanf("%d", &n);
        if (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6)
            break;
        if (n == 4)
        {
            inverter_maiusculas(str_input);
        }
        if (n == 2)
        {
            int deslocamento;
            scanf("%d", &deslocamento);
            deslocar(str_input, deslocamento);
        }
    }
    printf("%s\n", str_input);

    return 0;
}

void inverter_maiusculas(char *p)
{
    int i = 0;

    while (1)
    {
        if (p[i] == '\0')
            break;
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] -= 32;
        }
        else
        {
            if (p[i] >= 'A' && p[i] <= 'Z')
            {
                p[i] += 32;
            }
        }
        i++;
    }
}

void deslocar(char *p, int deslocamento)
{
    int i = 0;
    int z;

    while (1)
    {
        if (p[i] == '\0')
            break;
        if (p[i] >= 'a' && p[i] <= 'z' || p[i] >= 'A' && p[i] <= 'Z' || p[i] >= '0' && p[i] <= '9')
        {

            for (z = 0; z < deslocamento; z++)
            {
                p[i]++;
                if (p[i] == 'z' + 1)
                {
                    p[i] = 'a';
                }

                if (p[i] == 'Z' + 1)
                {
                    p[i] = 'A';
                }

                if (p[i] == '9' + 1)
                {
                    p[i] = '0';
                }
            }
        }
        i++;
    }
}