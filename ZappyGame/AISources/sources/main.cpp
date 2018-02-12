//
// main.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 12:35:17 2014 ovoyan_s
// Last update Sat Jul 12 13:01:08 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"main.hh"

int			main(int ac, char **av)
{
  try
    {
      if (ac == 5 || ac == 7)
	Client		trentonianClient(av);
      else
	std::cout << "USAGE :" << std::endl
		  << "        [-n team name]" << std::endl
		  << "        [-p port]" << std::endl
		  << "        [-h hostname]" << std::endl;
    }
  catch (const std::exception &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  return (0);
}
