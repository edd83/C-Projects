/*
** print_sym64.c for print_sym64 in /home/lardet_e/TP/nm-objdump/nm
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Mar 14 14:28:11 2014 lardet
** Last update Sat Mar 15 11:22:15 2014 lardet
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

static Elf64_Sym	**get_symtab_cpy(Elf64_Sym *symtab,
					 unsigned int size)
{
  Elf64_Sym		**new;
  unsigned int		i;

  new = malloc(sizeof(*new) * (size + 1));
  i = -1;
  while (++i < size)
    new[i] = &symtab[i];
  return (new);
}

void			print_sym64(Elf64_Shdr *symsection,
				    Elf64_Sym *symtab,
				    char *strsymtab,
				    Elf64_Shdr *shdr)
{
  unsigned int		i;
  unsigned int		size;
  Elf64_Sym		**symtab_cpy;

  (void)shdr;
  size = symsection->sh_size / sizeof(*symtab);
  if ((symtab_cpy = get_symtab_cpy(symtab, size)) == NULL)
    {
      fprintf(stderr, "error: malloc: failed.\n");
      return ;
    }
  i = - 1;
  while (++i < size)
    if (strsymtab[symtab_cpy[i]->st_name] != 0)
      {
	printf(" %016x ", 0);
	printf("%c ", 'U');
	printf(" %s\n", &strsymtab[symtab_cpy[i]->st_name]);
      }
  free(symtab_cpy);
}
