/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanse_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:31:34 by aparolar          #+#    #+#             */
/*   Updated: 2022/09/05 17:15:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	get_expansion_var(t_token *token, t_expansion *exp)
{
	exp->str = token->start;
	exp->index = 0;
	exp->name_var_env = NULL;
	exp->value = NULL;
	exp->quotes.d_index = 0;
	exp->quotes.s_index = 0;
	exp->dquote.str = NULL;
}

static void	do_expanse_vars(t_token *token)
{
	char		*tmp;
	char		**arr;
	t_expansion	exp;

	tmp = token->start;
	get_expansion_var(token, &exp);
	arr = get_expanded_string(&exp);
	if (ft_array_count(arr) > 1
		&& token->flags & (TOKEN_AOUTPUT | TOKEN_SINPUT))
	{
		gs_info()->error = MS_ERR_AMB_REDIR;
		ft_array_free(arr);
	}
	else
		split_expanded_token(token->node, arr);
}

static void	on_expanse_token(void *content)
{
	t_token	*token;

	if (gs_info()->error)
		return ;
	token = content;
	if (token->flags & TOKEN_TEXT && !(token->flags & TOKEN_EXPANDED)
		&& !(token->flags & TOKEN_DINPUT))
		do_expanse_vars(token);
}

static void	on_cmd(void *content)
{
	ft_lstiter(((t_command *)content)->argv, on_expanse_token);
	ft_lstiter(((t_command *)content)->redir, on_expanse_token);
}

void	expanse_vars(t_list *cmd_lst, t_env_node *env)
{
	(void)env;
	ft_lstiter(cmd_lst, on_cmd);
}
