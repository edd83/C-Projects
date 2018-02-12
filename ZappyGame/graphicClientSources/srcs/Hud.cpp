
#include "../headers/Hud.hh"

Hud::Hud():
	_width(WINDOW_WIDTH), _height(30), _level(""), _unity(""), _team(""), _name(""), _msg(""), _drawInventory(false)
{
	loadOneBitmap(FOOD, "images/food.png");
	loadOneBitmap(LINEMATE, "images/linemate.png");
	loadOneBitmap(DERAUMERE, "images/deraumere.png");
	loadOneBitmap(SIBUR, "images/sibur.png");
	loadOneBitmap(MENDIANE, "images/mendiane.png");
	loadOneBitmap(PHIRAS, "images/phiras.png");
	loadOneBitmap(THYSTAME, "images/thystame.png");
}

Hud::~Hud()
{
}

void Hud::loadOneBitmap(objectType type, const char *file)
{
	sf::Texture *texture = new sf::Texture();
	sf::Sprite *sprite;
	if (texture->loadFromFile(file))
	{
		texture->setSmooth(true);
		sprite = new sf::Sprite();
		sprite->setTexture(*texture);
		objectSprites[type] = sprite;
	}
	else
	{
		std::cerr << "Error : bitmap non loaded." << std::endl;
		exit(0);
	}
}

void Hud::setPositionSprite()
{
	objectSprites[FOOD]->setPosition(50, 0);
	objectSprites[LINEMATE]->setPosition(210, 0);
	objectSprites[DERAUMERE]->setPosition(390, 0);
	objectSprites[SIBUR]->setPosition(520, 0);
	objectSprites[MENDIANE]->setPosition(_width / 2 + 60, 0);
	objectSprites[PHIRAS]->setPosition(_width / 2 + 210, 0);
	objectSprites[THYSTAME]->setPosition(_width / 2 + 390, 0);

}

void Hud::drawText(const sf::Font &font, sf::RenderWindow &window) const
{
	sf::Text	nourriture("food :" + _food, font, 17);
	sf::Text	linemate("linemate :" + _linemate, font, 17);
	sf::Text	deraumere("deraumere :" + _deraumere, font, 17);
	sf::Text	sibur("sibur :" + _sibur, font, 17);
	sf::Text	mendiane("mendiane :" + _mendiane , font, 17);
	sf::Text	phiras("phiras :" + _phiras, font, 17);
	sf::Text	thystame("thystame :" + _thystame,  font, 17);
	sf::Text	level("level :" + _level, font, 17);
	sf::Text	unite("speed :", font, 17);
	sf::Text	value(_unity, font, 17);
	sf::Text	team("team :" + _team, font, 17);
	sf::Text  	message("Player "+ _name + "\tsays : " + _msg, font, 17);

	nourriture.setPosition(10, 3);
	linemate.setPosition(140, 3);
	deraumere.setPosition(300, 3);
	sibur.setPosition(480, 3);
	mendiane.setPosition(630, 3);
	phiras.setPosition(800, 3);
	thystame.setPosition(950, 3);
	level.setPosition(1150, 3);
	unite.setPosition(10, WINDOW_LENGTH - 28);
	value.setPosition(80, WINDOW_LENGTH - 28);
	team.setPosition(180, WINDOW_LENGTH - 28);
	message.setPosition(WINDOW_WIDTH / 2 - 250, WINDOW_LENGTH - 28);

	nourriture.setColor(sf::Color(0, 0, 0));
	linemate.setColor(sf::Color(0, 0, 0));
	deraumere.setColor(sf::Color(0, 0, 0));
	sibur.setColor(sf::Color(0, 0, 0));
	mendiane.setColor(sf::Color(0, 0, 0));
	phiras.setColor(sf::Color(0, 0, 0));
	thystame.setColor(sf::Color(0, 0, 0));
	level.setColor(sf::Color(0, 0, 0));
	unite.setColor(sf::Color(0, 0, 0));
	value.setColor(sf::Color(0, 0, 0));
	team.setColor(sf::Color(0, 0, 0));
	message.setColor(sf::Color(0, 0, 0));

	window.draw(nourriture);
	window.draw(linemate);
	window.draw(deraumere);
	window.draw(sibur);
	window.draw(mendiane);
	window.draw(phiras);
	window.draw(thystame);
	window.draw(level);
	window.draw(unite);
	window.draw(value);
	window.draw(team);
	window.draw(message);
}

