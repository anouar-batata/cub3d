/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:46:15 by alouriga          #+#    #+#             */
/*   Updated: 2025/02/15 02:56:28 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long				result;
	long				result1;

	i = 0;
	sign = 1;
	result = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result1 = result * 10 + (str[i] - '0');
		if ((result1 > 255 && sign == 1) || (result1 * sign < 0))
			return (-1);
		result = result1;
		i++;
	}
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static int	cheak(char c, char const *k)
{
	size_t	i;

	i = 0;
	while (k[i] != '\0')
	{
		if (k[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*p;
	size_t	i;
	size_t	s;
	size_t	f;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] != '\0' && cheak(s1[s], set))
		s++;
	f = ft_strlen(s1);
	while (f > s && cheak(s1[f - 1], set))
		f--;
	p = (char *)malloc(sizeof(char) * (f - s + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s < f)
	{
		p[i] = s1[s];
		i++;
		s++;
	}
	p[i] = '\0';
	return (p);
}

void	unit_data(t_datafile *data)
{

data->NO = malloc(sizeof(char *) * 2);
    data->SO = malloc(sizeof(char *) * 2);
    data->WE = malloc(sizeof(char *) * 2);
    data->EA = malloc(sizeof(char *) * 2);
    data->F = malloc(sizeof(char *) * 2);
    data->C = malloc(sizeof(char *) * 2);
    if (!data->NO || !data->SO || !data->WE || !data->EA || !data->F || !data->C)
    {
        return;
    }
    data->NO[0] = NULL;
    data->NO[1] = NULL;
    data->SO[0] = NULL;
    data->SO[1] = NULL;
    data->WE[0] = NULL;
    data->WE[1] = NULL;
    data->EA[0] = NULL;
    data->EA[1] = NULL;
    data->F[0] = NULL;
    data->F[1] = NULL;
    data->C[0] = NULL;
    data->C[1] = NULL;
    data->c = 0;
    data->No = 0;
    data->So = 0;
    data->We = 0;
    data->Ea = 0;
    data->f = 0;
}

int parce_numbers(char **res)
{
    int i;

    i = 0;
    while(res[i])
    {
        if (ft_atoi(res[i]) > 255)
        {
            printf("parce error\n");
            exit(1);
        }
        i++;
    }
    return (0);
}

int  check_parce_numbers(char *str)
{
    int i;
    int index;
    char **result;

    i = 0;
    index = 0;
    while(str[i] != '\0')
    {
        printf("%s\n", str);
         if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','))
        {
            puts("here");
            printf("parce error\n");
            exit(1);
        }
        if (str[i] == ',')
            index++;
        i++;
    }
    if (index != 3)
    {
        printf("parce error\n");
        exit(1);
    }
    result = ft_split(str, ',');
    i = 0;
    while(result[i] != NULL)
        i++;
    if (i != 3)
    {
        printf("parce error\n");
        exit(1);
    }
    parce_numbers(result);
    return (0);
}

int	check_the_result(char **res, t_datafile *data)
{
	if (!ft_strcmp(res[0], "NO") && data->No == 0)
	{
		data->NO[0] = ft_strdup(res[0]);
		data->NO[1] = ft_strdup(ft_strtrim(res[1], " "));
		data->No = 1;
	}
	else if (!ft_strcmp(res[0], "SO") && data->So == 0)
	{
		data->SO[0] = ft_strdup(res[0]);
		data->SO[1] = ft_strdup(ft_strtrim(res[1], " "));
		data->So = 1;
	}
    else if (!ft_strcmp(res[0], "WE") && data->No == 0)
    {
        data->WE[0] = ft_strdup(res[0]);
		data->WE[1] = ft_strdup(ft_strtrim(res[1], " "));
        data->We = 1;
    }
    else if (!ft_strcmp(res[0], "EA") && data->Ea == 0)
    {
        data->EA[0] = ft_strdup(res[0]);
		data->EA[1] = ft_strdup(ft_strtrim(res[1], " "));
        data->Ea = 1;
    }
    else if(!ft_strcmp(res[0], "F") && data->f == 0)
    {
        check_parce_numbers(ft_strtrim(res[1], " "));
        data->F[0] = ft_strdup(res[0]);
        data->F[1] = ft_strdup(ft_strtrim(res[1], " "));
        data->f = 1;
    }
    else if(!ft_strcmp(res[0], "C") && data->f == 0)
    {
        check_parce_numbers(ft_strtrim(res[1], " "));
        data->C[0] = ft_strdup(res[0]);
        data->C[1] = ft_strdup(ft_strtrim(res[1], " "));
        data->c = 1;
    }
	return(0);
}

int check_the_string(char *str, t_datafile *data)
{
	char *s;
	char **res;
	
	while (*str != '\0')
	{
		if (*str == ' ')
			str++;
		else
		{
			s = str;
			break;
		}
	}
	res = split_first_space(s);
    if (res[1] == NULL)
    {
        printf("parce error\n");
        exit(1);
    }
	check_the_result(res, data);
	return (0);
}

void    read_the_file(int fd)
{
	t_datafile *data;
	data = malloc(sizeof(t_datafile));
    char *td_arr;
    char *str;
    int i = 0;
	
	// printf("LOL\n");
	unit_data(data);
    td_arr = get_next_line(fd);
    while(td_arr != NULL) 
    {
        str = ft_strdup(td_arr);
        check_the_string(str, data);
		printf("%s\n", data->NO[0]);
        printf("%s\n", data->NO[1]);
        printf("%s\n", data->SO[0]);
        printf("%s\n", data->SO[1]);
    	td_arr = get_next_line(fd);
    }
}

int parce_name_file(char *str, int index)
{
    int i = 0;
    while(*str && i < index - 4)
    {
        i++;
        str++;
    }
    if (ft_strcmp(str, ".cub"))
        return (1);
    return (0);
    
}

int main(int ac, char **av)
{
    int i;
    
    if (ac == 2)
    {
        if (ft_strlen(av[1]) <= 4)
        {
            printf("error in name file\n");
            exit(1);
        }
        i = parce_name_file(av[1], ft_strlen(av[1]));
        if (i == 0)
        {
            i = open(av[1], O_RDONLY);
            if (i == -1)
            {
                printf("error in the input\n");
                exit(1);
            }
            else
                read_the_file(i);
        }
        else
        {
            printf("error in name file\n");
            exit(1);
        }
    }
    else
        printf("error in the input\n");
}