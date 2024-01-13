/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:19:54 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/01 13:04:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_tolower(unsigned int c);
int		ft_isdigit(unsigned int c);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
int		ft_isalnum(unsigned int c);
char	*ft_strrchr(const char *src, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_lstdelone(t_list *lst, void (*del) (void*));
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isascii(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstnew(void *content);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_toupper(unsigned int c);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar_fd(char c, int fd);
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_isprint(unsigned int c);
int		ft_isalpha(int c);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_atoi(const char *nptr);
void	*ft_memchr(void *src, char chr, size_t n);
char	*ft_strchr(const char *src, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t size);
void	ft_putendl_fd(char *s, int fd);

#endif
