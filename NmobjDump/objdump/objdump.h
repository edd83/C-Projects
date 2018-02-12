/*
** objdump.h for objdump in /home/catuss_a//Desktop/nmobjdump
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Sun Mar 13 21:53:28 2011 axel catusse
** Last update Fri Mar 14 19:29:49 2014 lardet
*/

#ifndef _OBJDUMP_H_
# define _OBJDUMP_H_

#include <elf.h>

int			xaccess(char *filename);
int			xopen(char *filename);
void			*xmmap(int fd, char * filename, unsigned int size);

void			objdp32_format(void *data, char *filename, int size);
void			objdp64_format(void *data, char *filename, int size);
void			print_flags32(Elf32_Ehdr *elf, Elf32_Shdr *shdr);
void			print_flags64(Elf64_Ehdr *elf, Elf64_Shdr *shdr);
int			check_elf_file32(Elf32_Ehdr *elf, int size, Elf32_Shdr *shdr);
int			check_elf_file64(Elf64_Ehdr *elf, int size, Elf64_Shdr *shdr);
void			print_flags_addr64(Elf64_Ehdr *elf, Elf64_Shdr *shdr);
void			print_flags_addr32(Elf32_Ehdr *elf, Elf32_Shdr *shdr);

#endif /* !_OBJDUMP_H_ */
