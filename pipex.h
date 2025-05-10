/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:05:54 by loruzqui          #+#    #+#             */
/*   Updated: 2025/05/07 12:51:11 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define COLOR_USERS "\033[38;2;84;222;253m"
# define COLOR_RESET "\033[0m"

typedef struct s_parser
{
	char				**args;
	struct s_parser		*next;
}	t_parser;

typedef struct s_data
{
	t_parser	*commands;
	char		*infile;
	char		*outfile;
	int			num_commands;
	char		**envp;
	char		*delim;
}	t_data;

////**************** GET PATH
void		ft_find_path(t_data *data);

////**************** MANAGE NODES PARSER
t_parser	*ft_new_node(char **command);
void		ft_add_node(t_parser **head, t_parser *node);

////**************** UTILS
void		ft_free_split(char **split);
int			ft_parserlen(t_parser *parser);
void		ft_print_commands(t_parser *head);

////**************** EXEC COMMANDS
void		ft_exec_pipes(t_data *data);
void		ft_exec_child(int i, int ***array_pipes, t_data *data);

////**************** FILES & HEREDOC
void		ft_manage_infile(t_data *data);
void		ft_manage_outfile(t_data *data);
int			ft_manage_heredoc(t_data *data);

////**************** FREES
void		ft_free_parser(t_parser *parser);
void		ft_free_data(t_data *data);

#endif
