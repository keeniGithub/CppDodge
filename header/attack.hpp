#ifndef ATTACK
#define ATTACK

#include <cstdlib>
#include <ctime>
#include <var.hpp>

void attack_rocket() {
    if (rocket_counter < 800) {
        rocket_counter += 2;
        if (rocket_counter > 400)
            rocket.addY(15);
    } else {
        rocket_counter = 0;
        rocket_attack_avalible = true;
    }
}

void attack_laser() {
    if (laser_counter < 75) {
        warning_left.setY(y_wrn);
        warning_right.setY(y_wrn);
        laser_counter += 1;
    } else if (laser_counter < 150) {
        if (laser_left.getWidth() < 20) laser_left.addWidth(1);
        if (laser_right.getWidth() < 20) laser_right.addWidth(1);
        laser_left.setHeight(h_ls);
        laser_right.setHeight(h_ls);
        laser_counter += 1;
    } else if (laser_counter < 300) {
        int center_x = platform.getX() + platform.getWidth() / 2;
        if (laser_left.getX() < center_x - laser_left.getWidth() - 10) {
            laser_left.addX(2);
        }
        if (laser_right.getX() > center_x + 10) {
            laser_right.subX(2);
        }
        laser_counter += 2;
    } else if (laser_counter < 375) {
        laser_counter += 1;
    } else if (laser_counter < 600) {
        if (laser_right.getX() < platform.getX() + platform.getWidth() - 30) {
            laser_left.addX(2);
            laser_right.addX(2);
        } else {
            laser_counter = 601;
        }
    } else if (laser_counter < 900) {
        if (laser_left.getX() > platform.getX() + 10) {
            laser_left.subX(2);
            laser_right.subX(2);
        } else {
            laser_counter = 901;
        }
    } else if (laser_counter < 1050) {
        int left_start = platform.getX() + 10;
        int right_start = platform.getX() + platform.getWidth() - laser_right.getWidth() - 10;

        if (laser_left.getX() > left_start) {
            laser_left.subX(2);
        }
        if (laser_right.getX() < right_start) {
            laser_right.addX(4);
        }
        laser_counter += 1;
    } else if (laser_counter < 1101) {
        if (laser_left.getWidth() > 0) laser_left.subWidth(1);
        if (laser_right.getWidth() > 0) laser_right.subWidth(1);
        laser_counter += 1;
    } else {
        laser_counter = 0;
        laser_attack_avalible = true;
        laser_left.setX(platform.getX() + 10);
        laser_right.setX(platform.getX() + platform.getWidth() - laser_right.getWidth() - 10);
        laser_right.subX(20);
        laser_left.setSize(0, 0);
        laser_right.setSize(0, 0);
    }
}

void attack_saw() {
    if (saw_counter < 75) {
        warning_left.setY(y_wrn);
        warning_right.setY(y_wrn);
        saw_counter += 1;
    } else if (saw_counter < 100) {
        warning_left.setY(-100);
        warning_right.setY(-100);
        saw_counter += 5;
    } else if (saw_counter < 300) {
        saw_left.subY(10);
        saw_right.subY(10);
        saw_counter += 10;
    } else if (saw_counter < 350) {
        saw_counter += 1;
    } else if (saw_counter < 650) {
        if (saw_left.getX() < x_sw + platform.getWidth()) saw_left.addX(10);
        if (saw_right.getX() > x_sw - platform.getWidth()) saw_right.subX(10);
        saw_counter += 10;
    } else if (saw_counter < 700) {
        saw_counter += 1;
    } else if (saw_counter < 1000) {
        if (saw_left.getX() > x_sw) saw_left.subX(10);
        if (saw_right.getX() < x_sw + platform.getWidth()) saw_right.addX(10);
        saw_counter += 10;
    } else if (saw_counter < 1100) {
        saw_counter += 2;
    } else if (saw_counter < 1200) {
        saw_left.addY(10);
        saw_right.addY(10);
        saw_counter += 4;
    } else if (saw_counter < 1350) {
        saw_counter += 1;
    } else {
        saw_counter = 0;
        saw_attack_avalible = true;
        saw_left.setY(y_sw);
        saw_right.setY(y_sw);
    }
}

void attack_pipe() {
    if (pipe_counter < 100) {
        if (pipe.getY() < 0) pipe.addY(10);
        pipe_counter += 1;
    } else if (pipe_counter < 200) {
        if (blob.getY() < y_pf - 40) blob.addY(15);
        pipe_counter += 2;
    } else if (pipe_counter < 300) {
        if (pipe.getY() > -150) pipe.subY(5);
        pipe_counter += 1;
    } else if (pipe_counter < 700) {
        pipe.setY(-150);
        if (player.getX() > blob.getX()) blob.addX(1);
        else blob.subX(1);
        pipe_counter += 1;
    } else if (pipe_counter < 900) {
        if (bl_degr < 360) bl_degr += 12;
        blob.addY(5);
        pipe_counter += 1;
    } else {
        pipe_counter = 0;
        pipe_attack_avalible = true;
        pipe.setPosition(x_pp, -150);
        blob.setPosition(x_bl, -36);
        bl_degr = 0;
    }
}

void attack_spiky() {
    if (spiky_counter < 100) {
        if (spiky.getY() < 0) spiky.addY(1);
        spiky_counter += 1;
    } else if (spiky_counter < 200) {
        if (spiky.getY() < x_pf) spiky.addY(20);
        spiky_counter += 2;
    } else if (spiky_counter < 500) {
        spiky.addY(1);
        spiky_counter += 1;
    } else {
        spiky_counter = 0;
        spiky_attack_avalible = true;
        spiky.setY(-170);
        x_sp = 0;
    }
}

void random_attack() {
    if (!rocket_attack_avalible) {
        attack_rocket();
    } if (!laser_attack_avalible) {
        attack_laser();
    } if (!saw_attack_avalible) {
        attack_saw();
    } if (!pipe_attack_avalible) {
        attack_pipe();
    } if (!spiky_attack_avalible) {
        attack_spiky();
    }
        
    attack_elapsed++;
    if (attack_elapsed >= attack_timer * 20) {
        int random_attack = rand() % 5;
        if (random_attack == 0 && rocket_attack_avalible) {
            rocket.setPosition(x_rkt, -100);
            rocket_attack_avalible = false;
            cout << "attack rocket" << endl;
        } else if (random_attack == 1 && laser_attack_avalible) {
            laser_right.subX(20);
            laser_attack_avalible = false;
            cout << "attack laser" << endl;
        } else if (random_attack == 2 && saw_attack_avalible) {
            saw_attack_avalible = false;
            cout << "attack saw" << endl;
        } else if (random_attack == 3 && pipe_attack_avalible) {
            pipe_attack_avalible = false;
            cout << "attack pipe" << endl;
        } else if (random_attack == 4 && spiky_attack_avalible) {
            if (x_sp == 0) {
                x_sp = rand() % (myapp.window.width - 2 * x_pf) + x_pf;
                spiky.setX(x_sp);
            }
            spiky_attack_avalible = false;
            cout << "attack spiky" << endl;
        }

        attack_elapsed = 0;
        attack_timer = rand() % 12 + 5;
    }
}

#endif