/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:58:10 by hmeys             #+#    #+#             */
/*   Updated: 2020/01/22 18:13:14 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 20
# include <limits.h>

typedef struct		s_liste
{
	void			*content;
	size_t			content_size;
	struct s_liste	*next;
}					t_liste;
void				*ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int					atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char*s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(const char *str, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
t_liste				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_liste **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_liste **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_liste **alst, t_liste *new);
void				ft_lstiter(t_liste *lst, void (*f)(t_liste *elem));
t_liste				*ft_lstmap(t_liste *lst, t_liste *(*f)(t_liste *elem));
char				*ft_strcut(char *str, int go, int stop);
int					get_next_line(const int fd, char **line);
char				**ft_strsplit_space(char const *s);
int					ft_isspace(char c);
char				*ft_str3join(char const *s1, char const *s2,
					char const *s3);
void				ft_exit_failure(char *str, int fd);
#endif
