/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:44:11 by rfleritt          #+#    #+#             */
/*   Updated: 2025/08/28 13:46:21 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	shell_prompt(t_data *data)
{
	while (1)
    {
        data->input = readline("minishell> ");
		
        if (!data->input)
        {
            printf("exit\n");
            break ;
        }
        if (data->input)
            add_history(data->input);
    }
}
