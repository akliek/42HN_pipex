/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:36:21 by akliek            #+#    #+#             */
/*   Updated: 2021/08/19 12:07:19 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	int		exist;
	char	**path;
	char	*res;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	envp[i] += 5;
	path = ft_split(envp[i], ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		exist = access(path[i], F_OK);
		if (exist == 0)
		{
			res = ft_strdup(path[i]);
			clean_str_arr(path);
			return (res);
		}
		i++;
	}
	return (NULL);
}
