//
// Parsing.cpp for Parsing in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun 30 16:04:09 2014 volpe
// Last update Mon Jul 21 11:46:40 2014 volpe
//

/*
msz = taille map
sgt = unité de temps
bct = contenu d'une case "X Y x1, x2, x3, ..." x = qté de ressource
tna = nom équipe
pnw = position joeuur "id X Y orientation niveau nom_equipe
enw = position des oeufs "id id_joueur X Y"
*/

#include	"../headers/Parsing.hh"

Parsing::Parsing()
{
  this->_fct[0] = &Parsing::setMapSize;
  this->_fct[1] = &Parsing::setCaseContent;
  this->_fct[2] = &Parsing::setTeamName;
  this->_fct[3] = &Parsing::setPlayer;
  this->_fct[4] = &Parsing::setPosPlayer;
  this->_fct[5] = &Parsing::setLvlPlayer;
  this->_fct[6] = &Parsing::setInvPlayer;
  this->_fct[7] = &Parsing::brcPlayer;
  this->_fct[8] = &Parsing::startIncant;
  this->_fct[9] = &Parsing::endIncant;
  this->_fct[10] = &Parsing::createEgg;
  this->_fct[11] = &Parsing::throwRes;
  this->_fct[12] = &Parsing::takeRes;
  this->_fct[13] = &Parsing::playerDie;
  this->_fct[14] = &Parsing::setEgg;
  this->_fct[15] = &Parsing::hatchingEgg;
  this->_fct[16] = &Parsing::playerConnect;
  this->_fct[17] = &Parsing::eggDie;
  this->_fct[18] = &Parsing::setTimeUnit;
  this->_fct[19] = &Parsing::endGame;
  this->_fct[20] = &Parsing::msgSrv;
  this->_fct[21] = &Parsing::udkCmd;
  this->_fct[22] = &Parsing::wrParam;
  this->_fct[23] = &Parsing::expulsePlayer;
  
  this->_cmd[0] = "msz";
  this->_cmd[1] = "bct";
  this->_cmd[2] = "tna";
  this->_cmd[3] = "pnw";
  this->_cmd[4] = "ppo";
  this->_cmd[5] = "plv";
  this->_cmd[6] = "pin";
  this->_cmd[7] = "pbc";
  this->_cmd[8] = "pic";
  this->_cmd[9] = "pie";
  this->_cmd[10] = "pfk";
  this->_cmd[11] = "pdr";
  this->_cmd[12] = "pgt";
  this->_cmd[13] = "pdi";
  this->_cmd[14] = "enw";
  this->_cmd[15] = "eht";
  this->_cmd[16] = "ebo";
  this->_cmd[17] = "edi";
  this->_cmd[18] = "sgt";
  this->_cmd[19] = "seg";
  this->_cmd[20] = "smg";
  this->_cmd[21] = "suc";
  this->_cmd[22] = "sbp";
  this->_cmd[23] = "pex";
}

Parsing::~Parsing()
{
}

void		Parsing::execute(std::string message, GraphClient &Game)
{
  int	i = 0;
  
  while (i < 24 && message.compare(0, 3, this->_cmd[i]))
    i++;
  if (i <= 23)
    (this->*_fct[i])(message, Game);
  else
    throw ParserException("Wrong syntax : Command not found");
}

void		Parsing::setMapSize(std::string content, GraphClient &Game)
{
  int		i = 4;
  int		j = 0;
  const char	*msg = content.c_str();
  char		x[10];
  char		y[10];
  bool		ok = true;

  if (content.length() < 7)
    throw ParserException("Wrong syntax : Bad map size arguments");
  while (j < 10)
    {
      x[j] = 0;
      y[j] = 0;
      j++;
    }
  j = 0;
  while (msg[i])
    {
      if (msg[i] == ' ')
	{
	  ok = false;
	  j = 0;
	}
      if (ok == true)
	{
	  x[j] = msg[i];
	  j++;
	}
      else if (msg[i] != ' ' && msg[i] != '\n' && ok == false)
	{
	  y[j] = msg[i];
	  j++;
	}
      i++;
    }
  Game.getMap().setWidth(atoi(x));
  Game.getMap().setLength(atoi(y));
  Game.getMap().create();
}

