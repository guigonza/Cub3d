/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:50:50 by rdrevar           #+#    #+#             */
/*   Updated: 2025/06/09 13:50:55 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*----------GET_NEXT_LINE------------*/
char	*get_next_line(int fd);

#endif
