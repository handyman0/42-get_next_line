/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelo-do <lmelo-do@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:14:24 by lmelo-do          #+#    #+#             */
/*   Updated: 2025/07/29 15:25:29 by lmelo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_and_store(int fd, char *resto);
char	*ft_extract_line(char *resto);
char	*ft_update_line(char *resto);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
