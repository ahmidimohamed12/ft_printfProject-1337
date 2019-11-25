/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:14:24 by mahmidi           #+#    #+#             */
/*   Updated: 2019/10/18 11:22:06 by mahmidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
#define	LIBFT_H
#define	BUFF_SIZE 100;

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

typedef struct s_list
{
	void	*content;
	struct s_list	*next;

}					t_list;

int					ft_strlen(char *a);
int					ft_toupper(int a);
int 				ft_tolower(int a);
void				ft_putchar(char a);
void				ft_putstr(char *a);
void				ft_putchar_fd(char a, int fd);
int					ft_isdigit(int a);
void				ft_putstr_fd(char  *a, int fd);
void				ft_putnbr(int a);
void				ft_putnbr_fd(int n,	int fd);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long				ft_atoi(const char *str);
char				*ft_strrchr(const char *s, int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
char				*ft_strsub(char *c, int n, int len);
int					ft_isascii(int a);
int					ft_isalnum(int a);
int					ft_isalpha(int a);
int					ft_isprint(int a);
void				*ft_memcpy(void *dest, void *src, size_t n);
char				*ft_strnew(int n);
void				ft_bzero(void *d, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char 				*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
#endif
