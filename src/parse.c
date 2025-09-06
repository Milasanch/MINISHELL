/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:43:10 by rfleritt          #+#    #+#             */
/*   Updated: 2025/09/04 14:46:15 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_quote	parse_quotes(t_data *data, int i)
{
	t_quote	state;
	
	state = GENERAL;
	while (data->input[i])
    {
        if (state == GENERAL)
        {
            if (data->input[i] == '\'')
                state = SINGLE;
            else if (data->input[i] == '"')
                state = DOUBLE;
        }
        else if (state == SINGLE)
        {
            if (data->input[i] == '\'')
                state = GENERAL;
        }
        else if (state == DOUBLE)
        {
            if (data->input[i] == '"')
                state = GENERAL;
        }
        i++;
    }
	return (state);
}

int	parse_pipes(t_data *data, int i)
{
	return (false);
}

int parse_syntax(t_data *data)
{
    int i = 0;

	while(data->input[i])
	{
		if (data->input[i] == '"' || data->input[i] == 39)
		{
    		if (parse_quotes(data, i) != GENERAL)
        		printf("Syntax error\n");
		}
		if (data->input[i] == '|')
		{
			if (parse_pipes(data, i))
				printf("Syntax error");
		}
		if (data->input[i] == '<' || data->input[i] == '>')
		{
			if (parse_pipes(data, i))
				printf("Syntax error");
		}
		i++;
	}
	if (parse_pipes())
	return (LOOP_RUN);
}

int	parse_input(t_data *data)
{
	if (ft_strcmp("", data->input) != 0)
		add_history(data->input);
	if (parse_syntax(data))
		return(LOOP_RUN);
	if (ft_strcmp("exit", data->input) == 0)
	{
		rl_clear_history();
        printf("exit\n");
		free(data);
		return (LOOP_STOP);
	}
	return (LOOP_RUN);
}