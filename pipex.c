/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:46:08 by akliek            #+#    #+#             */
/*   Updated: 2021/08/19 11:47:54 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(char **argv, char **envp, int *fd)
{
	int		out;
	int		ex;
	char	**cmd;
	char	*path;

	waitpid(0, NULL, 0);
	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (access(argv[1 ], F_OK) == -1)
		exit(0);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(out, 1);
	cmd = ft_split(argv[3], ' ');
	path = get_path(cmd[0], envp);
	ex = execve(path, cmd, envp);
	clean_str(path);
	clean_str_arr(cmd);
	if (ex == -1)
	{
		perror("Error: wft does your command mean???");
		exit(0);
	}
}

static void	child_process(char **argv, char **envp, int *fd)
{
	int		in;
	int		ex;
	char	**cmd;
	char	*path;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
	{
		perror("Error: can't open file");
		exit(0);
	}
	dup2(in, 0);
	cmd = ft_split(argv[2], ' ');
	path = get_path(cmd[0], envp);
	ex = execve(path, cmd, envp);
	clean_str(path);
	clean_str_arr(cmd);
	if (ex == -1)
	{
		perror("Error: wft does your command mean???");
		exit(0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];

	if (argc != 5)
	{
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");
		return (0);
	}
	if (pipe(fd) == -1)
	{
		perror("Error: can't create pipe");
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error: can't create fork");
		return (-1);
	}
	if (pid == 0)
		child_process(argv, envp, fd);
	else
		parent_process(argv, envp, fd);
	return (0);
}
