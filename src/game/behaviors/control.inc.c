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
    cur_obj_scale(0.3f);
}

void bhv_banana_loop(void) {
    if (lateral_dist_between_objects(o, gMarioObject) < 80.f && gMarioState->pos[1] < gMarioState->floorHeight + 10.0f && o->oAction == 0){
        mario_stop_riding_and_holding(gMarioState);
        update_mario_sound_and_camera(gMarioState);
        play_sound(SOUND_MARIO_OOOF, gMarioState->marioObj->header.gfx.cameraToObject);
        drop_and_set_mario_action(gMarioState, ACT_FORWARD_GROUND_KB, 0);
        gMarioStates[0].forwardVel = 90.0f;
        play_sound(SOUND_GENERAL_CUSTOM_SLIP, gGlobalSoundSource);
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
    struct Object *fallingPiece = cur_obj_nearest_object_with_behavior(bhvFallingPieceTemple);
    switch(o->oAction){
        case 0:
            if (lateral_dist_between_objects(o, gMarioObject) < 6000.f){
                o->oVelY -= 20.0f;
                o->oPosY += o->oVelY;
                if (o->oPosY < o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            cur_obj_shake_screen(2);
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
            spawn_mist_particles_variable(0, 0, 80.0f);
            spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
            o->oAction = 3;
            break;
        case 2:
            o->oVelY = 0.0f;
            cur_obj_shake_screen(2);
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
            spawn_mist_particles_variable(0, 100, 80.0f);
            spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
            cur_obj_become_intangible();
            o->oAction = 4;
            break;
        case 3:
            break;
        case 4:
            o->oVelY -= 2.0f;
            o->oPosY += o->oVelY;
            break;
        
    }
}

#include "actors/fall_piece_temple_1/collision_header.h"
#include "actors/fall_piece_temple_2/collision_header.h"
#include "actors/fall_piece_temple_3/collision_header.h"
#include "actors/fall_piece_temple_4/collision_header.h"
#include "actors/fall_piece_temple_5/collision_header.h"

static Collision const *sFallPieceTempleCollisionModels[] = {
    fall_piece_temple_1_collision,
    fall_piece_temple_2_collision,
    fall_piece_temple_3_collision,
    fall_piece_temple_4_collision,
    fall_piece_temple_5_collision,
};

void bhv_falling_piece_temple_init(void){
    s32 behavior = GET_BPARAM2(o->oBehParams);
    o->oAnimState = behavior;
    o->collisionData = segmented_to_virtual(sFallPieceTempleCollisionModels[behavior]);
}

void bhv_falling_piece_temple_loop(void){
    f32 dist;
    struct Object *falling = cur_obj_find_nearest_object_with_behavior(bhvFallingRock, &dist);
    // if (lateral_dist_between_objects(o, gMarioObject) < 7000.f){
    //     print_text_fmt_int(20, (SCREEN_HEIGHT - 64), "o->oAction %d",(s16)o->oAction);
    //     print_text_fmt_int(20, (SCREEN_HEIGHT - 80), "falling->oAction %d",(s16)falling->oAction);
    //     print_text_fmt_int(20, (SCREEN_HEIGHT - 96), "dist %d",(s16)dist);
    //     // print_text_fmt_int(20, (SCREEN_HEIGHT - 80), "PosY %d", (s16)gMarioState->floor->type == SURFACE_ANTI_GRAVITY);
    // }
    switch(o->oAction){
        case 0:
            if (dist < 1300){
                falling->oAction = 2;
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_become_intangible();
            o->oVelY -= 2.0f;
            cur_obj_shake_screen(2);
            o->oPosY += o->oVelY;
            if (o->oPosY < o->oHomeY - 600){
                mark_obj_for_deletion(o);
                mark_obj_for_deletion(falling);
            }
            break;  
    }
}

void bhv_falling_piece_init(void){
    s32 behavior = GET_BPARAM2(o->oBehParams);
    o->oAnimState = behavior;
}

void bhv_falling_piece_loop(void){
    s32 behavior = GET_BPARAM2(o->oBehParams);
    f32 dist = 3500.f, dist2 = 400.f;
    if (behavior > 1){
        dist = 1500.f;
        dist2 = 1300.f;
    }
    switch(o->oAction){
        case 0:
            if (lateral_dist_between_objects(o, gMarioObject) < dist){
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_become_intangible();
            o->oVelY -= 3.0f;
            cur_obj_shake_screen(1);
            o->oPosY += o->oVelY;
            if (o->oPosY < o->oHomeY - dist2){
                mark_obj_for_deletion(o);
            }
            break;  
    }
}

void bhv_testing_init(void) {
}

void bhv_testing_loop(void) {
    o->oFaceAngleYaw += 0x800;
    switch(o->oAction){
        case 0:
            if (obj_check_if_collided_with_object(o, gMarioObject)) {
                cur_obj_shake_screen(2);
                cur_obj_play_sound_2(SOUND_OBJ_POUNDING1);
                o->oAction = 1;               
            }
            break;
        case 1:
            if (o->oTimer < 8){
                spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                o->oFaceAngleYaw += 0x1600;
                o->oPosY += 10;
            } else {
                mark_obj_for_deletion(o);
            }
            break;
    }

}

void bhv_spawning_ranking_star_init(void){
    o->oStarChild = NULL;
}

void bhv_spawning_ranking_star_loop(void){
    s32 behavior = GET_BPARAM1(o->oBehParams);
    s16 levelNum = 0;
    if (lateral_dist_between_objects(o, gMarioObject) < 400.f && o->oStarChild == NULL){
        switch(behavior){
            case 1: {
                levelNum = LEVEL_BOB;
                break;
                }
            case 2: {
                levelNum = LEVEL_WF;
                break;
                }
            case 3: {
                levelNum = LEVEL_JRB;
                break;
                }
        }
        s32 coins = save_file_get_course_coin_score(gCurrSaveFileNum - 1, behavior - 1);
        u16 timer = save_file_get_course_time(gCurrSaveFileNum - 1, behavior - 1);
        s16 checks = calculate_rank(levelNum, timer, coins);


        if (checks == 4){
            o->oStarChild = bhv_spawn_star_ranking_no_level_exit(behavior);
        }
    }
}