void	Hud::drawInventory(const sf::Font &font, sf::RenderWindow &window) const
{
	sf::Text	nb_food(_inventaires[0], font, 17);
	sf::Text	nb_linemate(_inventaires[1], font, 17);
	sf::Text	nb_deraumere(_inventaires[2], font, 17);
	sf::Text	nb_sibur(_inventaires[3], font, 17);
	sf::Text	nb_mendiane(_inventaires[4] , font, 17);
	sf::Text	nb_phiras(_inventaires[5], font, 17);
	sf::Text	nb_thystame(_inventaires[6], font, 17);
	sf::Text	nbLevel(_level, font, 17);
	sf::Text	team(_team, font, 17);

	nb_food.setPosition(90, 3);
	nb_linemate.setPosition(260, 3);
	nb_deraumere.setPosition(440, 3);
	nb_sibur.setPosition(570, 3);
	nb_mendiane.setPosition(750, 3);
	nb_phiras.setPosition(900, 3);
	nb_thystame.setPosition(1080, 3);
	nbLevel.setPosition(1217, 3);
	team.setPosition(250, WINDOW_LENGTH - 28);

	nb_food.setColor(sf::Color(0, 0, 0));
	nb_linemate.setColor(sf::Color(0, 0, 0));
	nb_deraumere.setColor(sf::Color(0, 0, 0));
	nb_sibur.setColor(sf::Color(0, 0, 0));
	nb_mendiane.setColor(sf::Color(0, 0, 0));
	nb_phiras.setColor(sf::Color(0, 0, 0));
	nb_thystame.setColor(sf::Color(0, 0, 0));
	nbLevel.setColor(sf::Color(0, 0,0));
	team.setColor(sf::Color(0, 0, 0));

	window.draw(nb_food);
	window.draw(nb_linemate);
	window.draw(nb_deraumere);
	window.draw(nb_sibur);
	window.draw(nb_mendiane);
	window.draw(nb_phiras);
	window.draw(nb_thystame);
	window.draw(nbLevel);
	window.draw(team);
}

void Hud::draw(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(_width, _height));
	sf::RectangleShape littleInfo(sf::Vector2f(_width, 30));
	sf::Font			font;


	if (!font.loadFromFile("images/visitor1.ttf"))
	{
		std::cerr << "error loading .tff for font" << std::endl;
		return ;
	}
	rectangle.setFillColor(sf::Color(200, 200, 200));
	rectangle.setPosition(0, 0);

	littleInfo.setFillColor(sf::Color(200, 200, 200));
	littleInfo.setPosition(0, WINDOW_LENGTH - 30);

	setPositionSprite();
	window.draw(rectangle);
	window.draw(littleInfo);
	window.draw(*(objectSprites[FOOD]));
	window.draw(*(objectSprites[LINEMATE]));
	window.draw(*(objectSprites[DERAUMERE]));
	window.draw(*(objectSprites[SIBUR]));
	window.draw(*(objectSprites[MENDIANE]));
	window.draw(*(objectSprites[PHIRAS]));
	window.draw(*(objectSprites[THYSTAME]));
	drawText(font, window);
	if (_drawInventory == true)
		drawInventory(font, window);
}

// void	Hud::fillInventory(const std::vector<std::string> & arg)
// {
// 	unsigned int i = 4;
// 	unsigned int j = 0;

// 	if (_inventaires.size() == 0)
// 	{
// 		while (i < arg.size())
// 		{
// 			_inventaires.push_back(arg[i]);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (i < arg.size())
// 			_inventaires[j++] = arg[i++];
// 	}
// 	_drawInventory = true;
// }

void	Hud::setLevel(const std::string & level)
{
	_level = level;
}

void	Hud::setTeam(const std::string & team)
{
	_team = team;
}

void	Hud::setUnity(const std::string & unity)
{
	_unity = unity;
}

void	Hud::setName(const std::string & name)
{
	_name = name;
}

void	Hud::setMsg(const std::string &msg)
{
	_msg = msg;
}

void	Hud::setRes(const std::string &food, const std::string &linemate, const std::string &deraumere, const std::string &sibur, const std::string &mendiane, const std::string &phiras, const std::string & thystame)
{
  this->_food = food;
  this->_linemate = linemate;
  this->_deraumere = deraumere;
  this->_sibur = sibur;
  this->_mendiane = mendiane;
  this->_phiras = phiras;
  this->_thystame = thystame;
}
