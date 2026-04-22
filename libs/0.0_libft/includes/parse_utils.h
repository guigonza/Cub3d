/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:18:24 by rdrevar           #+#    #+#             */
/*   Updated: 2026/04/21 19:37:49 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>


char		**ft_split_quote(char const *s, char c);
char		*ft_strndup_trim_quote(const char *start, size_t len);
size_t		ft_strlen_quote(const char *s, char delimiter);

int			ft_strtol(const char *str, long *out);
double		ft_strtod(const char *str, char **endptr);

int			ft_valid_int(const char *str);
char		*ft_utoa_base(uintmax_t number, const char *base);

#endif
