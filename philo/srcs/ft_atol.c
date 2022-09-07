/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:09:43 by jayoon            #+#    #+#             */
/*   Updated: 2022/09/07 16:36:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

static void	init_utils(ssize_t *p_result, int *p_sign, int *p_flag)
{
	*p_result = 0;
	*p_sign = 1;
	*p_flag = 0;
}

static const char	*pass_space(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static const char	*check_sign(const char *str, int *p_sign)
{
	if (ft_issign(*str))
	{
		if (*str == '-')
			*p_sign = -1;
		if (!ft_isdigit(*(str + 1)))
			return (NULL);
		str++;
	}
	return (str);
}

static int	do_atol(const char *str, ssize_t *p_result, size_t len)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (!ft_isdigit(*str) || len > 10)
		{
			flag = 1;
			break ;
		}
		*p_result = 10 * *p_result + *str - '0';
		str++;
		len++;
	}
	return (flag);
}

ssize_t	ft_atol(const char *str)
{
	ssize_t	result;
	size_t	len;
	int		sign;
	int		flag;

	if (!str)
		return (0);
	init_utils(&result, &sign, &flag);
	len = 0;
	str = pass_space(str);
	str = check_sign(str, &sign);
	if (str == NULL)
		return (-1);
	flag = do_atol(str, &result, len);
	if (flag != 0)
		return (-1);
	if (result > (ssize_t)INT_MAX)
		return ((ssize_t)INT_MAX + 1);
	return ((ssize_t)sign * result);
}
