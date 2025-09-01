/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:33:18 by rfleritt          #+#    #+#             */
/*   Updated: 2025/09/01 17:28:57 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
    t_data	*data;
    (void)argv;
    (void)env;
		
    if (argc != 1)
    {
        ft_putstr_fd("No arguments\n", 2);
        return (1);
    }
	data = init_shell(env);
    shell_prompt(data);
    return (0);    
}
