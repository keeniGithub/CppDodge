#ifndef GAME
#define GAME

#include <InSDL.hpp>
#include <var.hpp>
#include <bind.hpp>
#include <attack.hpp>
#include <save.hpp>

void init_attack_timer() {
    srand(static_cast<unsigned>(time(0)));
    attack_timer = rand() % 12 + 5;
    attack_elapsed = 0;
}

void init(){
    myapp.init(1200, 600, name, true);

    texture icon(myapp.Render, path+"image/icon.png");
    myapp.setIcon(icon);

    set_position();
    load(max_count);
    bind_movement();
    bind_button();
    bind_menu();
    init_attack_timer();
}

void reset(){
    current_count = 0;
    attack = "";
    attack_counter = 0;
    die = false;
    playanim = false;
    player.setPosition(x_pl, y_pl);
    laser_right.setSize(0, 0);
    laser_left.setSize(0, 0);
}

#endif