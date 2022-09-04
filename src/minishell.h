/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:49:57 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/04 16:46:55 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <string.h>
/*
**  Definitions
*/

# define MS_ERR_PIPE              "Error: Wrong pipes.\n"
# define MS_ERR_EMPTY             "Error: Empty command.\n"
# define MS_ERR_SYNTAX            "Error: Syntax error.\n"
# define MS_ERR_AMB_REDIR         "Error: Ambiguous redirection.\n"
# define MS_ERR_IS_DIR            "Error: Is a directory.\n"
# define MS_ERR_CMD_NOT_FOUND     "Error: Command not found.\n"
# define MS_ERR_FILE_O_DIR_NEXIST "Error: Don't exist file or directory.\n"
# define MS_PERM_DENY             "Error: Permission denied.\n"

# define TOKEN_EMPTY     0x00001
# define TOKEN_SINPUT    0x00002
# define TOKEN_DINPUT    0x00004
# define TOKEN_SOUTPUT   0x00008
# define TOKEN_DOUTPUT   0x00010
# define TOKEN_SOR       0x00020
# define TOKEN_DOR       0x00040
# define TOKEN_SAND      0x00080
# define TOKEN_DAND      0x00100
# define TOKEN_END       0x00200
# define TOKEN_TEXT      0x00400
# define TOKEN_SQUOTE    0x00800
# define TOKEN_DQUOTE    0x01000
# define TOKEN_QUOTES    0x01800
# define TOKEN_OPERATOR  0x003FE
# define TOKEN_CSQUOTE   0x02000
# define TOKEN_CDQUOTE   0x04000
# define TOKEN_LOCKED    0x06000
# define TOKEN_AINPUT    0x00006
# define TOKEN_AOUTPUT   0x00018
# define TOKEN_IO        0x0001E
# define TOKEN_EXPANDED  0x08000

# define FD_RD 0
# define FD_WR 1

/*
**  Enumerations
*/

/*
**  Structures
*/

typedef struct s_delim
{
	char	chr;
	void	(*f)(t_list **, char *);
}	t_delim;

typedef struct s_token
{
	struct s_list	*node;
	char			*start;
	int				flags;
}	t_token;

/*
	la estructura t_command
		contiene dos listas una del comando y sus argumentos (argv)
		la otra la lista de redirecciones (redir)
comando válido | comando válido

definición de comando válido

'texto(cmd) texto(argv)' < texto < texto > texto << texto >> texto
*/

typedef struct s_command
{
	t_list	*argv;
	t_list	*redir;
	pid_t	pid;
	int		fd[2];
	int		pipe_side;
	int		fd_in;
	int		fd_out;
	int		result;
	t_list	*node;
}			t_command;

typedef struct s_key_value_var
{
	void	*key;
	void	*value;
}	t_key_value_var;

