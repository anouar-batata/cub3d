/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouriga <alouriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:07:11 by alouriga          #+#    #+#             */
/*   Updated: 2025/02/15 02:44:51 by alouriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_datafile
{
    char **NO;
    int No;
    char **SO;
    int So;
    char **WE;
    int We;
    char **EA;
    int Ea;
    char **F;
    int f;
    char **C;
    int c;
}   t_datafile;

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_free(char *reach);
char **split_first_space(const char *str);
char	**ft_split(char const *s, char c);