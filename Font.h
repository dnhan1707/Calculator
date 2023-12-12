//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_FONT_H
#define SFML_PROJECT_FONT_H

#include "SFML/Graphics.hpp"
#include <map>
#include "FontEnum.h"

class Font : public sf::Drawable
{
private:

    inline static std::map<FontEnum, sf::Font > fonts;
    static std::string  getPath(FontEnum font);
    static void loadfont(FontEnum font);

public:
    static sf::Font& getFont(FontEnum fontEnum);
};


#endif //SFML_PROJECT_FONT_H