typedef struct s_env_node
{
	char				*name;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_minishell
{
	char				*error;
	int					exit_status;
	int					last_exit_status;
	int					pipes;
	char				*cmd_str;
	int					heredoc_fd;
	struct s_list		*tk;
	struct s_list		*delim;
	struct s_env_node	*env;
	struct s_list		*cmd_lst;
}	t_minishell;

typedef struct s_exp_quotes
{
	int	d_index;
	int	s_index;
}		t_exp_quotes;

typedef struct s_write_quotes
{
	char	*str;
	int		index;
	char	*name_var_env;
	char	*value;
}		t_write_quotes;

typedef struct s_expansion
{
	char					*str;
	int						index;
	char					*aux;
	int						dcomillas;
	int						scomillas;
	char					*name_var_env;
	char					*value;
	struct s_exp_quotes		quotes;
	struct s_write_quotes	dquote;
}		t_expansion;

typedef struct s_builtin
{
	char					*pwd;
	char					*oldpwd;
	char					*user;
	char					*home;
	char					*path;
	struct s_command		*cmd;
}		t_builtin;

typedef struct s_export
{
	char					*name_1;
	char					*name_2;
	char					**str;
	char					*aux;
	int						length;
	int						index;
	char					*name;
	int						check;
	struct s_command		*cmd;
}		t_export;

/*
**  Information
*/

t_minishell		*gs_info(void);

/*
	Exit Functions
*/

void			exit_controlled(int status);

/*
**  Environment Functions
*/

t_key_value_var	*get_env_key_value(char *str);
void			parse_env(char **env);
char			*get_env_var(char *key);
void			set_env_var(char *key, char *value);
t_env_node		*add_env_entry(t_key_value_var *kv);
void			add_env_var(char *key, char *value);
char			**get_env_array(void);
void			remove_env_entry(char *key);
int				get_env_size(void);

/*
**  Cleaning Functions
*/

void			clean_all(void);
void			destroy_env(void);

/*
**  Prompt Functions
*/

void			get_cmd(void);

/*
**	Parser Functions
*/

char			*parse_argv(char *str);
char			**get_argv(char *str);

/*
	New Parser Functions
*/

void			parse_cmd(char *str);
t_delim			*new_delim(char chr, void (*f)(t_list **, char *));
t_list			*new_delim_node(char chr, void (*f)(t_list **, char *));
t_token			*new_token(int flags);
t_list			*new_token_node(int flags);
void			insert_token_and_move(t_list **token_lst, int flags);
void			delim_space(t_list **token_lst, char *str);
void			delim_default(t_list **token_lst, char **str);
void			delim_end(t_list **token_lst, char *str);
void			delim_or(t_list **token_lst, char *str);
void			delim_input(t_list **token_lst, char *str);
void			delim_output(t_list **token_lst, char *str);
void			delim_generic1(t_list **token_lst, char *str, int sflag);
void			delim_generic2(t_list **token_lst, char *str,
					int sflag, int dflag);
void			init_delims(void);
void			set_token_flag_isempty(t_token *token, int flags);
void			set_token_flag_if(t_token *token, int flags, int flag_cond);
void			set_token_start(t_token *token, char *str);
t_list			*get_tokens(char *str);
void			do_delimiter(t_list **token_lst, t_list *delim_lst, char **str);
void			check_token_quotes(t_token *token, char chr);
void			delim_and(t_list **token_lst, char *str);
void			delim_free(void);

/*
	Lexer Functions
*/

t_command		*new_command(void);
t_list			*new_command_node(void);
void			free_command_lst(t_list **cmd_lst);
t_list			*lexer(void);
int				check_consistence(t_list **command_lst);
t_list			*get_commands(t_list *tokens_lst);
void			expanse_vars(t_list *cmd_lst, t_env_node *env);
char			*do_expanse(char *str, char *start, char *end);
char			*remove_quotes(char *str, int expandable);
void			split_expanded_token(t_list *token_lst, char **exp);
t_command		*get_next_command(t_command *cmd);

/*
	Expander Functions
*/

char			**get_expanded_string(t_expansion *exp);
void			fill(t_expansion *exp);
void			correction(char *str);
void			quotes(t_expansion *exp);
void			write_dcomillas(t_expansion *exp);
void			get_name_var_env(t_expansion *exp);
void			get_var_env(t_expansion *exp);
void			write_scomillas(t_expansion *exp);
void			write_without_comillas(t_expansion *exp);
void			copy_to_expand(t_expansion *exp);
void			copy_to_expand_exit(t_expansion *exp);
void			var_env_replace_digit(t_expansion *exp);
void			var_env_replace_alpha(t_expansion *exp);
void			question_mark(t_expansion *exp);
char			*ft_strjoin_v2(char *s1, char *s2);
char			*ft_strdup_v2(char *str);

/*
	Executor Functions
*/

char			*add_path_to_cmd(char *path, char *cmd);
int				execute_cmd(t_list *cmd_lst, t_env_node *env_lst);
char			**get_array_from_token_lst(t_list *token_lst);
char			*find_command(char *cmd);
t_command		*find_cmd_by_pid(t_command *head, int pid);
t_command		*get_last_command(t_list *cmd_lst);
int				execute(int fd_in, t_command *cmd);
void			get_redirections(t_command *cmd);
void			connect_redirections(int fd_in, t_command *cmd);
int				is_directory(char *dir);
void			get_heredoc(t_command *cmd, t_token *token);
t_command		*get_exit_next_command(t_command *cmd);
void			connect_cmds_pipe(t_command *prev, t_command *cmd1,
					t_command *cmd2);
void			wait_cmds(int n, int last_pid);
void			father_close_fds(int fd_in, t_command *cmd);
void			check_redirecction_errors(int fd, char *filename);
void			execute_heredocs(t_command *cmd);

/*
	Builtin Functions
*/

int				is_builtin(char *name);
int				execute_builtin(int fd_in, char *name, t_command *cmd);
void			do_builtin_fork(int fd_in, t_command *cmd,
					void (*f)(t_command *cmd));
void			do_builtin_with_prefork(int fd_in, t_command *cmd,
					void (*pf)(t_command *cmd),	void (*f)(t_command *cmd));
void			do_builtin_with_postfork(int fd_in, t_command *cmd,
					void (*pf)(t_command *cmd),	void (*f)(t_command *cmd));
void			builtin_pwd(t_command *cmd);
void			builtin_exit(t_command *cmd);
void			builtin_pre_exit(t_command *cmd);
void			builtin_echo(t_command *cmd);
void			builtin_cd(t_command *cmd);
void			builtin_post_cd(t_command *cmd);
void			builtin_env(t_command *cmd);
void			builtin_pre_unset(t_command *cmd);
void			builtin_unset(t_command *cmd);
void			builtin_pre_export(t_command *cmd);
void			builtin_export(t_command *cmd);
void			builtin_pre_export(t_command *cmd);
void			builtin_export_burbuja(void);
void			builtin_export_var(char **argv);
int				get_index(const char *str, int c);
void			get_name_var_to_export(t_export *export, char *str);
void			check_name_var_to_export(t_export *export);
void			get_value_var_to_export(t_export *export, char *str);
size_t			ft_strmaxlen(const char *s1, const char *s2);

/*
	Print Functions
*/

void			print_tokens(void *content);

/*
	Error Functions
*/

void			show_error(t_command *cmd, char *filename);
void			err_cmd_not_found(t_command *cmd);
void			err_file_dir_not_found(t_command *cmd, char *filename);
void			err_permission_deny(t_command *cmd, char *filename);

/*
	Signal Functions
*/

void			init_main_signals(void);
void			disable_main_signals(void);
void			on_father_signal(int signo);

#endif
