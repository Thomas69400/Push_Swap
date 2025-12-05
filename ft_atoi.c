
#include <stddef.h>
#include <stdlib.h>

static int is_only_nbr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!('0' <= s[i] && s[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int *ft_atoi(char *s)
{
    int minus;
    long rslt;
    int *ret;

    minus = 1;
    rslt = 0;
    if (s[0] == '-' || s[0] == '+')
    {
        if (s[0] == '-')
            minus = -1;
        s++;
    }
    if (!is_only_nbr(s))
        return (NULL);
    if (!('0' <= s[0] && s[0] <= '9'))
        return (NULL);
    while (('0' <= s[0] && s[0] <= '9') && s[0])
        rslt = (rslt * 10) + (s++[0] - 48);
    if (rslt < -2147483648 || rslt > 2147483647)
        return (NULL);
    ret = malloc(sizeof(int));
    if (!ret)
        return (NULL);
    *ret = (int)(rslt * minus);
    return (ret);
}
