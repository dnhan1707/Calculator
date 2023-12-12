//
// Created by ASUS on 11/14/2023.
//

#include "Font.h"

std::string Font::getPath(FontEnum font) {
    switch (font) {
        case ARIAL:
            return "Fonts/arial.ttf";

        case STARMONK:
            return "Fonts/STARMONK.TTF";

        case OPEN_SANS:
            return "Fonts/OpenSans-Bold.ttf";
    }
}

void Font::loadfont(FontEnum font)
{
    fonts[font].loadFromFile(getPath(font));
}

sf::Font& Font::getFont(FontEnum font)
{
    loadfont(font);
    return fonts[font];
}
