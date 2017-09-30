#include "../includes/vm.h"

long long int			ft_atoiLong(const char *str)
{
    long long int		i;
    long long int		result;
    int		            sign;

    result = 0;
    i = 0;
    sign = 1;
    if (str[i] == '\200')
        return (0);
    while (str[i] < 33)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
        result = ((result * 10) + (str[i] - '0'));
        i++;
    }
    return (result * sign);
}