/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:23:49 by rfleritt          #+#    #+#             */
/*   Updated: 2025/09/01 13:10:39 by rfleritt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <termcap.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define LOOP_STOP 0
# define LOOP_RUN 1

typedef enum e_type {
    CMD,
    ARG,
    PIPE,
    REDIR_OUT,
    REDIR_IN,
    APPEND,
    HEREDOC
} t_type;

typedef struct s_token {
    char *value;
    t_type type;
    struct s_token *next;
} t_token;

typedef struct s_data
{
    char *input;
    char **env;
    t_token	*token;
}	t_data;

void	sigint_handler(int sig);
void	shell_prompt(t_data *data);
void	new_signal(void);
int		parse_input(t_data *data);
int 	tok_init(t_data *data);
t_data  *init_shell(char **env);

#endif