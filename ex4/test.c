#include <stdio.h>
#include <stdlib.h>

int     base_len(char *base)
{
        int     i;

        i = 0;
        while (base[i])
        {
                i++;
        }
        return (i);
}

int     index_in_base(char c, char *base)
{
        int     i;

        i = 0;
        while (base[i])
        {
                if (c == base[i])
                        return (i);
                i++;
        }
        return (-1);
}

char    *itoa(int nbr, char *base)
{
        char    *str;
        int     i;
        int     count;
        int     temp;
        int     rest;

        temp = nbr;
        count = 0;
        if (temp == 0)
                return (0);
        while (temp > 0)
        {
                temp = temp % base_len(base);
                count++;
        }
        str = malloc(sizeof(char) * count + 1);
        i = 0;
        while (i < count)
        {
                rest = nbr % base_len(base);
                str[i] = base[rest];
                nbr /= base_len(base);
                i++;
        }
        return (str);
}

int main(void)
{
  char *base = "0123456789ABCDEF";
  int nbr = 10;
  int i = 0;
  char *str = itoa(nbr, base);
  
  while(str[i])
  {
    printf("%s", str[i]);
    i++;
  }
}
