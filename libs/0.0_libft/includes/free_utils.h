/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:15:23 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/17 18:15:26 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "list.h"

void		ft_free_array(void **arr, int size);
void		ft_free_str_array(char **arr);
void		ft_free_lst(t_list **lst);

#endif
