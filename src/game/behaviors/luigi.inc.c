void bhv_luigi_init(void) {
    o->oAction = 0;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void bhv_luigi_loop(void) {
    switch (o->oAction){
        case 0: 
            luigi_act_idle();
            break;
        case 1:
            luigi_act_talk();
            break;
        case 2:
            break;
    }
    curr_obj_random_blink(&o->oLuigiBlinkTimer);
}

void luigi_act_idle(void) {
    s16 animFrame = o->header.gfx.animInfo.animFrame;

    object_step();

    // if (o->oDistanceToMario < 1000.0f) {
    //     o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
    // }

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = 1;
    }
}
void luigi_act_talk(void) {
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte) != 0) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);

            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oInteractStatus = INT_STATUS_NONE;
            o->oAction = 0;
        }
    }
}
