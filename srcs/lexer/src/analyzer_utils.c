/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:05:13 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/20 01:44:48 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyzer.h"

//=== get_current_state =================================
int	get_current_state(t_list *token)
{
	int	type;

	type = get_token_type(token);
	if (state_operator(token) == OPERATOR)
		return (OPERATOR);
	if (state_redir(token) == REDIR)
		return (REDIR);
	if (type == CLOSE_PARENTHESIS || type == OPEN_PARENTHESIS)
		return (type);
	if (type == DOUBLE_QUOTES || type == SINGLE_QUOTES)
		return (type);
	if (type == SEMICOLON)
		return (type);
	return (STRING);
}

//=== parse_error =======================================
int	parse_error(int prev_state, int state, t_list *token, int eq_point)
{
	char	*msg;

	msg = NULL;
	if ((prev_state == START && state == OPERATOR)
		|| (prev_state == OPERATOR && state == OPERATOR)
		|| (prev_state == CLOSE_PARENTHESIS && state == STRING)
		|| (prev_state == OPEN_PARENTHESIS && state == OPERATOR)
		|| (prev_state == OPERATOR && state == CLOSE_PARENTHESIS)
		|| (prev_state == OPEN_PARENTHESIS && state == CLOSE_PARENTHESIS)
		|| (prev_state == CLOSE_PARENTHESIS && state == OPEN_PARENTHESIS)
		|| (prev_state == REDIR && state == REDIR)
		|| (prev_state == REDIR && state == OPERATOR)
		|| (eq_point < 0))
		msg = get_token_name(token);
	if ((prev_state == STRING && state == OPEN_PARENTHESIS)
		|| (!token->next && state == REDIR))
	{
		msg = get_token_name(token->next);
		if (!msg)
			msg = "newline";
	}
	if (msg)
	{
		ft_putstr_fd(PARSE_ERROR_MSG, 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("'\n", 2);
	}
	return (PARSE_ERROR * !(!msg));
}

//=== complete_tokens ===================================
t_list	*complete_tokens(int eq_point, t_list *token)
{
	int	type;
	t_list	*tokens;

	tokens = NULL;
	type = get_token_type(token);
	if (type == SINGLE_QUOTES || type == DOUBLE_QUOTES)
		quote_prompt(token);
	if (type == PIPE || type == AND || type == OR)
		ft_lastadd_back(&tokens, operator_prompt(type));
	if (eq_point > 0)
		ft_lst_add_back(&tokens, subsh_prompt(eq_point));
	return (tokens);
}
