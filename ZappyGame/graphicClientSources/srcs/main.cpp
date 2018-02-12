//
// main.cpp for main in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/SFML
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun 23 17:35:52 2014 volpe
// Last update Sun Jul 13 13:46:17 2014 volpe
//

#include	"../headers/Client.hh"

int	main(int argc, char **argv)
{
  try
    {
      if (argc == 5)
	Client	        zappyGraphic(argv);
      else
	std::cout << "USAGE :" << std::endl
		  << "        [-p port]" << std::endl
		  << "        [-h hostname]" << std::endl;
    }
  catch (const std::exception &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  return (0);

  return (0);
}
