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
    x_sp = 0;
    die = false;
    playanim = false;
    rocket_attack_avalible = true;
    laser_attack_avalible = true;
    saw_attack_avalible = true;
    pipe_attack_avalible = true;
    spiky_attack_avalible = true;
    rocket_counter = 0;
    laser_counter = 0;
    saw_counter = 0;
    pipe_counter = 0;
    spiky_counter = 0;
    active_attacks = 0;
    player.setPosition(x_pl, y_pl);
    rocket.setPosition(x_rkt, -100);
    laser_left.setX(x_pf + 10);
    laser_right.setX((x_pf + platform.getWidth() - laser_right.getWidth()) - 10);
    laser_left.setHeight(0);
    laser_right.setHeight(0);
    saw_left.setPosition(x_sw, y_sw);
    saw_right.setPosition(x_sw + platform.getWidth(), y_sw);
    warning_left.setY(y_wrn);
    warning_right.setY(y_wrn);
    pipe.setPosition(x_pp, -150);
    blob.setPosition(x_bl, -36);
    spiky.setY(-170);
}

#endif