#include "../../game/puppyprint.h"
void bhv_control_loop(void) {
    print_text_fmt_int(20, (SCREEN_HEIGHT - 32), "m.vel0 %d",(s16)gMarioState->vel[0]);
    print_text_fmt_int(20, (SCREEN_HEIGHT - 48), "m.vel1 %d",(s16)gMarioState->vel[1]);
    print_text_fmt_int(20, (SCREEN_HEIGHT - 64), "m.vel2 %d",(s16)gMarioState->vel[2]);
    print_text_fmt_int(20, (SCREEN_HEIGHT - 80), "PosY %d", (s16)gMarioState->floor->type == SURFACE_ANTI_GRAVITY);
    if (gPlayer1Controller->buttonPressed & (L_TRIG)){
        // vec3f_copy_with_gravity_switch(gMarioState->pos, gMarioState->marioObj->header.gfx.pos);
        print_text_fmt_int(20, (SCREEN_HEIGHT - 96), "pressed L");
    }
    //
    // print_text_fmt_int(20, (SCREEN_HEIGHT - 112), "gCameraPos2 %d", gCameraPos[2] );
    // print_text_fmt_int(20, (SCREEN_HEIGHT - 128), "wTimer %d", (s16)sTimerWeapon);
    // print_text_fmt_int(20, (SCREEN_HEIGHT - 144), "oTimer %d", (s16)o->oTimer);
    }

void bhv_rotating_trunk_loop(void) {
        o->oFaceAngleRoll += 0x050;
    }

void bhv_flying_init(void) {
        o->oFaceAngleRoll += 0x050;
    }

void bhv_flying_loop(void) {
        o->oFaceAngleRoll += 0x050;
    }