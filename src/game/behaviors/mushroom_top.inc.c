// Assuming these are defined somewhere in your system:

void bhv_mushroom_top_init(void) {
    o->oMushroomAnimate = 0;
    switch(GET_BPARAM1(o->oBehParams)){
        case 0:
            {
            o->oMushroomSize = 1.0f;
            break;
            }
        case 1:
        {
            o->oMushroomSize = 2.0f;
            break;
        }
        case 2:
        {
            o->oMushroomSize = 3.0f;
            break;
        }
    }

    switch(GET_BPARAM2(o->oBehParams)){
        case 0:
            {
            o->oMushroomForce = 64.0f;
            break;
            }
        case 1:
        case 2:
        {
            o->oMushroomForce = 84.0f;
            break;
        }
    }
    cur_obj_scale(o->oMushroomSize);
}

void bhv_mushroom_top_loop(void) {
    if (lateral_dist_between_objects(o, gMarioObject) < 400.f){
        print_text_fmt_int(20, (SCREEN_HEIGHT - 32), "m.vel0 %d",(s16)gMarioState->vel[1]);
        print_text_fmt_int(20, (SCREEN_HEIGHT - 48), "m.vel1 %d",(s16)gMarioState->forwardVel);
        print_text_fmt_int(20, (SCREEN_HEIGHT - 64), "m.vel2 %d",(s16)o->oMushroomForce);
        print_text_fmt_int(20, (SCREEN_HEIGHT - 80), "m.vel0 %d",(s16)angle_to_degrees(gMarioState->faceAngle[0]));
        print_text_fmt_int(20, (SCREEN_HEIGHT - 96), "m.vel1 %d",(s16)angle_to_degrees(gMarioState->faceAngle[1]));
        print_text_fmt_int(20, (SCREEN_HEIGHT - 112), "m.vel2 %d",(s16)angle_to_degrees(gMarioState->faceAngle[2]));
    }
    if  (gMarioObject->platform == o && o->oMushroomAnimate == 0 && gMarioState->floor->type == SURFACE_BOUNCE){
        gMarioState->action = ACT_MUSH_BOUNCE;
        play_sound_if_no_flag(gMarioState, SOUND_MARIO_YAHOO, MARIO_MARIO_SOUND_PLAYED);
        update_mario_sound_and_camera(gMarioState);
        gMarioState->marioObj->header.gfx.animInfo.animFrame = 0;
        set_mario_animation(gMarioState, MARIO_ANIM_TRIPLE_JUMP);
        // set_mario_action(gMarioState, MARIO_ANIM_TRIPLE_JUMP_LAND, 0);
        o->oMushroomAnimate = 1;
        o->oTimer = 0;
        if (GET_BPARAM3(o->oBehParams) != 0){
            switch(GET_BPARAM2(o->oBehParams)){
                case 2:{
                        gMarioState->faceAngle[1] = gMarioState->floorYaw;
                        gMarioState->vel[1] = o->oMushroomForce * 1.5f;
                        gMarioState->forwardVel = o->oMushroomForce;
                    break;
                }
                case 3:{
                        gMarioState->faceAngle[1] = gMarioState->floorYaw;
                        gMarioState->vel[1] = o->oMushroomForce * 2.f;
                        gMarioState->forwardVel = o->oMushroomForce;
                    break;
                }
                default:{
                        gMarioState->faceAngle[1] = gMarioState->floorYaw;
                        gMarioState->vel[1] = o->oMushroomForce;
                        gMarioState->forwardVel = o->oMushroomForce;
                    break;
                }
            }
        } else {
            switch(GET_BPARAM2(o->oBehParams)){
                case 2:{
                        gMarioState->vel[1] = o->oMushroomForce *2.f;
                    break;
                }
                default:{
                        gMarioState->vel[1] = o->oMushroomForce;
                    break;
                }
            }
        }
    }
    if (o->oMushroomAnimate == 1){
        // Shrink until the squish speed becomes 0, then unisquish
        if (o->oTimer < 4) {
            o->header.gfx.scale[1] -= 0.5f;
        }
        else if (o->oTimer < 8) {
            o->header.gfx.scale[1] += 0.5f;
        }
        else {
            o->header.gfx.scale[1] = o->oMushroomSize;
            o->oMushroomAnimate = 0;
        }
    }

    //     if (o->oTimer >= 16) {
    //         obj_die_if_health_non_positive();
    //     }
}
