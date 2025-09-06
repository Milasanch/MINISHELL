/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:44:11 by rfleritt          #+#    #+#             */
/*   Updated: 2025/09/04 12:20:11 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data  *init_shell(char **env)
{
	t_data *data;
	
	data = ft_calloc(1, sizeof(t_data));
	data->input = NULL;
	data->token = NULL;
	data->env = env;
    return (data);
}

void	shell_prompt(t_data *data)
{
	new_signal();
	while (1)
    {
        data->input = readline("minishell> ");
		
        if (!data->input)
        {
            rl_clear_history();
            printf("exit\n");
            free(data);
            break ;
        }
        if (data->input)
        {
            if (parse_input(data))
                return ;
        }
    }
}
