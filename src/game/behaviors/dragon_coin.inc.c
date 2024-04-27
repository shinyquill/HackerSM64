void bhv_dragon_coin_loop(void) {
    o->oFaceAngleYaw += 0x800;
    switch(o->oAction){
        case 0:
            if (obj_check_if_collided_with_object(o, gMarioObject)) {
                play_sound(SOUND_GENERAL_CUSTOM_DRAGON_COIN, gGlobalSoundSource);
                o->oAction = 1;               
            }
            break;
        case 1:
            if (o->oTimer < 8){
                spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                o->oFaceAngleYaw += 0x1600;
                o->oPosY += 10;
            } else {
                // o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
                mark_obj_for_deletion(o);
            }
            break;
    }

}

void bhv_hidden_red_coin_dragon_coin_init(void) {
    s16 numRedCoinsRemaining = count_objects_with_behavior(bhvHiddenRedCoin);
    o->oHiddenStarTriggerTotal = numRedCoinsRemaining + gRedCoinsCollected;
    o->oHiddenStarTriggerCounter = o->oHiddenStarTriggerTotal - numRedCoinsRemaining;
    
}

void bhv_hidden_red_coin_dragon_coin_loop(void) {
    struct Object *starObj = NULL;
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;

    switch (o->oAction) {
        case HIDDEN_STAR_ACT_INACTIVE:
            if (o->oHiddenStarTriggerCounter == o->oHiddenStarTriggerTotal) {
                o->oAction = HIDDEN_STAR_ACT_ACTIVE;
            }
            break;

        case HIDDEN_STAR_ACT_ACTIVE:
            if (o->oTimer > 2) {
                starObj = spawn_object_abs_with_rot(o, 0, MODEL_DRAGON_COIN, bhvDragonCoin, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
                starObj->oBehParams = o->oBehParams;
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}