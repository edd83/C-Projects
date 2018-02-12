/*
** elf64_format.c for elf64_format in /home/lardet_e/TP/nm-objdump/nm
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Mar 14 14:28:43 2014 lardet
** Last update Sat Mar 15 11:06:16 2014 lardet
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nm.h"

int	check_elf_file64(Elf64_Ehdr *elf, int size, Elf64_Shdr *shdr)
{
  int			i;

  i = -1;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_offset > (unsigned int)size)
	{
	  fprintf(stderr, "objdump : File truncated\n");
	  return (-1);
	}
    }
  return (1);
}

Elf64_Shdr	*set_sym_tab(Elf64_Shdr **strsymsection,
				     char *strtab,
				     Elf64_Ehdr *elf,
				     Elf64_Shdr *shdr)
{
  int			i;
  Elf64_Shdr		*symsection;

  symsection = NULL;
  *strsymsection = NULL;
  i = -1;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_size)
	{
	  if (!strcmp(&strtab[shdr[i].sh_name], ".symtab"))
	    symsection = (Elf64_Shdr*)&shdr[i];
	  if (!strcmp(&strtab[shdr[i].sh_name], ".strtab"))
	    *strsymsection = (Elf64_Shdr*)&shdr[i];
	}
    }
  return (symsection);
}

int		check_elf_format(Elf64_Ehdr *elf, char *path)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0
      || elf->e_ident[EI_MAG1] != ELFMAG1
      || elf->e_ident[EI_MAG2] != ELFMAG2
      || elf->e_ident[EI_MAG3] != ELFMAG3
      || (elf->e_type != ET_EXEC && elf->e_type
	  != ET_REL && elf->e_type != ET_DYN))
    {
      fprintf(stderr, "nm: %s: File format not recognized\n", path);
      return (-1);
    }
  return (1);
}

void			elf64_format(void *data, char *filename,
				     int ac, int size)
{
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  Elf64_Sym		*symtab;
  Elf64_Shdr		*strsymsection;
  Elf64_Shdr		*symsection;
  char			*strsymtab;
  char			*strtab;

  elf = (Elf64_Ehdr*)data;
  if (check_elf_format(elf, filename) == -1)
    return ;
  shdr = (Elf64_Shdr*)(data + elf->e_shoff);
  if (check_elf_file64(elf, size, shdr) == -1)
    return ;
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  symsection = set_sym_tab(&strsymsection, strtab, elf, shdr);
  if (ac > 2)
    printf("\n%s:\n", filename);
  if (strsymsection == NULL || symsection == NULL)
    {
      fprintf(stderr, "nm: %s: no symbols\n", filename);
      return ;
    }
  symtab = (Elf64_Sym*)((char*)data + symsection->sh_offset);
  strsymtab = (char*)((char*)data + strsymsection->sh_offset);
  print_sym64(symsection, symtab, strsymtab, shdr);
}
