/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:50:51 by mpeulet           #+#    #+#             */
/*   Updated: 2023/10/02 14:47:01 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

/*define gnl*/

# define BUFFER_SIZE 42
# define MAX_FD 1024

/*struct gnl*/

typedef struct s_gnl
{
	int		tdl;
	char	*temp;
	char	*str;
}		t_gnl;

/*struct int*/

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}		t_int;

/*struct libt*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

/*struct ft_printf*/

typedef struct s_pff
{
	va_list		args1;
	int			tl;
}		t_pff;

/* bits */

void	print_bits(unsigned char octet);

/*gnl*/

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*gnl(int fd, int clear);
char	*get_next_line_bonus(int fd);
char	*get_next_line(int fd);

/*is*/

int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_iswhitespace(int c);
int		ft_int_over_maxmin(long nb);
int		ft_is_sign(int c);

/*lst*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newl);
int		ft_lstsize(t_list *lst);	
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newl);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_sort_list(t_list *lst, int (*cmp)(int, int));

/* math */

int		abs_value(int nb);
size_t	lcm(unsigned int a, unsigned int b);
size_t	pgcd(unsigned int a, unsigned int b);

/* mem */

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/* other */

void	ft_swap(int *a, int *b);

/*pf*/

/****************************************************************/

/* *** Main ft_printf file *** */

t_pff	*init_tab(t_pff *tab);
int		ft_whatisnext(t_pff *tab, const char *s, int i);
int		ft_printf(const char *format, ...);

/* *** Utils files for %c %s %d %i %u *** */

void	ft_printf_char(t_pff *tab);
int		ft_put_str_printf(t_pff *tab);
void	ft_put_idnbr_printf(t_pff *tab);
void	print_unbr(unsigned int ui, t_pff *tab);
void	ft_put_unbr_printf(t_pff *tab);

/* *** Utils files for %p %x %X *** */

int		ft_putcharpf(char c);
void	print_ptr(unsigned long p, t_pff *tab);
int		ft_put_ptr_printf(t_pff *tab);
void	print_hex(unsigned int h, t_pff *tab, char c);
int		ft_put_hex_printf(t_pff *tab, char c);

/****************************************************************/

/*put*/

void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_stdout(char c);
void	ft_putstr_stdout(char *s);
void	ft_putendl_stdout(char *s);

/*str*/

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strcmp(char *s1, char *s2);
int		ft_str_isdigit(char *s);

/*to*/

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
double	ft_atof(const char *s);
long	ft_atol(const char *str);

/* *** To use library : #include "libft.h" header in the code  *** */
/* *** gcc -c -o main.o main.c *** */
/* *** gcc -o program_name main.o -L. -lft *** */

#endif
