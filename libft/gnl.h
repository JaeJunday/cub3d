/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   gnl.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hujeong <hujeong@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/02 20:06:29 by hujeong		   #+#	#+#			 */
/*   Updated: 2023/05/02 20:06:46 by hujeong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define READ 1
# define NO 0

# include <sys/types.h>

char	*get_next_line(int fd);
int		read_check(char *store);
char	*read_loop(char **store, ssize_t *store_size, int fd, char *buff);
char	*get_one_line(char **store, ssize_t *st_size);
char	*line_store(char **store, ssize_t *st_size, char *buf, ssize_t rd_size);
char	*make_oneline(char **store, ssize_t *st_size);
void	trim_store(char **store, ssize_t *st_size, ssize_t i, ssize_t j);

#endif