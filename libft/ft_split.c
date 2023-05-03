/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hujeong <hujeong@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/14 10:06:59 by jaejkim		   #+#	#+#			 */
/*   Updated: 2023/05/02 20:10:03 by hujeong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == c)
			++i;
		else
		{
			while (s[i] != c && s[i])
				++i;
			++word;
		}
	}
	return (word);
}

static char	*save_str(char *str, char c, int letter, int i)
{
	char	*strs;

	while (str[i] && str[i] != '\n')
	{
		if (str[i] == c)
			++i;
		else
		{
			++letter;
			++i;
			if (str[i] == c)
				break ;
		}
	}
	strs = (char *)malloc(sizeof(char) * letter + 1);
	if (strs == NULL)
		return (0);
	strs[letter] = '\0';
	while (letter >= 1)
		strs[--letter] = str[--i];
	return (strs);
}

static char	*move_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == c)
			++i;
		else
		{
			++i;
			if (str[i] == c)
				break ;
		}	
	}
	return (&str[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	int		word;
	int		i;

	str = (char *)s;
	word = count_word(str, c);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (strs == 0)
		return (0);
	i = -1;
	while (++i < word)
	{		
		strs[i] = save_str(str, c, 0, 0);
		if (strs[i] == 0)
		{
			while (i >= 0)
				free(strs[i--]);
			free(strs);
			return (0);
		}
		str = move_str(str, c);
	}
	strs[i] = NULL;
	return (strs);
}