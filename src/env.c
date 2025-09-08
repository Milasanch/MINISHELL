/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:20:58 by milagros          #+#    #+#             */
/*   Updated: 2025/09/08 02:42:06 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static t_env *env_new(const char *key, const char *val)
// {
//     t_env *n = (t_env *)malloc(sizeof(t_env));
//     if (!n) return NULL;
//     n->key = ft_strdup(key);
//     n->val = val ? ft_strdup(val) : NULL;
//     n->next = NULL;
//     if (!n->key || (val && !n->val))
//     {
//         free(n->key);
//         free(n->val);
//         free(n);
//         return NULL;
//     }
//     return n;
// }


// static void env_push_back(t_env **env, t_env *node)
// {
//     t_env *it;
//     if (!*env) 
//     { 
//         *env = node; 
//         return; 
//     }
//     it = *env; while (it->next) it = it->next; it->next = node;
// }


// static void split_kv(const char *s, char **out_k, char **out_v)
// {
//     const char *eq = strchr(s, '=');
//     if (eq)
//     {
//         *out_k = strndup(s, (size_t)(eq - s));
//         *out_v = ft_strdup(eq + 1);
//     }
//     else
//     {
//         *out_k = ft_strdup(s);
//         *out_v = NULL;
//     }
// }


// void env_free(t_env **env)
// {
//     t_env *n, *tmp;
//     if (!env) return;
//     n = *env;
//     while (n)
//     {
//         tmp = n->next;
//         free(n->key);
//         free(n->val);
//         free(n);
//         n = tmp;
//     }
//     *env = NULL;
// }


// t_env *env_from_environ(char **environ)
// {
//     t_env *env = NULL;
//     char *k;
//     char *v;
//     for (int i = 0; environ && environ[i]; ++i)
//     {
//         k = NULL;
//         v = NULL;
//         split_kv(environ[i], &k, &v);
//         if (!k) continue;
//         t_env *n = env_new(k, v);
//         free(k);
//         free(v);
//         if (!n) { env_free(&env); return NULL; }
//         env_push_back(&env, n);
//     }
//     return env;
// }

// char *env_get(t_env *env, const char *key)
// {
//     while (env)
//     {
//         if (ft_strcmp(env->key, key) == 0)
//         return env->val;
//         env = env->next;
//     }
//     return NULL;
// }


// int env_set(t_env **env, const char *key, const char *val)
// {
//     t_env *it = *env;
//     while (it)
//     { 
//        if (ft_strcmp(it->key, key) == 0)
//      {
//         char *nv = val ? ft_strdup(val) : NULL;
//             if (val && !nv) return 1;
//             free(it->val); it->val = nv; return 0;
//         }
//         it = it->next;
//     }
//     t_env *n = env_new(key, val);
//     if (!n) return 1;
//     env_push_back(env, n);
//     return 0;
// }


// int env_unset(t_env **env, const char *key)
// {
//     t_env *it = *env, *prev = NULL;
//     while (it)
//     {
//         if (ft_strcmp(it->key, key) == 0)
//         {
//             if (prev) prev->next = it->next; else *env = it->next;
//             free(it->key); free(it->val); free(it);
//             return 0;
//         }
//     prev = it; it = it->next;
//     }
// return 0;
// }


// void env_print(t_env *env)
// {
//     while (env)
//     {
//         if (env->val)
//         printf("%s=%s\n", env->key, env->val);
//         env = env->next;
//     }
// }