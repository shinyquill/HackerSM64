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

void bhv_shell_loop(void) {
        o->oFaceAngleYaw += 0x100;
    }

void bhv_banana_init(void) { 
    o->oAction = 0;
    cur_obj_scale(0.25f);
}

void bhv_banana_loop(void) {
    if (lateral_dist_between_objects(o, gMarioObject) < 80.f && gMarioState->pos[1] < gMarioState->floorHeight + 10.0f && o->oAction == 0){
        mario_stop_riding_and_holding(gMarioState);
        update_mario_sound_and_camera(gMarioState);
        play_sound(SOUND_MARIO_OOOF, gMarioState->marioObj->header.gfx.cameraToObject);
        drop_and_set_mario_action(gMarioState, ACT_HARD_BACKWARD_AIR_KB, 0);
        gMarioStates[0].forwardVel = 90.0f;
        // gMarioState->faceAngle[1] = o->oMoveAngleYaw;
        o->oAction = 1;
    }
    switch(o->oAction){
        case 0:
            break;
        case 1:
            if (o->header.gfx.scale[1] > 0.05f) {
                o->header.gfx.scale[1] -= 0.05f;
            } else {
                o->header.gfx.scale[1] = 0.05f;
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}
void bhv_falling_rock_init(void){
    o->oPosY += 6000.f;
    s32 sSize;
    switch(GET_BPARAM1(o->oBehParams)){
        case 0:
            {
            cur_obj_scale(1.5f);
            break;
            }
        case 1:
        {
            cur_obj_scale(2.0f);
            break;
        }
        case 2:
        {
            cur_obj_scale(3.0f);
            break;
        }
    }
}

void bhv_falling_rock_loop(void){
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    // print_text_fmt_int(20, (SCREEN_HEIGHT - 32), "dist %d",(s16)o->oDistanceToMario );
    // print_text_fmt_int(20, (SCREEN_HEIGHT - 48), "m.vel0 %d",(s16)lateral_dist_between_objects(o, gMarioObject) < 6000.f);
    if (lateral_dist_between_objects(o, gMarioObject) < 6000.f && o->oAction == 0){
        o->oVelY -= 100.0f; 
        o->oPosY += o->oVelY;
        if (o->oPosY < o->oHomeY) {
            o->oPosY = o->oHomeY;
            o->oAction = 1;
        }
    }
    if (o->oAction == 1){
        cur_obj_shake_screen(SHAKE_POS_SMALL);
        create_sound_spawner(SOUND_GENERAL_WALL_EXPLOSION);
        spawn_mist_particles_variable(0, 0, 80.0f);
        spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
        o->oAction = 2;
    }
}