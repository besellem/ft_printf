/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 02:16:30 by besellem          #+#    #+#             */
/*   Updated: 2020/11/15 16:49:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** INCLUDES
*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

/*
** FUNCTIONS PROTOTYPES
*/
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** LISTS BONUS
*/
typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

/*
** ADDED
*/
double			ft_atod(const char *str);
int				ft_atoi_base(char *str, char *base);
long			ft_atol(const char *str);
long double		ft_atold(const char *str);
long long		ft_atoll(const char *str);
long			ft_strtol(const char *str, char **endptr, int base);
long long		ft_strtoll(const char *str, char **endptr, int base);
char			*ft_itoa_base(long long n, char *base);
size_t			ft_factorial(size_t nb);
int				ft_find_next_prime(int nb);
int				ft_is_prime(long long nb);
int				ft_nblen(long long n);
int				ft_nblen_base(long long n, int base);
long long		ft_power(long long nb, int power);
void			ft_putaddr(void *addr);
void			ft_putaddr_fd(void *addr, int fd);
void			ft_putchar(char c);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putstr(char *s);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strcasestr(const char *haystack, const char *needle);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, size_t n);
size_t			ft_strnlen(const char *s, size_t maxlen);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strpbrk(const char *s, const char *charset);
char			**ft_strsplit(char *str, char *charset);
char			*ft_strstr(const char *haystack, const char *needle);

#endif
