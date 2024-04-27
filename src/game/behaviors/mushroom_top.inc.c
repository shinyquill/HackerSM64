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
    if  (gMarioObject->platform == o && o->oMushroomAnimate == 0 && gMarioState->floor->type == SURFACE_BOUNCE){
        gMarioState->action = ACT_MUSH_BOUNCE;
        play_sound(SOUND_GENERAL_CUSTOM_SPRING, gGlobalSoundSource);
        play_sound_if_no_flag(gMarioState, SOUND_MARIO_YAHOO, MARIO_MARIO_SOUND_PLAYED);
        update_mario_sound_and_camera(gMarioState);
        gMarioState->marioObj->header.gfx.animInfo.animFrame = 0;
        set_mario_animation(gMarioState, MARIO_ANIM_TRIPLE_JUMP);
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
            o->header.gfx.scale[1] -= 0.25f;
        }
        else if (o->oTimer < 8) {
            o->header.gfx.scale[1] += 0.25f;
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