void		Parsing::setTimeUnit(std::string content, GraphClient &Game)
{
  int		j = -1;
  char		res[content.length()];
  const char	*msg = content.c_str();

  if (content.length() < 6)
    throw ParserException("Wrong Syntax : Bad time unit arguments");
  for (int i = 4; i < static_cast<int>(content.length()) - 1; i++)
    res[++j] = msg[i];
  Game.setTimeUnit(atoi(res));
}

void		Parsing::setCaseContent(std::string content, GraphClient &Game)
{
  std::string			delimeter = " ";
  std::string			token;
  std::list<int>		listToken;
  size_t			pos = 0;
  bool				ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	listToken.push_back(atoi(token.c_str()));
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if ((pos = content.find("\n")) != std::string::npos)
    {
      token = content.substr(0, pos);
      listToken.push_back(atoi(token.c_str()));
    }
  if (listToken.size() != 9)
    throw ParserException("Wrong syntax for bct : Usage : \"bct X Y q q q q q q q\\n\"");
  Game.getMap().setCaseContent(listToken);
}

void		Parsing::cleanBuffer(char *buffer, int length)
{
  for (int i = 0; i <= length; i++)
    buffer[i] = 0;
}

void		Parsing::setTeamName(std::string teamName, GraphClient &Game)
{
  int		i;
  int		j = -1;
  char		res[teamName.length()];
  const char	*msg = teamName.c_str();

  this->cleanBuffer(res, teamName.length());
  for (i = 4; i < static_cast<int>(teamName.length()) - 1; i++)
    res[++j] = msg[i];
  if (i == 4)
    throw ParserException("Wrong syntax for tna ! Usage : \"tna [team name]\\n\"");
  Game.getListTeam().push_back(new Team(res));
}

void		Parsing::setPlayer(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (listToken.size() != 5)
    throw ParserException("Wrong syntax for pnw ! Usage : \"pnw #n X Y O L N\\n\"");
  Trentonian	*player= new Trentonian();
  std::list<int>::iterator	it = listToken.begin();
  player->setId((*it));
  std::cout << "id=" << *it << std::endl;
  it++;
  player->setX((*it));
  std::cout << "X=" << *it << std::endl;
  it++;
  player->setY((*it));
  std::cout << "Y=" << *it << std::endl;
  it++;
  player->setDir((*it));
  std::cout << "Dir=" << *it << std::endl;
  it++;
  player->setLevel((*it));
  std::cout << "Level=" << *it << std::endl;
  player->setTeamName(content);
  std::cout << "team:" << content << std::endl;
  Game.getListPlayer().push_back(player);
}

void		Parsing::setEgg(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 4)
    throw ParserException("Wrong syntax for enw ! Usage : \"enw #e #n X Y\\n\"");
  Game.addEgg(listToken);
}

void		Parsing::setPosPlayer(std::string content, GraphClient &Game)
{  
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 4)
    throw ParserException("Wrong syntax for ppo ! Usage : \"ppo #n X Y O\\n\"");
  Game.updatePlayer(listToken);
}

void		Parsing::setLvlPlayer(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 2)
    throw ParserException("Wrong syntax for plv ! Usage : \"plv #n L\\n\"");
  Game.updateLevelPlayer(listToken);  
}

void		Parsing::setInvPlayer(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 10)
    throw ParserException("Wrong syntax for pin ! Usage : \"pin #n X Y q q q q q q q \\n\"");
  Game.updateInventoryPlayer(listToken);  
}

void		Parsing::brcPlayer(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

 while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for bpc ! Usage : \"bpc #n M \\n\"");
  Game.updateMsgPlayer(listToken, content);  

}

void		Parsing::startIncant(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() < 4)
    throw ParserException("Wrong syntax for pic ! Usage : \"pic X Y L #n #n ...\\n\"");
  Game.startCast(listToken);    
}

void		Parsing::endIncant(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 3)
    throw ParserException("Wrong syntax for pie ! Usage : \"pie X Y R \\n\"");
  Game.endCast(listToken);
}

