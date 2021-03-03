#include "minishell.h"

void	wsh_unset(t_wsh_tokens *wsh_token, t_wsh_list *wsh_list)
{
	int	i;
	int j;

	i = 32;
	while (wsh_list->wsh_envs[i] != NULL)
	{
		j = 0;
		while (wsh_token->wsh_param[j][0] != '\0')
		{
			if (wsh_list->wsh_envs[i][0] == wsh_token->wsh_param[j][0])
			{
				if (!(ft_strncmp(wsh_list->wsh_envs[i], wsh_token->wsh_param[j], ft_strlen(wsh_token->wsh_param[j]))))
				{
					wsh_free((void *)wsh_list->wsh_envs[i]);
					wsh_list->wsh_envs[i] = NULL;
				}
			}
			j++;
		}
		i++;
	}
	return ;
}