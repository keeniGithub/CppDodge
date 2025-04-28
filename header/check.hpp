#ifndef CHECK
#define CHECK

#include <InSDL.hpp>

bool check_border(frect player, app myapp) {
    return player.getX() < 0 || player.getX() + player.getWidth() > myapp.window.width ||
           player.getY() < 0 || player.getY() + player.getHeight() > myapp.window.height;
}

#endif