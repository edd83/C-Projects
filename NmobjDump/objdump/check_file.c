/*
** check_file.c for check_file in /home/lardet_e/TP/nm-objdump/objdump
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Mar 14 19:27:09 2014 lardet
** Last update Fri Mar 14 19:35:56 2014 lardet
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "objdump.h"

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

int	check_elf_file32(Elf32_Ehdr *elf, int size, Elf32_Shdr *shdr)
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
