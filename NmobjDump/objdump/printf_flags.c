/*
** printf_flags.c for printf_flags in /home/lardet_e/TP/nm-objdump
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Tue Mar 11 23:45:28 2014 lardet
** Last update Sat Mar 15 12:39:22 2014 lardet
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "objdump.h"
#include "flags.h"

void	print_flags_addr64(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
  int		i;
  unsigned int	res;

  i = -1;
  res = 0;
  if (elf->e_type == ET_EXEC)
    res += EXEC_P;
  if (elf->e_type == ET_DYN)
    res += DYNAMIC;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	res += HAS_SYMS;
      if (shdr[i].sh_type == SHT_RELA && elf->e_type == ET_REL)
	res += HAS_RELOC;
      if (shdr[i].sh_type == SHT_HASH)
	res += D_PAGED;
    }
  printf("0x%08x:\n", res);
}

void	print_flags_addr32(Elf32_Ehdr *elf, Elf32_Shdr *shdr)
{
  int		i;
  unsigned int	res;

  i = -1;
  res = 0;
  if (elf->e_type == ET_EXEC)
    res += EXEC_P;
  if (elf->e_type == ET_DYN)
    res += DYNAMIC;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	res += HAS_SYMS;
      if (shdr[i].sh_type == SHT_RELA && elf->e_type == ET_REL)
	res += HAS_RELOC;
      if (shdr[i].sh_type == SHT_HASH)
	res += D_PAGED;
    }
  printf("0x%08x:\n", res);
}

void     print_flags64(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
  int   i;

  i = -1;
  if (elf->e_type == ET_EXEC)
    printf("%s, ", "EXEC_P");
  if (elf->e_type == ET_DYN)
    printf("%s, ", "DYNAMIC");
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	printf("%s", "HAS_SYMS");
      if (shdr[i].sh_type == SHT_RELA && elf->e_type == ET_REL)
	printf("%s, ", "HAS_RELOC");
      if (shdr[i].sh_type == SHT_HASH)
	printf("%s, ", "D_PAGED");
    }
  printf("\n");
}

void     print_flags32(Elf32_Ehdr *elf, Elf32_Shdr *shdr)
{
  int   i;

  i = -1;
  if (elf->e_type == ET_EXEC)
    printf("%s, ", "EXEC_P");
  if (elf->e_type == ET_DYN)
    printf("%s, ", "DYNAMIC");
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
        printf("%s", "HAS_SYMS");
      if (shdr[i].sh_type == SHT_RELA && elf->e_type == ET_REL)
	printf("%s, ", "HAS_RELOC");
      if (shdr[i].sh_type == SHT_HASH)
        printf("%s, ", "D_PAGED");
    }
  printf("\n");
}
