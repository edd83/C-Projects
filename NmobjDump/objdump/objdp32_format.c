/*
** objdp32_format.c for objdp32_format in /home/lardet_e/TP/nm-objdump/objdump
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed Mar 12 23:28:41 2014 lardet
** Last update Fri Mar 14 19:33:25 2014 lardet
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "objdump.h"

int		check_elf_format32(Elf32_Ehdr *elf, char *path)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0
      || elf->e_ident[EI_MAG1] != ELFMAG1
      || elf->e_ident[EI_MAG2] != ELFMAG2
      || elf->e_ident[EI_MAG3] != ELFMAG3
      || (elf->e_type != ET_EXEC && elf->e_type
	  != ET_REL && elf->e_type != ET_DYN))
    {
      fprintf(stderr, "objdump: %s: File format not recognized\n", path);
      return (-1);
    }
  return (1);
}

void			print_ascii32(unsigned int j,
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

void			print_sect32(char *strtab,
				     Elf32_Ehdr *elf,
				     Elf32_Shdr *shdr,
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
	print_ascii32(j, &z, w, (char*)w);
    }
}

void			print_section32(char *strtab,
					Elf32_Ehdr *elf,
					Elf32_Shdr *shdr)
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
	  print_sect32(strtab, elf, shdr, i);
	}
    }
}

void			objdp32_format(void *data, char *filename, int size)
{
  Elf32_Ehdr		*elf;
  Elf32_Shdr		*shdr;
  char			*strtab;

  elf = (Elf32_Ehdr*)data;
  if (check_elf_format32(elf, filename) == -1)
    return ;
  shdr = (Elf32_Shdr*)(data + elf->e_shoff);
  if (check_elf_file32(elf, size, shdr) == -1)
    return ;
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:%5cfile format\n", filename, ' ');
  printf("architecture: %s, flags ",
	 elf->e_machine == 3 ? "i386" : "notf");
  print_flags_addr32(elf, shdr);
  print_flags32(elf, shdr);
  printf("start address 0x%08x\n\n", elf->e_entry);
  print_section32(strtab, elf, shdr);
}
