#include <InSDL.hpp>
#include <var.hpp>
#include <physic.hpp>
#include <check.hpp>
#include <anim.hpp>
#include <bind.hpp>
#include <save.hpp>
#include <attack.hpp>

using namespace std;

int main()
{
    app myapp;
    myapp.init(1200, 600, name, true);

    texture icon(myapp.Render, path+"image/icon.png");
    myapp.setIcon(icon);

    frect logo(0, 0, 500, 100);
    texture t_lg(myapp.Render, path+"image/CppDodge.png");

    frect menu_background(0, 0, 1200, 600);
    texture t_mbg(myapp.Render, path+"image/menuBg.png");

    frect background(0, 0, 1200, 800);
    texture t_bg(myapp.Render, path+"image/bg.png");

    frect button(0, 0, 400, 75);
    texture t_btn(myapp.Render, path+"image/btnPlay.png");
    texture t_hvbtn(myapp.Render, path+"image/hoverPlay.png");

    frect button_github(0, 0, 400, 75);
    texture t_ghbtn(myapp.Render, path+"image/btnGithub.png");
    texture t_hvghbtn(myapp.Render, path+"image/hoverGithub.png");

    frect counter(0, 140, 25, 50);
    text t_ct(myapp.Render, "0", myapp.font);

    frect max_counter(0, 180, 25, 50);
    text t_mct(myapp.Render, "0", myapp.font, 158, 228, 255);

    frect dash_state(0, 15, 75, 110);
    texture t_ds(myapp.Render, path+"image/dash.png");
    texture t_nods(myapp.Render, path+"image/noDash.png");

    frect lava(0, 0, 1200, 50);
    texture t_lv(myapp.Render, path+"image/lavahound.png");

    frect platform(0, 0, 600, 150);
    texture t_pf(myapp.Render, path+"image/platform.png");

    frect player(0, 0, 60, 60);
    texture t_pl(myapp.Render, path+"image/rambo.png");
    texture t_dpl(myapp.Render, path+"image/ramboSad.png");
    SDL_FPoint point_pl = {
        static_cast<float>( player.getWidth()/2 ),
        static_cast<float>( player.getHeight()/2 )
    };

    frect pause_background(0, 0, 350, 350);
    texture t_pbg(myapp.Render, path+"image/pauseBg.png");

    frect button_resume(0, 0, 250, 80);
    texture t_rsbtn(myapp.Render, path+"image/btnResume.png");
    texture t_hvrsbtn(myapp.Render, path+"image/hoverResume.png");

    frect button_quit(0, 0, 250, 80);
    texture t_qtbtn(myapp.Render, path+"image/btnQuit.png");
    texture t_hvqtbtn(myapp.Render, path+"image/hoverQuit.png");

    frect button_pause(10, 10, 60, 60);
    texture t_psbtn(myapp.Render, path+"image/btnPause.png");
    
    frect scope(player.getX()-25, player.getY()-25, player.getWidth()+50, player.getHeight()+50);
    texture t_scp(myapp.Render, path+"image/scope.png");
    SDL_FPoint point_scp = {
        static_cast<float>( scope.getWidth()/2 ),
        static_cast<float>( scope.getHeight()/2 )
    };

    frect rocket(0, -100, 48, 96);
    texture t_rkt(myapp.Render, path+"image/rocket.png");

    frect laser_left(0, 0, 0, 0);
    frect laser_right(0, 0, 0, 0);
    texture t_ls(myapp.Render, path+"image/laser.png");

    frect warning_left(0, 0, 60, 60);
    frect warning_right(0, 0, 60, 60);
    texture t_wrn(myapp.Render, path+"image/warning.png");

    int x_pf = (myapp.window.width - platform.getWidth()) / 2;
    int y_pf = (myapp.window.height - platform.getHeight());
    platform.setPosition(x_pf, y_pf);

    int x_pl = (myapp.window.width - player.getWidth()) / 2;
    int y_pl = (myapp.window.height - platform.getHeight() - player.getHeight());
    player.setPosition(x_pl, y_pl);

    int x_ct = (myapp.window.width - counter.getWidth()) - 50;
    counter.setX(x_ct);
    max_counter.setX(x_ct);

    int x_ds = (myapp.window.width - dash_state.getWidth());
    dash_state.setX(x_ds);

    int y_lv = (myapp.window.height - lava.getHeight());
    lava.setY(y_lv);

    int x_lg = (myapp.window.width - logo.getWidth()) / 2;
    int y_lg = (myapp.window.height - logo.getHeight()) / 2 - 120;
    logo.setPosition(x_lg, y_lg);

    int x_btn = (myapp.window.width - button.getWidth()) / 2;
    int y_btn = (myapp.window.height - button.getHeight()) / 2;
    button.setPosition(x_btn, y_btn);

    int y_ghbtn = (myapp.window.height - button.getHeight()) / 2 + 100;
    button_github.setPosition(x_btn, y_ghbtn);

    int x_pbg = (myapp.window.width - pause_background.getWidth()) / 2;
    int y_pbg = (myapp.window.height - pause_background.getHeight()) / 2;
    pause_background.setPosition(x_pbg, y_pbg);

    int x_rsbtn = (myapp.window.width - button_resume.getWidth()) / 2;
    int y_rsbtn = (myapp.window.height - button_resume.getHeight()) / 2 - 50;
    button_resume.setPosition(x_rsbtn, y_rsbtn);
    button_quit.setPosition(x_rsbtn, y_rsbtn + 100);
    
    int x_rkt = (myapp.window.width - rocket.getWidth()) / 2;
    rocket.setX(x_rkt);

    int h_ls = (myapp.window.height - platform.getHeight());
    laser_left.setX(x_pf + 10);
    laser_right.setX((x_pf + platform.getWidth() - laser_right.getWidth()) - 25);

    int y_wrn = (myapp.window.height - platform.getHeight() - warning_left.getHeight());
    warning_left.setX(x_pf - 15);
    warning_right.setX(x_pf + platform.getWidth() - laser_right.getWidth() - 40);
    warning_left.setY(y_wrn);
    warning_right.setY(y_wrn);

    load(max_count);

    bind_movement(myapp);
    bind_button(myapp, button, button_resume, button_quit, button_pause, button_github, player, x_pl, y_pl);
    bind_menu(myapp);

    init_attack_timer();

    while (!myapp.quit) {
        handleEvent(myapp);

        if (!game){
            myapp.fill(0, 0, 0);
            menu_background.fillTexture(myapp.Render, &t_mbg);
            logo.fillTexture(myapp.Render, &t_lg);
            button.fillTexture(myapp.Render, button.onHover() ? &t_hvbtn : &t_btn);
            button_github.fillTexture(myapp.Render, button_github.onHover() ? &t_hvghbtn : &t_ghbtn);
        } else {
            scope.setFrect(player.getX()-25, player.getY()-25, player.getWidth()+50, player.getHeight()+50);

            myapp.fill(0, 0, 0);
            background.fillTexture(myapp.Render, &t_bg);
            counter.fillText(myapp.Render, &t_ct);
            max_counter.fillText(myapp.Render, &t_mct);
            dash_state.fillTexture(myapp.Render, dash_available ? &t_ds : &t_nods);
            platform.fillTexture(myapp.Render, &t_pf);
            lava.fillTexture(myapp.Render, &t_lv);
            button_pause.fillTexture(myapp.Render, &t_psbtn);
            player.fillTexture(myapp.Render, 
                (die || (death_count % 10 == 0 && death_count != 0)) ? &t_dpl : &t_pl, 
                moved_left ? -5 : moved_right ? 5 : degr, 
                facing_right ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL, point_pl
            );
            rocket.fillTexture(myapp.Render, &t_rkt);
            if (attack == "laser"){
                laser_left.fillTexture(myapp.Render, &t_ls);
                laser_right.fillTexture(myapp.Render, &t_ls);
                warning_left.fillTexture(myapp.Render, &t_wrn);
                warning_right.fillTexture(myapp.Render, &t_wrn);
            }

            if (attack == "rocket" && attack_counter < 400){
                scope.fillTexture(myapp.Render, &t_scp, scp_degr, SDL_FLIP_NONE, point_scp);
                rocket.setX(player.getX());
            }

            if (!pause){
                if (moved_left) 
                    player.subX(10);
                if (moved_right) 
                    player.addX(10);

                random_attack(rocket, x_rkt, laser_left, laser_right, warning_left, warning_right, x_pf, platform.getWidth(), y_wrn, h_ls, (x_pf + platform.getWidth() - laser_right.getWidth()) - 10);

                handle_jump(player, platform);
                handle_dash(myapp, player);
                
                anim_die(player, x_pl, y_pl);
                if (die) {
                    laser_left.setX(x_pf + 10);
                    laser_right.setX((x_pf + platform.getWidth() - laser_right.getWidth()) - 10);
                    laser_left.setHeight(0);
                    laser_right.setHeight(0);
                }

                if (
                    player.onTouch(lava) 
                    || check_border(player, myapp)
                    || player.onTouch(rocket)
                    || player.onTouch(laser_left)
                    || player.onTouch(laser_right)
                   ) 
                    die = true;

                cout<<"Player Y: "<<player.getY()<<endl;
                cout<<"Platform Y: "<<platform.getY()<<endl;
                cout<<"y_pf Y: "<<y_pf<<endl;

                if (player.getY() > 400 && player.onTouch(platform)) 
                    player.setY(400);

                if (current_count >= max_count) 
                    max_count = current_count;
                
                string count_str = to_string(current_count);
                counter.setWidth(count_str.length() * 25);
                t_ct.setText(count_str);

                string max_count_str = to_string(max_count);
                max_counter.setWidth(max_count_str.length() * 25);
                t_mct.setText(max_count_str);

                scp_degr += 6;
            } else {
                pause_background.fillTexture(myapp.Render, &t_pbg);
                button_resume.fillTexture(myapp.Render, button_resume.onHover() ? &t_hvrsbtn : &t_rsbtn);
                button_quit.fillTexture(myapp.Render, button_quit.onHover() ? &t_hvqtbtn : &t_qtbtn);
            }
        }

        save(max_count);

        delayms(1);
        myapp.update();
    }

    myapp.exit();
    return 0;
}