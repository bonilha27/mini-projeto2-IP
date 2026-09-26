#include <stdio.h>

void inverter_maiusculas(char *p);
void deslocar(char *p, int deslocamento);
void rotacionar(char *p, int n_rot);
void invertePalavra(char palavra[]);
void trocarParesImpares(char palavra[]);
void trocarMetades(char palavra[]);
int str_tamanho(char *p);

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

        if (n == 1)
        {
            invertePalavra(str_input);
        }

        if (n == 2)
        {
            int deslocamento;
            scanf("%d%*c", &deslocamento);
            deslocar(str_input, deslocamento);
        }

        if (n == 3)
        {
            trocarParesImpares(str_input);
        }

        if (n == 4)
        {
            inverter_maiusculas(str_input);
        }

        if (n == 5)
        {
            int n_rot;
            scanf("%d%*c", &n_rot);
            rotacionar(str_input, n_rot);
        }

        if (n == 6)
        {
            trocarMetades(str_input);
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
            if (deslocamento >= 0)
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

            else
            {
                for (z = 0; z < -deslocamento; z++)
                {
                    p[i]--;
                    if (p[i] == 'a' - 1)
                    {
                        p[i] = 'z';
                    }

                    if (p[i] == 'A' - 1)
                    {
                        p[i] = 'Z';
                    }

                    if (p[i] == '0' - 1)
                    {
                        p[i] = '9';
                    }
                }
            }
        }
        i++;
    }
}
void rotacionar(char *p, int n_rot)
{
    int z, temp, i;
    temp = i = 0;
    char str_rotacionada[10001];
    if (n_rot > 0)
    {
        for (z = 0; z < n_rot; z++)
        {
            temp = i = 0;
            while (1)
            {
                if (p[i] == '\0')
                    break;

                if (p[i + 1] == '\0')
                {
                    str_rotacionada[0] = p[i];
                }
                else
                    str_rotacionada[i + 1] = p[i];

                i++;
            }
            while (1)
            {
                if (p[temp] == '\0')
                    break;
                p[temp] = str_rotacionada[temp];
                temp++;
            }
        }
    }
    else
    {
        for (z = 0; z < -n_rot; z++)
        {
            temp = i = 0;
            while (1)
            {
                if (p[i] == '\0')
                    break;
                str_rotacionada[i] = p[i + 1];

                if (str_rotacionada[i] == '\0')
                {
                    str_rotacionada[i] = p[0];
                }

                i++;
            }
            while (1)
            {
                if (p[temp] == '\0')
                    break;
                p[temp] = str_rotacionada[temp];
                temp++;
            }
        }
    }
}

void invertePalavra(char palavra[])
{
    int i, j;
    char guardaCaracteres;
    for (i = 0, j = str_tamanho(palavra) - 1; i < j; i++, j--)
    {
        guardaCaracteres = palavra[i];
        palavra[i] = palavra[j];
        palavra[j] = guardaCaracteres;
    }
}

void trocarParesImpares(char palavra[])
{
    int i, j;
    char guardaCaracteres;

    for (i = 0, j = 1; j < str_tamanho(palavra); i += 2, j += 2)
    {
        guardaCaracteres = palavra[i];
        palavra[i] = palavra[j];
        palavra[j] = guardaCaracteres;
    }
}

void trocarMetades(char palavra[])
{
    int tamanho = 0;

    while (palavra[tamanho] != '\0')
    {
        tamanho++;
    }
    int metade = tamanho / 2;
    int pulo;
    int i;

    if (tamanho % 2 == 0)
    {
        pulo = metade;
    }
    else
    {
        pulo = metade + 1;
    }
    for (i = 0; i < metade; i++)
    {
        char reserva = palavra[i];
        palavra[i] = palavra[i + pulo];
        palavra[i + pulo] = reserva;
    }
    if (tamanho % 2 != 0)
    {
        char centro = palavra[metade];
        for (i = metade; i < tamanho - 1; i++)
        {
            palavra[i] = palavra[i + 1];
        }
        palavra[tamanho - 1] = centro;
    }
}

int str_tamanho(char p[])
{
    int i, contador;
    contador = i = 0;
    while (1)
    {
        if (p[i] != '\0')
            contador++;
        if (p[i] == '\0')
        {
            break;
        }
        i++;
    }
    return contador;
}