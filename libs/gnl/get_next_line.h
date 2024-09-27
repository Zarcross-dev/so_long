/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:13:58 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/27 15:36:10 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *line, char *buff);
size_t	ft_strlen(const char *s);
char	*line_reader(int fd, char *line);
char	*line_extractor(char *line);
char	*line_remover(char *line);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);

#endif //GET_NEXT_LINE_H
