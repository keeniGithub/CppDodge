#include <InSDL.hpp>
#include <var.hpp>
#include <cstring>

int main()
{
    app myapp;
    myapp.init(1200, 600, name, true);

    texture icon(myapp.Render, path+"image/icon.png");
    myapp.setIcon(icon);

    frect background(0, 0, 1200, 800);
    texture t_bg(myapp.Render, path+"image/bg.png");

    frect counter(0, 30, 25, 50);
    text t_ct(myapp.Render, "0", myapp.font);

    frect max_counter(0, 70, 25, 50);
    text t_mct(myapp.Render, "0", myapp.font, 158, 228, 255);

    frect platform(0, 0, 600, 150);
    texture t_pf(myapp.Render, path+"image/platform.png");

    frect player(0, 0, 60, 60);
    texture t_pl(myapp.Render, path+"image/rambo.png");
    SDL_FPoint point_pl = {player.getWidth()/2, player.getHeight()/2};

    myapp.bindKey(SDL_SCANCODE_A, [&]() { moved_left = true; facing_right = true; });
    myapp.bindKey(SDL_SCANCODE_D, [&]() { moved_right = true; facing_right = false; });
    myapp.bindKey(SDL_SCANCODE_W, [&]() { if (!is_jump) jumped = true; });
    myapp.bindKey(SDL_SCANCODE_SPACE, [&]() { if (!is_jump) jumped = true; });

    myapp.bindKey(SDL_SCANCODE_LSHIFT, [&]() {
        if (dash_available && !dash_in_progress) {
            dash_in_progress = true;
            dash_speed = facing_right ? -30.0f : 30.0f;
            dash_target_x = player.getX() + (facing_right ? -300 : 300);
            dash_available = false;
            dash_cooldown_time = SDL_GetTicks();
        }
    });

    myapp.bindKeyUp(SDL_SCANCODE_A, [&]() { moved_left = false; });
    myapp.bindKeyUp(SDL_SCANCODE_D, [&]() { moved_right = false; });
    myapp.bindKeyUp(SDL_SCANCODE_W, [&]() { if (is_jump) jumped = false; });
    myapp.bindKeyUp(SDL_SCANCODE_SPACE, [&]() { if (is_jump) jumped = false; });

    int x_pf = (myapp.window.width - platform.getWidth()) / 2;
    int y_pf = (myapp.window.height - platform.getHeight()) + 75;
    platform.setPosition(x_pf, y_pf);

    int x_pl = (myapp.window.width - player.getWidth()) / 2;
    int y_pl = (myapp.window.height - platform.getHeight() - player.getHeight());
    player.setPosition(x_pl, y_pl);

    int x_ct = (myapp.window.width - counter.getWidth()) - 100;
    counter.setX(x_ct);
    max_counter.setX(x_ct);

    unsigned int last_time = SDL_GetTicks();

    while (!myapp.quit) {
        handleEvent(myapp);

        if (moved_left) player.subX(10);
        if (moved_right) player.addX(10);

        if (jumped && !is_jump) { 
            jump_speed = jump_force;
            is_jump = true;
        }
        
        if (is_jump) {
            player.addY(jump_speed);
            jump_speed += gravity * 0.1f;
        }
        
        if (player.onTouch(platform)){
            is_jump = false;
            jumped = false;
            jump_speed = 0;
        } else
            player.addY(gravity);

        if (dash_in_progress) {
            int current_x = player.getX();
            if ((dash_speed > 0 && current_x < dash_target_x) || (dash_speed < 0 && current_x > dash_target_x)) {
                player.addX(dash_speed);
            } else {
                dash_in_progress = false;
            }
        }

        if (player.getY() > myapp.window.height + 500){
            player.setPosition(x_pl, y_pl);
            count = 0;
        }

        if (count >= max_count) max_count = count;
        
        unsigned int current_time = SDL_GetTicks();
        if (current_time - last_time >= 1000) {
            count++;
            last_time = current_time;
        }
        if (!dash_available && current_time - dash_cooldown_time >= 1500) {
            dash_available = true;
        }

        string count_str = to_string(count);
        counter.setWidth(count_str.length() * 25);
        t_ct.setText(count_str);

        string max_count_str = to_string(max_count);
        max_counter.setWidth(max_count_str.length() * 25);
        t_mct.setText(max_count_str);

        myapp.fill(0, 0, 0);
        background.fillTexture(myapp.Render, &t_bg);
        counter.fillText(myapp.Render, &t_ct);
        max_counter.fillText(myapp.Render, &t_mct);
        platform.fillTexture(myapp.Render, &t_pf);
        player.fillTexture(myapp.Render, &t_pl, moved_left ? -7 : moved_right ? 7 : 0, facing_right ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL, point_pl);

        delayms(1);
        myapp.update();
    }

    myapp.exit();
    return 0;
}