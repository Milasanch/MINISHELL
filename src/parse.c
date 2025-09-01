/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:43:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/09/01 13:15:29 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parse_input(t_data *data)
{
	if (ft_strcmp("", data->input) != 0)
		add_history(data->input);
	
	//if (tok_init(data))
	//	return (LOOP_STOP);
}