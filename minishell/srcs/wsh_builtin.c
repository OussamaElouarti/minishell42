#include "minishell.h"

int		ft_isbuiltin(const char *command)
{
	static char builin[7][10] = {"echo", "cd", "pwd", "exit", "export", "unset", "env"};
	int			i;

	i = 0;
	while (!ft_strncmp(command, builin[i], ft_strlen(builin[i])))
		i++;
	if (ft_strncmp(command, builin[i], ft_strlen(builin[i])))
		return (1);
	return (0);
}

int		wsh_exec_builtin(t_wsh_list *wsh_list)
{
	if (!ft_strncmp(wsh_list->ast_parsed->wsh_command, "exit", 5))
		wsh_exit(wsh_list);
	if (!ft_strncmp(wsh_list->ast_parsed->wsh_command, "pwd", 4))
		wsh_pwd();
	if (!ft_strncmp(wsh_list->ast_parsed->wsh_command, "env", 4))
		wsh_env(wsh_list->wsh_envs);
	if (!ft_strncmp(wsh_list->ast_parsed->wsh_command, "export", 7))
		wsh_export(wsh_list->ast_parsed, wsh_list);
	if (!ft_strncmp(wsh_list->ast_parsed->wsh_command, "unset", 6))
		wsh_unset(wsh_list->ast_parsed, wsh_list);
	return (0);
}