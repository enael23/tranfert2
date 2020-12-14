/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:30:37 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/11/24 19:19:09 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gcc -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -Iincludes -o main main.c -L. -lft
** gcc -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -Iincludes main.c -L. -lft -o main
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	if (n / 10 != 0)
		ft_putnbr(ft_abs(n / 10));
	ft_putchar(ft_abs(n % 10) + '0');
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
		write(1, str, i);
}

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
	return (str);
}

char	*ft_strdup_main(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((dest = (char *)malloc(++i * sizeof(char))) == NULL)
		return (NULL);
	while (i-- > 0)
		dest[i] = s[i];
	return (dest);
}

t_list	*ft_lstnew_main(void *content)
{
	t_list	*elem;

	if (content == NULL)
		return (NULL);
	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_back_main(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL || new == NULL) // or no check to crash the program if given a NULL ptr?
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void 	ft_lstclear_main(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL) // or no check to crash the program if given a NULL ptr?
		return ;
	while (*lst != NULL)
	{
		if (del != NULL && (*lst)->content != NULL) // to avoid free on a non-malloc memory if given NULL as "*del_fct"
			(*del)((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

int		main(void)
{
//									FT_LSTNEW
	t_list	*list;
//									FT_LSTADD_FRONT
	t_list	*tmp;
//									FT_LSTSIZE
//									FT_LSTLAST
//									FT_LSTADD_BACK
//									FT_LSTDELONE
//									FT_LSTCLEAR
//									FT_LSTITER
//									FT_LSTMAP
	t_list	*new_list;



//									FT_LSTNEW
	ft_putstr("\t\t\t\t\t\t\tFT_LSTNEW\n");
	ft_putstr("ft_lstnew(\"Hello world!\") [expected: Hello world!] : ");
	list = ft_lstnew("Hello world!");
	ft_putstr(list->content);
	free(list);
	write(1, "\n", 1);
	ft_putstr("ft_lstnew(NULL) [expected: (null)] : ");
	list = ft_lstnew(NULL);
//	if (list->content == NULL)
	if (list == NULL)
		ft_putstr("(null)");
//	free(list);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTADD_FRONT
	ft_putstr("\t\t\t\t\t\t\tFT_LSTADD_FRONT\n");
	ft_putstr("ft_lstadd_front(NULL, ft_lstnew_main(\"Hello\")) [expected: ] : ");
	ft_lstadd_front(NULL, list = ft_lstnew_main("Hello"));
	free(list);
	write(1, "\n", 1);
	list = NULL;
	ft_putstr("ft_lstadd_front(&list, NULL), (&list, ft_lstnew_main(\" world!\")), (&list, ft_lstnew_main(\"Hello\")) [expected: Hello world!] : ");
	ft_lstadd_front(&list, NULL);
	ft_lstadd_front(&list, ft_lstnew_main(" world!"));
	ft_lstadd_front(&list, ft_lstnew_main("Hello"));
	while (list != NULL)
	{
		ft_putstr(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTSIZE
	ft_putstr("\t\t\t\t\t\t\tFT_LSTSIZE\n");
	ft_putstr("lst = NULL");
	list = NULL;
	ft_putstr(" -> lstsize [expected: 0] = ");
	ft_putnbr(ft_lstsize(list));
	write(1, "\n", 1);
	ft_putstr("lst = ");
	ft_lstadd_front(&list, ft_lstnew_main("Hello"));
	ft_putstr(list->content);
	ft_putstr(" -> lstsize [expected: 1] = ");
	ft_putnbr(ft_lstsize(list));
	write(1, "\n", 1);
	ft_putstr("lst = ");
	ft_putstr(list->content);
	ft_lstadd_front(&list, ft_lstnew_main(" world"));
	ft_putstr(list->content);
	ft_putstr(" -> lstsize [expected: 2] = ");
	ft_putnbr(ft_lstsize(list));
	write(1, "\n", 1);
	ft_putstr("lst = ");
	ft_putstr(list->next->content);
	ft_putstr(list->content);
	ft_lstadd_front(&list, ft_lstnew_main("!"));
	ft_putstr(list->content);
	ft_putstr(" -> lstsize [expected: 3] = ");
	ft_putnbr(ft_lstsize(list));
	write(1, "\n", 1);
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTLAST
	ft_putstr("\t\t\t\t\t\t\tFT_LSTLAST\n");
	ft_putstr("lst = NULL");
	list = NULL;
	write(1, "\n", 1);
	ft_putstr("ft_lstlast [expected: (null)] = ");
	if (ft_lstlast(list) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_lstadd_front(&list, ft_lstnew_main("!"));
	ft_lstadd_front(&list, ft_lstnew_main(" world"));
	ft_lstadd_front(&list, ft_lstnew_main("Hello"));
	ft_putstr("lst = ");
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_putstr("ft_lstlast(lst) [expected: !] = ");
	ft_putstr(ft_lstlast(list)->content);
	write(1, "\n", 1);
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTADD_BACK
	ft_putstr("\t\t\t\t\t\t\tFT_LSTADD_BACK\n");
	ft_putstr("ft_lstadd_back(NULL, ft_lstnew_main(\"Hello\")) [expected: ] : ");
	ft_lstadd_back(NULL, list = ft_lstnew_main("Hello"));
	free(list);
	write(1, "\n", 1);
	list = NULL;
	ft_putstr("ft_lstadd_back(&list, NULL), (&list, ft_lstnew_main(\"Hello\")), (&list, ft_lstnew_main(\" world!\")) [expected: Hello world!] : ");
	ft_lstadd_back(&list, NULL);
	ft_lstadd_back(&list, ft_lstnew_main("Hello"));
	ft_lstadd_back(&list, ft_lstnew_main(" world!"));
	while (list != NULL)
	{
		ft_putstr(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTDELONE
	ft_putstr("\t\t\t\t\t\t\tFT_LSTDELONE\n");
	ft_putstr("lst = NULL\n");
	list = NULL;
	ft_putstr("ft_lstadd_back_main(&list, ft_strdup_main(\"Hello\"), ft_strdup_main(\" world!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("Hello")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main(" world!")));
	ft_putstr("lst = ");
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_putstr("ft_lstdelone(xxx, &free) on all elements\n");
	tmp = list;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		ft_lstdelone(tmp, &free);
	}
	ft_putstr("lst [expected: (null)] = ");
	if (list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_lstadd_back_main(&list, ft_lstnew_main(\"Hello\"), ft_lstnew_main(\" world!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main("Hello"));
	ft_lstadd_back_main(&list, ft_lstnew_main(" world!"));
	ft_putstr("lst = ");
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_putstr("ft_lstdelone(xxx, NULL) on all elements\n");
	tmp = list;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		ft_lstdelone(tmp, NULL);
	}
	ft_putstr("lst [expected: (null)] = ");
	if (list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTCLEAR
	ft_putstr("\t\t\t\t\t\t\tFT_LSTCLEAR\n");
	ft_putstr("lst = NULL\n");
	list = NULL;
	ft_putstr("ft_lstadd_back_main(&list, ft_strdup_main(\"Hello\"), ft_strdup_main(\" world!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("Hello")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main(" world!")));
	ft_putstr("lst = ");
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_putstr("ft_lstclear(NULL, &free), ft_lstclear(&lst, &free)\n");
	ft_lstclear(NULL, &free);
	ft_lstclear(&list, &free);
	ft_putstr("lst [expected: (null)] = ");
	if (list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_lstclear(&lst, &free)\n");
	ft_lstclear(&list, &free);
	ft_putstr("(no crash)");
	write(1, "\n", 1);
	ft_putstr("ft_lstadd_back_main(&list, ft_lstnew_main(\"Hello\"), ft_lstnew_main(\" world!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main("Hello"));
	ft_lstadd_back_main(&list, ft_lstnew_main(" world!"));
	ft_putstr("lst = ");
	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
	ft_putstr("ft_lstclear(&lst, NULL)\n");
	ft_lstclear(&list, NULL);
	ft_putstr("lst [expected: (null)] = ");
	if (list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTITER
	ft_putstr("\t\t\t\t\t\t\tFT_LSTITER\n");
	ft_putstr("lst = NULL\n");
	list = NULL;
	ft_putstr("ft_lstadd_back_main(&list, ft_strdup_main(\"Hello\"), ft_strdup_main(\" world\"), ft_strdup_main(\"!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("Hello")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main(" world")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("!")));
	ft_putstr("ft_lstiter(list, NULL) [expected: ] = ");
	ft_lstiter(list, NULL);
	write(1, "\n", 1);
	ft_putstr("ft_lstiter(list, &ft_putstr) [expected: Hello world!] = ");
	ft_lstiter(list, (void (*)(void *))&ft_putstr);
	write(1, "\n", 1);
	ft_lstclear_main(&list, &free);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_LSTMAP
	ft_putstr("\t\t\t\t\t\t\tFT_LSTMAP\n");
	ft_putstr("lst = NULL\n");
	list = NULL;
	ft_putstr("ft_lstadd_back_main(&list, ft_strdup_main(\"Hello\"), ft_strdup_main(\" world\"), ft_strdup_main(\"!\")\n");
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("Hello")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main(" world")));
	ft_lstadd_back_main(&list, ft_lstnew_main(ft_strdup_main("!")));
	ft_putstr("ft_lstiter(list, &ft_putstr) = ");
	ft_lstiter(list, NULL);
	ft_lstiter(list, (void (*)(void *))&ft_putstr);
	write(1, "\n", 1);
	ft_putstr("new_lst = NULL\n");
	new_list = NULL;
	ft_putstr("new_list = ft_lstmap(NULL, &ft_strcapitalize, &free) [expected: (null)] = ");
	new_list = ft_lstmap(NULL, (void *(*)(void *))&ft_strcapitalize, &free);
	if (new_list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("new_list = ft_lstmap(list, NULL, &free) [expected: (null)] = ");
	new_list = ft_lstmap(list, NULL, &free);
	if (new_list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("new_list = ft_lstmap(list, &ft_strcapitalize, &free) [expected: HELLO WORLD!] = ");
	new_list = ft_lstmap(list, (void *(*)(void *))&ft_strcapitalize, &free);
	ft_lstiter(new_list, (void (*)(void *))&ft_putstr);
	write(1, "\n", 1);
	ft_putstr("ft_lstclear_main(&new_list, NULL) [expected: (null)] = ");
	ft_lstclear_main(&new_list, NULL);
	if (new_list == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("new_list = ft_lstmap(list, &ft_strcapitalize, NULL) [expected: HELLO WORLD!] = ");
	new_list = ft_lstmap(list, (void *(*)(void *))&ft_strcapitalize, NULL);
	ft_lstiter(new_list, (void (*)(void *))&ft_putstr);
	write(1, "\n", 1);
	ft_lstclear_main(&list, NULL);
	ft_lstclear_main(&new_list, &free);



	return (0);
}
