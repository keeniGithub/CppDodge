#ifndef PHYSIC
#define PHYSIC

#include <InSDL.hpp>
#include <var.hpp>

void handle_jump() {
    if (jumped && !is_jump) {
        jump_speed = jump_force;
        is_jump = true;
    }

    if (is_jump) {
        player.addY(jump_speed);
        jump_speed += gravity * 0.1f;
    }

    if (player.onTouch(platform)) {
        is_jump = false;
        jumped = false;
        jump_speed = 0;
    } else {
        player.addY(gravity);
    }
}

void handle_dash() {
    myapp.bindKey(SDL_SCANCODE_LSHIFT, [&]() {
        if (dash_available && !dash_in_progress) {
            dash_in_progress = true;
            dash_speed = facing_right ? -30.0f : 30.0f;
            dash_target_x = player.getX() + (facing_right ? -300 : 300);
            dash_available = false;
            dash_cooldown_time = SDL_GetTicks();
        }
    }, [](){});

    if (dash_in_progress) {
        int current_x = player.getX();
        if ((dash_speed > 0 && current_x < dash_target_x) || (dash_speed < 0 && current_x > dash_target_x)) {
            player.addX(dash_speed);
        } else {
            dash_in_progress = false;
        }
    }

    unsigned int current_time = SDL_GetTicks();
    if (current_time - last_time >= 1000) {
        current_count++;
        last_time = current_time;
    }
    if (!dash_available && current_time - dash_cooldown_time >= 1500)
        dash_available = true;
}
#endif