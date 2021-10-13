#include "libft.h"

void	*ft_lst_to_arr(t_list *lst)
{
	void	**arr;
	int		i;
	int		count;

	count = ft_lstsize(lst);
	arr = malloc(sizeof(void *) * (count + 1));
	i = 0;
	while (lst)
	{
		arr[i++] = lst->content;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}