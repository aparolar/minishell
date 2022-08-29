/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:48:46 by aparolar          #+#    #+#             */
/*   Updated: 2022/07/03 19:49:29 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

/*
**  Defines
*/

# define GNL_BUFFER_SIZE 1024

/*
**  Simple List
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
   Memory Functions
*/

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dst, void *src, size_t len);
void		*ft_calloc(size_t count, size_t size);

/*
	String Functions
*/

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strchrs(char *str, char *chrs);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
long		ft_atol(const char *str);
char		*ft_ltoa(long n);
char		*ft_strrem(const char *s, size_t start, size_t len);
char		*ft_strcat(const char *s1, const char *s2);
int			ft_is_valid_aint(char *str);
char		*ft_strcmp(char *s1, char *s2);
char		*ft_strreplace(char *str, char *search, char *replace);
char		*ft_str_free(char **new, char **old);

/*
	Char Functions
*/

int			ft_isalpha(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);

/*
**  Part 2
*/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putchar(char c);
int			ft_putstr(char *str);

/*
**  Lists
*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
void		ft_lstiter_if(t_list *lst, void *content,
				void (*f)(void *), int (*cmp)(void *, void *));
void		ft_lstiter_var(t_list *lst, void (*f)(void *, void **), void **var);
int			ft_lstiter_bpa_if(t_list *lst, int (*f)(void *, void *, void *));
int			ft_lstiter_count(t_list *lst, int (*f)(void *));
void		ft_lstinsert_next(t_list *lst, t_list *new);

/*
**  Other Functions
*/

int			ft_intlen(int n);
int			ft_longlen(long n);

/*
**  Files
*/

int			get_next_line(int fd, char **line);

/*
**  Array function
*/

void		ft_array_free(char **array);
size_t		ft_array_count(char **array);

#endif
