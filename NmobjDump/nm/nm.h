/*
** nm.h for nm in /home/lardet_e/TP/nm-objdump/nm
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Mar 14 14:29:19 2014 lardet
** Last update Sat Mar 15 11:06:18 2014 lardet
*/

#ifndef _NM_H_
# define _NM_H_

#include <elf.h>

int			xaccess(char *filename);
int			xopen(char *filename);
void			*xmmap(int fd, char * filename, unsigned int size);

void			elf64_format(void *data, char *filename, int ac, int size);
void			print_sym64(Elf64_Shdr *symsection,
				  Elf64_Sym *symtab,
				  char *strsymtab,
				  Elf64_Shdr *shdr);

#endif /* !_NM_H_ */
