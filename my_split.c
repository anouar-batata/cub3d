/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:51:40 by alouriga          #+#    #+#             */
/*   Updated: 2025/02/13 22:12:24 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// char	*ft_strdup(char *s1)
// {
// 	char	*cpy;
// 	size_t	i;

// 	if (!s1)
// 		return (NULL);
// 	cpy = (char *)malloc((ft_strlen2(s1) + 1) * sizeof(char));
// 	if (!cpy)
// 		exit(1);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		cpy[i] = s1[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*my_strcpy(char *dest, const char *src)
// {
// 	char	*ptr;

// 	ptr = dest;
// 	while (*src)
// 	{
// 		*ptr++ = *src++;
// 	}
// 	*ptr = '\0';
// 	return (dest);
// }

// char	*my_strncpy(char *dest, const char *src, size_t n)
// {
// 	char	*ptr;

// 	ptr = dest;
// 	while (n > 0 && *src)
// 	{
// 		*ptr++ = *src++;
// 		n--;
// 	}
// 	while (n > 0)
// 	{
// 		*ptr++ = '\0';
// 		n--;
// 	}
// 	return (dest);
// }

// char	*ft_strchrr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*(unsigned char *)s == (unsigned char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*(unsigned char *)s == (unsigned char)c)
// 		return ((char *)s);
// 	return (NULL);
// }

// char	**split_first_equal(const char *str, char **result
// 							, const char *equal_pos, size_t key_len)
// {
// 	size_t		value_len;

// 	result = malloc(3 * sizeof(char *));
// 	if (!result)
// 		exit (1);
// 	equal_pos = ft_strchrr(str, '=');
// 	if (!equal_pos)
// 	{
// 		result[0] = ft_strdup((char *)str);
// 		result[1] = NULL;
// 		return (result);
// 	}
// 	key_len = equal_pos - str;
// 	result[0] = malloc(key_len + 1);
// 	if (!result[0])
// 		exit (1);
// 	my_strncpy(result[0], str, key_len);
// 	result[0][key_len] = '\0';
// 	value_len = ft_strlen(equal_pos + 1);
// 	result[1] = malloc(value_len + 1);
// 	if (!result[1])
// 		exit (1);
// 	my_strcpy(result[1], equal_pos + 1);
// 	result[2] = NULL;
// 	return (result);
// }





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_first_space(const char *str)
{
    char **result = malloc(3 * sizeof(char *));
    if (!result)
        exit(1);

    const char *space_pos = strchr(str, ' ');  // Find the first space
    if (!space_pos) {
        result[0] = strdup(str);
        result[1] = NULL;
        return result;
    }

    size_t key_len = space_pos - str;
    result[0] = strndup(str, key_len);

    // Skip the first space
    space_pos++;

    result[1] = strdup(space_pos);
    result[2] = NULL;
    return result;
}


// int main() 
// {
//     char *str = "NO       jf/dfij/dfjk  9       ";
//     char **res;
//     res = split_first_space(str);
//     int i = 0;
//     while(res[i] != NULL)
//     {
//         printf("%s\n", res[i]);
//         i++;
//     }
//     return(0);
// }

// size_t	ft_strlenn(const char *s) {
// 	int	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*my_strncpy(char *dest, const char *src, size_t n) {
// 	char	*ptr = dest;
// 	while (n > 0 && *src) {
// 		*ptr++ = *src++;
// 		n--;
// 	}
// 	*ptr = '\0';
// 	return (dest);
// }

// char	*my_strcpy(char *dest, const char *src) {
// 	char	*ptr = dest;
// 	while (*src) {
// 		*ptr++ = *src++;
// 	}
// 	*ptr = '\0';
// 	return (dest);
// }

// char	**split_first_space(const char *str) {
// 	const char *space_pos;
// 	char **result;
// 	size_t key_len, value_len;

// 	result = malloc(3 * sizeof(char *));
// 	if (!result)
// 		exit(1);

// 	space_pos = strchr(str, ' ');  // Find the first space
// 	if (!space_pos) {
// 		result[0] = strdup(str);
// 		result[1] = NULL;
// 		return result;
// 	}

// 	key_len = space_pos - str;
// 	result[0] = malloc(key_len + 1);
// 	if (!result[0])
// 		exit(1);
// 	my_strncpy(result[0], str, key_len);

// 	// Skip additional spaces after the first one
// 	while (*space_pos == ' ')
// 		space_pos++;

// 	value_len = ft_strlenn(space_pos);
// 	result[1] = malloc(value_len + 1);
// 	if (!result[1])
// 		exit(1);
// 	my_strcpy(result[1], space_pos);

// 	result[2] = NULL;
// 	return result;
// }