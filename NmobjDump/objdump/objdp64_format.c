/*
** objdp64_format.c for objdp64_format in /home/lardet_e/TP/nm-objdump/objdump
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Mar 12 23:30:14 2014 lardet
** Last update Sat Mar 15 12:39:43 2014 lardet
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "objdump.h"

int		check_elf_format64(Elf64_Ehdr *elf, char *path)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0
      || elf->e_ident[EI_MAG1] != ELFMAG1
      || elf->e_ident[EI_MAG2] != ELFMAG2
      || elf->e_ident[EI_MAG3] != ELFMAG3
      || (elf->e_type != ET_EXEC && elf->e_type
	  != ET_REL && elf->e_type != ET_DYN))
    {
      fprintf(stderr, "objdump %s: File format not recognized\n", path);
      return (-1);
    }
  return (1);
}

void			print_ascii64(unsigned int j,
				      unsigned int *z,
				      unsigned char *w,
				      char *t)
{
  int			x;

  x = j;
  while (x % 16 != 0)
    {
      if (x % 4 == 0 && x % 16)
	printf(" ");
      printf("  ");
      ++x;
    }
  printf("  ");
  while (*z < j)
    {
      if (isprint(w[*z]))
	printf("%c", t[*z]);
      else
	printf(".");
      (*z)++;
    }
  while ((*z)++ % 16 != 0)
    printf(" ");
  *z = j;
  printf("\n");
}

void			print_sect64(char *strtab,
				     Elf64_Ehdr *elf,
				     Elf64_Shdr *shdr,
				     int i)
{
  unsigned char		*w;
  unsigned int		j;
  int			addr;
  unsigned int		z;

  addr = shdr[i].sh_addr;
  printf("Contents of section %s:\n", &strtab[shdr[i].sh_name]);
  w = (unsigned char*)((char*)elf + shdr[i].sh_offset);
  j = 0;
  z = 0;
  while (j < shdr[i].sh_size)
    {
      if (j % 16 == 0)
	printf(" %04x ", addr);
      printf("%02x", w[j++]);
      if (j % 4 == 0 && j % 16 && j < shdr[i].sh_size)
	printf(" ");
      if (j % 16 == 0)
	addr += 16;
      if (j % 16 == 0 || j >= shdr[i].sh_size)
	print_ascii64(j, &z, w, (char*)w);
    }
}

void			print_section64(char *strtab,
					Elf64_Ehdr *elf,
					Elf64_Shdr *shdr)
{
  int			i;

  i = -1;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_size
	  && strcmp(&strtab[shdr[i].sh_name], ".strtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".symtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".shstrtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".bss"))
      	{
	  print_sect64(strtab, elf, shdr, i);
	}
    }
}

void			objdp64_format(void *data, char *filename, int size)
{
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  char			*strtab;

  elf = (Elf64_Ehdr*)data;
  if (check_elf_format64(elf, filename) == -1)
    return ;
  shdr = (Elf64_Shdr*)(data + elf->e_shoff);
  if (check_elf_file64(elf, size, shdr) == -1)
    return ;
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format elf64-x86-64\n", filename, ' ');
  printf("architecture: %s, flags ",
	 elf->e_machine == 0x3e ? "i386:x86-64" : "notf");
  print_flags_addr64(elf, shdr);
  print_flags64(elf, shdr);
  printf("start address 0x%016x\n\n", (int)elf->e_entry);
  print_section64(strtab, elf, shdr);
}
