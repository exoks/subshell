/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:44:14 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/20 01:45:17 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZER_H
# define ANALYZER_H

# include "lexer.h"
# include "readline/readline.h"
# include "libft.h"

# define PARSE_ERROR_MSG "minishell: syntax error near unexpected token `"
# define PARSE_ERROR	 258

/*====================================================================*\
|     Prompts :                                                        |
\*====================================================================*/
# define SUBSH_PROMPT		"subsh> "
# define PIPE_PROMPT		"pipe> "
# define AND_PROMPT			"cmdand> "
# define OR_PROMPT			"cmdor> "
# define QUOTE_PROMPT		"quote> "
# define DQUOTE_PROMPT		"dquote> "

/*====================================================================*\
|     Analyzer:                                                        |
\*====================================================================*/
t_list	*analyzer(t_list *tokens);

void	update_data(int *data, int cur_state);
int		parse_error(int prev_state, int state, t_list *token, int eq_point);
t_list	*complete_tokens(int eq_point, t_list *token);

/*====================================================================*\
|     Subtokens:                                                       |
\*====================================================================*/
t_list	*subsh_prompt(int eq_point);
t_list	*operator_prompt(int type);
t_list	*quote_prompt(t_list *token);
char	*get_prompt(int type);

/*====================================================================*\
|     STATES :                                                         |
\*====================================================================*/
int		get_current_state(t_list *token);
int		state_operator(t_list *token);
int		state_redir(t_list *token);

#endif
