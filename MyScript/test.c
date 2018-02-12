/*
** test.c for testpty in /home/lardet_e/rendu/PSU_2013_myscript
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sun Mar  2 23:35:43 2014 lardet
** Last update Sun Mar  2 23:37:27 2014 lardet
*/

#define _XOPEN_SOURCE 600

#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define __USE_BSD

#include <termios.h>

int main(void)
{
  int  fdm, fds, rc;
  char input[150];

  system("ls -l /dev/pts");
  fdm = open("/dev/ptmx", O_RDWR | O_NOCTTY);
  if (fdm < 0)
    {
      fprintf(stderr, "Erreur %d sur posix_openpt()\n", errno);
      return 1;
    }
  rc = grantpt(fdm);
  if (rc != 0)
    {
      fprintf(stderr, "Erreur %d sur grantpt()\n", errno);
      return 1;
    }
  rc = unlockpt(fdm);
  if (rc != 0)
    {
      fprintf(stderr, "Erreur %d sur unlockpt()\n", errno);
      return 1;
    }

  fds = open(ptsname(fdm), O_RDWR);

  if (fork())
    {
      close(fds);
      while (1)
	{
	  write(1, "Entree : ", sizeof("Entree : "));
	  rc = read(0, input, sizeof(input));
	  if (rc > 0)
	    {
	      write(fdm, input, rc);
	      rc = read(fdm, input, sizeof(input) - 1);
	      if (rc > 0)
		{
		  input[rc] = '\0';
		  fprintf(stderr, "%s", input);
		}
	      else
		{
		  break;
		}
	    }
	  else
	    {
	      break;
	    }
	}
    }
  else
    {
      struct termios slave_orig_term_settings;
      struct termios new_term_settings;

      close(fdm);

      rc = tcgetattr(fds, &slave_orig_term_settings);

      new_term_settings = slave_orig_term_settings;
      cfmakeraw (&new_term_settings);
      tcsetattr (fds, TCSANOW, &new_term_settings);

      close(0);
      close(1);
      close(2);
      dup(fds);
      dup(fds);
      dup(fds);
      while (1)
	{
	  rc = read(fds, input, sizeof(input) - 1);
	  if (rc > 0)
	    {
	      input[rc - 1] = '\0';
	      printf("Le fils a recu : '%s'\n", input);
	    }
	  else
	    {
	      break;
	    }
	}
    }
  return 0;
}
