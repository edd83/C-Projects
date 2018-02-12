/*
** objdump.c for objdump in /home/lardet_e/TP/nm-objdump/objdump
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Mar 12 23:28:19 2014 lardet
** Last update Fri Mar 14 18:40:09 2014 lardet
*/

#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>
#include "objdump.h"

void			my_objdump(char *filename)
{
  void			*data;
  Elf32_Ehdr		*elf;
  int			fd;
  long			size;

  if (xaccess(filename) == -1)
    return ;
  if ((fd = xopen(filename)) == -1)
    return ;
  if ((size = lseek(fd, 0, SEEK_END)) == -1)
    {
      fprintf(stderr, "error: lseek: %s\n", strerror(errno));
      return ;
    }
  if ((data = xmmap(fd, filename, size)) == MAP_FAILED)
    return ;
  elf = (Elf32_Ehdr*)data;
  if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    objdp32_format(data, filename, size);
  else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    objdp64_format(data, filename, size);
  if (close(fd) == -1)
    fprintf(stderr, "error: close: %s\n", strerror(errno));
  if (munmap(data, size) == -1)
    fprintf(stderr, "error: munmap: %s\n", strerror(errno));
}

int			main(int ac, char **av)
{
  int			i;

  if (ac > 1)
    {
      i = 0;
      while (++i < ac)
	my_objdump(av[i]);
    }
  else
    my_objdump("./my_objdump");
  return (1);
}
