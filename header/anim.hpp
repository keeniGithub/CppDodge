#ifndef ANIM
#define ANIM

#include <InSDL.hpp>
#include <var.hpp>
#include <game.hpp>

void anim_die(){
    if (die) {
        playanim = true;

        if (degr < 180) degr += 9;

        if (anim_y < 100) {
            anim_y += 10;
            player.subY(20);
        } if (anim_y == 100 && anim_y_back != 100) {
            anim_y_back += 5;
            player.addY(5);
        } if (degr == 180 && anim_y == 100 && anim_y_back == 100) {
            playanim = false;
            degr = 0;
            anim_y = 0;
            anim_y_back = 0;
        }

        if (!playanim){
            reset();
            death_count++;
        }
    }
}

#endif