void		Parsing::createEgg(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for pfk ! Usage : \"pfk #n\\n\"");
  Game.addEgg(listToken);
}

void		Parsing::throwRes(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 2)
    throw ParserException("Wrong syntax for pdr ! Usage : \"pdr #n i\\n\"");
  Game.updateSquare(listToken);
}

void		Parsing::takeRes(std::string content, GraphClient &Game)
{
  std::string	        delimeter = " ";
  std::string		token;
  std::list<int>	listToken;
  size_t		pos = 0;
  bool			ok = false;

  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
	{
	  if (token.find("#") != std::string::npos)
	    token.erase(0, 1);
	  listToken.push_back(atoi(token.c_str()));
	}
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 2)
    throw ParserException("Wrong syntax for pgt ! Usage : \"pgt #n i\\n\"");
  Game.playerPickupRessource(listToken);
}

void            Parsing::playerDie(std::string content, GraphClient &Game)
{  std::string           delimeter = " ";
  std::string           token;
  std::list<int>        listToken;
  size_t                pos = 0;
  bool                  ok = false;
 
  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
        {
          if (token.find("#") != std::string::npos)
            token.erase(0, 1);
          listToken.push_back(atoi(token.c_str()));
        }
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for pdi ! Usage : \"pdi #n\\n\"");
  Game.playerDie(listToken);
}

void		Parsing::hatchingEgg(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  std::list<int>        listToken;
  size_t                pos = 0;
  bool                  ok = false;
 
  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
        {
          if (token.find("#") != std::string::npos)
            token.erase(0, 1);
          listToken.push_back(atoi(token.c_str()));
        }
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for eht ! Usage : \"eht #e\\n\"");
  Game.hatchingEgg(listToken);
}

void		Parsing::playerConnect(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  std::list<int>        listToken;
  size_t                pos = 0;
  bool                  ok = false;
 
  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
        {
          if (token.find("#") != std::string::npos)
            token.erase(0, 1);
          listToken.push_back(atoi(token.c_str()));
        }
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for ebo ! Usage : \"ebo #e\\n\"");
  Game.playerConnect(listToken);
}

void		Parsing::eggDie(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  std::list<int>        listToken;
  size_t                pos = 0;
  bool                  ok = false;
 
  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
        {
          if (token.find("#") != std::string::npos)
            token.erase(0, 1);
          listToken.push_back(atoi(token.c_str()));
        }
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for edi ! Usage : \"edi #e\\n\"");
  Game.eggDie(listToken);
}

void            Parsing::endGame(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  size_t                pos = 0;

  if ((pos = content.find(delimeter)) != std::string::npos)
    content.erase(0, pos + delimeter.length());
  Game.putWinner(content);
}

void            Parsing::msgSrv(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  size_t                pos = 0;

  if ((pos = content.find(delimeter)) != std::string::npos)
    content.erase(0, pos + delimeter.length());
  Game.putSrvMsg(content);
}

void		Parsing::udkCmd(std::string content, GraphClient &Game)
{
  (void)Game;
  (void)content;
  std::cout << "Unknow Command !" << std::endl;
}

void		Parsing::wrParam(std::string content, GraphClient &Game)
{
  (void)Game;
  (void)content;
  std::cout << "Wrong Parameter" << std::endl;
}

void		Parsing::expulsePlayer(std::string content, GraphClient &Game)
{
  std::string           delimeter = " ";
  std::string           token;
  std::list<int>        listToken;
  size_t                pos = 0;
  bool                  ok = false;
 
  while ((pos = content.find(delimeter)) != std::string::npos)
    {
      token = content.substr(0, pos);
      if (ok == true)
        {
          if (token.find("#") != std::string::npos)
            token.erase(0, 1);
          listToken.push_back(atoi(token.c_str()));
        }
      content.erase(0, pos + delimeter.length());
      ok = true;
    }
  if (content.find("#") != std::string::npos)
    content.erase(0, 1);
  listToken.push_back(atoi(content.c_str()));
  if (listToken.size() != 1)
    throw ParserException("Wrong syntax for pex ! Usage : \"pex #n\\n\"");
  Game.playerExpulse(listToken);
}
