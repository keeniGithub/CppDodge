#include <InSDL.hpp>
#include <var.hpp>
#include <physic.hpp>
#include <check.hpp>
#include <died.hpp>
#include <bind.hpp>
#include <save.hpp>
#include <attack.hpp>

using namespace std;

int main()
{
    init();

    texture t_lg(myapp.Render, path+"image/CppDodge.png");
    texture t_mbg(myapp.Render, path+"image/menuBg.png");
    texture t_bg(myapp.Render, path+"image/bg.png");
    texture t_btn(myapp.Render, path+"image/btnPlay.png");
    texture t_hvbtn(myapp.Render, path+"image/hoverPlay.png");
    texture t_ghbtn(myapp.Render, path+"image/btnGithub.png");
    texture t_hvghbtn(myapp.Render, path+"image/hoverGithub.png");
    texture t_ds(myapp.Render, path+"image/dash.png");
    texture t_nods(myapp.Render, path+"image/noDash.png");
    texture t_lv(myapp.Render, path+"image/lavahound.png");
    texture t_pf(myapp.Render, path+"image/platform.png");
    texture t_pl(myapp.Render, path+"image/rambo.png");
    texture t_dpl(myapp.Render, path+"image/ramboSad.png");
    texture t_pbg(myapp.Render, path+"image/pauseBg.png");
    texture t_rsbtn(myapp.Render, path+"image/btnResume.png");
    texture t_hvrsbtn(myapp.Render, path+"image/hoverResume.png");
    texture t_qtbtn(myapp.Render, path+"image/btnQuit.png");
    texture t_hvqtbtn(myapp.Render, path+"image/hoverQuit.png");
    texture t_psbtn(myapp.Render, path+"image/btnPause.png");
    texture t_scp(myapp.Render, path+"image/scope.png");
    texture t_rkt(myapp.Render, path+"image/rocket.png");
    texture t_ls(myapp.Render, path+"image/laser.png");
    texture t_sw(myapp.Render, path+"image/saw.png");
    texture t_wrn(myapp.Render, path+"image/warning.png");
    texture t_pp(myapp.Render, path+"image/pipe.png");
    texture t_bl(myapp.Render, path+"image/blob.png");
    texture t_sp(myapp.Render, path+"image/spiky.png");

    text t_ct(myapp.Render, "0", myapp.font);
    text t_mct(myapp.Render, "0", myapp.font, 158, 228, 255);

    while (!myapp.quit) {
        handleEvent(myapp);

        myapp.fill(0, 0, 0);

        if (!game) {
            reset();
            
            menu_background.fillTexture(myapp.Render, &t_mbg);
            logo.fillTexture(myapp.Render, &t_lg);
            button.fillTexture(myapp.Render, button.onHover() ? &t_hvbtn : &t_btn);
            button_github.fillTexture(myapp.Render, button_github.onHover() ? &t_hvghbtn : &t_ghbtn);
        } else {
            scope.setFrect(player.getX()-25, player.getY()-25, player.getWidth()+50, player.getHeight()+50);

            background.fillTexture(myapp.Render, &t_bg);
            counter.fillText(myapp.Render, &t_ct);
            max_counter.fillText(myapp.Render, &t_mct);
            dash_state.fillTexture(myapp.Render, dash_available ? &t_ds : &t_nods);

            if (!spiky_attack_avalible) spiky.fillTexture(myapp.Render, &t_sp);

            platform.fillTexture(myapp.Render, &t_pf);
            button_pause.fillTexture(myapp.Render, &t_psbtn);
            player.fillTexture(myapp.Render, 
                (die || (death_count % 10 == 0 && death_count != 0)) ? &t_dpl : &t_pl, 
                moved_left ? -5 : moved_right ? 5 : degr, 
                facing_right ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL, point_pl
            );
            rocket.fillTexture(myapp.Render, &t_rkt);

            if (!laser_attack_avalible) {
                laser_left.fillTexture(myapp.Render, &t_ls);
                laser_right.fillTexture(myapp.Render, &t_ls);
            }

            if (!rocket_attack_avalible && rocket_counter < 400) {
                scope.fillTexture(myapp.Render, &t_scp, scp_degr, SDL_FLIP_NONE, point_scp);
                rocket.setX(player.getX());
            }

            if (!saw_attack_avalible) {
                saw_left.fillTexture(myapp.Render, &t_sw, saw_degr, SDL_FLIP_NONE, point_sw);
                saw_right.fillTexture(myapp.Render, &t_sw, saw_degr*-1, SDL_FLIP_NONE, point_sw);
                warning_left.fillTexture(myapp.Render, &t_wrn);
                warning_right.fillTexture(myapp.Render, &t_wrn);
            }

            if (!pipe_attack_avalible) {
                blob.fillTexture(myapp.Render, &t_bl, bl_degr, SDL_FLIP_NONE, point_bl);
                pipe.fillTexture(myapp.Render, &t_pp);
            }

            lava.fillTexture(myapp.Render, &t_lv);

            if (!pause){
                if (moved_left) 
                    player.subX(10);
                if (moved_right) 
                    player.addX(10);

                random_attack();

                handle_jump();
                handle_dash();
                handle_die();
                
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
                saw_degr += 12;
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