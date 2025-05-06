#ifndef ANIM
#define ANIM

#include <InSDL.hpp>
#include <var.hpp>
#include <game.hpp>

void handle_die(){
    if (
        player.onTouch(lava) 
        || check_border(player, myapp)
        || player.onTouch(rocket)
        || player.onTouch(laser_left)
        || player.onTouch(laser_right)
        || player.onTouch(saw_left)
        || player.onTouch(saw_right)
        || player.onTouch(blob)
        || player.onTouch(spiky)
       ) 
        die = true;

    if (die) {
        playanim = true;

        if (degr < 180) degr += 9;

        if (anim_y < 100) {
            anim_y += 10;
            player.subY(17);
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