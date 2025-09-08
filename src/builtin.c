/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:09:12 by milagros          #+#    #+#             */
/*   Updated: 2025/09/08 02:42:58 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_echo(char **argv)
{
    int i = 1;
    int nflag = 0;

    while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
    {
        int j = 2;
        while (argv[i][j] == 'n') 
            j++;
        if (argv[i][j] != '\0') 
            break; 
        nflag = 1;
        i++;
    }
    while (argv[i])
    {
        write(STDOUT_FILENO, argv[i], ft_strlen(argv[i]));
        if (argv[i + 1]) 
            write(STDOUT_FILENO, " ", 1);
        i++;
    }
    if (!nflag) 
        write(STDOUT_FILENO, "\n", 1);
    return 0;
}

// int ft_cd(char **argv, t_env **env)
// {
//     const char *path = argv[1];
//     char oldpwd[PATH_MAX];

//     if (!path)
//     {
//         const char *home = env_get(*env, "HOME");
//         if (!home)
//         {
//             puterr("minishell: cd: ", "HOME not set", "\n");
//             return 1;
//         }
//         path = home;
//     }
//     if (!getcwd(oldpwd, sizeof(oldpwd))) oldpwd[0] = '\0';

//     if (chdir(path) != 0)
//     {
//         puterr("minishell: cd: ", path, ": ");
//         puterr(strerror(errno), NULL, "\n");
//         return 1;
//     }
//     if (oldpwd[0]) env_set(env, "OLDPWD", oldpwd);
//     {
//         char newpwd[PATH_MAX];
//         if (getcwd(newpwd, sizeof(newpwd))) env_set(env, "PWD", newpwd);
//     }
//     return 0;
// }

// int ft_pwd(void)
// {
//     char buf[PATH_MAX];
//     if (getcwd(buf, sizeof(buf)))
//         printf("%s\n", buf);
//     else
//     {
//         perror("minishell: pwd");
//         return 1;
//     }
//     return 0;
// }

// int ft_export(char **argv, t_env **env)
// {
//     int status = 0;
//     int i = 1;

//     if (!argv[1]) { env_print(*env); return 0; }

//     while (argv[i])
//     {
//         char *eq = strchr(argv[i], '=');
//         if (eq)
//         {
//             size_t klen = (size_t)(eq - argv[i]);
//             char *k = ms_strndup(argv[i], klen);
//             char *v = ft_strdup(eq + 1);
//             if (!k || !v)
//             {
//                 free(k); free(v);
//                 puterr("minishell: export: ", "malloc failed", "\n");
//                 status = 1;
//             }
//             else if (!is_valid_identifier(k))
//             {
//                 puterr("minishell: export: `", argv[i], "': not a valid identifier\n");
//                 status = 1;
//             }
//             else if (env_set(env, k, v)) status = 1;
//             free(k); free(v);
//         }
//         else
//         {
//             if (!is_valid_identifier(argv[i]))
//             {
//                 puterr("minishell: export: `", argv[i], "': not a valid identifier\n");
//                 status = 1;
//             }
//             else if (env_set(env, argv[i], env_get(*env, argv[i]))) status = 1;
//         }
//         i++;
//     }
//     return status;
// }

// int ft_unset(char **argv, t_env **env)
// {
//     int status = 0;
//     int i = 1;

//     while (argv[i])
//     {
//         if (!is_valid_identifier(argv[i]))
//         {
//             puterr("minishell: unset: `", argv[i], "': not a valid identifier\n");
//             status = 1;
//         }
//         else env_unset(env, argv[i]);
//         i++;
//     }
//     return status;
// }

// int ft_env(t_env *env)
// {
//     env_print(env);
//     return 0;
// }

// int ft_exit(char **argv, int *should_exit)
// {
//     long long code_ll = 0;

//     *should_exit = 1;
//     if (!argv[1])
//         return 0; 
//     if (!parse_ll(argv[1], &code_ll))
//     {
//         puterr("minishell: exit: ", argv[1], ": numeric argument required\n");
//         return 2;
//     }
//     if (argv[2])
//     {
//         puterr("minishell: exit: ", "too many arguments", "\n");
//         *should_exit = 0;
//         return 1;
//     }
//     return (int)(unsigned char)code_ll;
// }

int is_builtin(const char *cmd)
{
    if (!cmd) return 0;
    return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") ||
    !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export") ||
    !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env") ||
    !ft_strcmp(cmd, "exit"));
}

int exec_builtin(char **args, t_env *env)
{
    if (!args || !args[0])
        return (0);
    if (ft_strcmp(args[0], "echo") == 0)
        return ft_echo(args);
    else if (ft_strcmp(args[0], "cd") == 0)
        return ft_cd(args, env);
    else if (ft_strcmp(args[0], "pwd") == 0)
        return ft_pwd();
    else if (ft_strcmp(args[0], "export") == 0)
        return ft_export(args, env);
    else if (ft_strcmp(args[0], "unset") == 0)
        return ft_unset(args, env);
    else if (ft_strcmp(args[0], "env") == 0)
        return ft_env(env);
    else if (ft_strcmp(args[0], "exit") == 0)
        return ft_exit(args);
    return (0); //LOOP_RUN?
}
