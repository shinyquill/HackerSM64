
/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

    obj_set_hitbox(o, &sRedCoinHitbox);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != o->parentObj->oHiddenStarTriggerTotal) {
                // Cap visible count to 99
                if (o->parentObj->oHiddenStarTriggerCounter > 99) {
                    spawn_orange_number(9, 28, 0, 0);
                    spawn_orange_number(9, -28, 0, 0);
                }
                else if (o->parentObj->oHiddenStarTriggerCounter >= 10) {
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter % 10, 28, 0, 0);
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter / 10, -28, 0, 0);
                }
                else {
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
                }
            }

#ifdef JP_RED_COIN_SOUND
            // For JP version, play an identical sound for all coins.
            create_sound_spawner(SOUND_GENERAL_RED_COIN);
#else
            if (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter > 7) {
                // Play the first red coin sound until it gets to the final 8
                play_sound(SOUND_MENU_COLLECT_RED_COIN, gGlobalSoundSource);
            }
            else {
                // On all versions but the JP version, each coin collected plays a higher noise.
                play_sound(SOUND_MENU_COLLECT_RED_COIN
                        + (((u8) 7 - (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter)) << 16),
                        gGlobalSoundSource);
            }
#endif
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

void bhv_hidden_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenDragonCoin);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }
    o->oAction = 0;
    obj_set_hitbox(o, &sRedCoinHitbox);
}


void bhv_hidden_red_coin_loop(void) {
    struct Object *redCircle;
    switch (o->oAction) {
        case 0:
            // Become invisible and intangible
            o->parentObj->oHiddenStarTriggerCounter = 0;
            cur_obj_disable_rendering();
            cur_obj_become_intangible();

            // Set action to HIDDEN_BLUE_COIN_ACT_WAITING after the blue coin switch is found.
            o->oHiddenRedCircle = cur_obj_nearest_object_with_behavior(bhvRedRing);

            if (o->oHiddenRedCircle != NULL) {
                o->oAction = 1;
            }

            break;

        case 1:
            // Wait until the blue coin switch starts ticking to activate.
            redCircle = o->oHiddenRedCircle;

            if (redCircle->oAction == 1) {
                o->oAction = 2;
            }

            break;

        case 2:
            // Become tangible
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // Delete the coin once collected
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oAction == 2 ) {
                // ...and there is a red coin star in the level...
                if (o->parentObj != NULL) {
                    // ...increment the star's counter.
                    o->parentObj->oHiddenStarTriggerCounter++;

                    // Spawn the orange number counter, as long as it isn't the last coin.
                    if (o->parentObj->oHiddenStarTriggerCounter != o->parentObj->oHiddenStarTriggerTotal) {
                        // Cap visible count to 99
                        if (o->parentObj->oHiddenStarTriggerCounter > 99) {
                            spawn_orange_number(9, 28, 0, 0);
                            spawn_orange_number(9, -28, 0, 0);
                        }
                        else if (o->parentObj->oHiddenStarTriggerCounter >= 10) {
                            spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter % 10, 28, 0, 0);
                            spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter / 10, -28, 0, 0);
                        }
                        else {
                            spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
                        }
                    }
                    if (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter > 7) {
                        // Play the first red coin sound until it gets to the final 8
                        play_sound(SOUND_MENU_COLLECT_RED_COIN, gGlobalSoundSource);
                    }
                    else {
                        // On all versions but the JP version, each coin collected plays a higher noise.
                        play_sound(SOUND_MENU_COLLECT_RED_COIN
                                + (((u8) 7 - (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter)) << 16),
                                gGlobalSoundSource);
                    }
                spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                o->oAction = 3;
                // obj_mark_for_deletion(o);
                }
            }

            // After 200 frames of waiting and 20 2-frame blinks (for 240 frames total),
            // delete the object.
            if (gCurrLevelNum == LEVEL_JRB){
                if (cur_obj_wait_then_blink(600, 20)) {
                    o->oAction = 0;
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                }
            } else {
                if (cur_obj_wait_then_blink(300, 20)) {
                    o->oAction = 0;
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                }
            }

            break;

            case 3:
            // Become invisible and intangible
            cur_obj_disable_rendering();
            cur_obj_become_intangible();

            // Set action to HIDDEN_BLUE_COIN_ACT_WAITING after the blue coin switch is found.
            o->oHiddenRedCircle = cur_obj_nearest_object_with_behavior(bhvRedRing);
            if (o->oHiddenRedCircle != NULL){
                if (o->oHiddenRedCircle->oAction == 0) {
                    o->oAction = 0;
                } 
            } else {
                mark_obj_for_deletion(o);
            }
            break;

    }

    o->oInteractStatus = INT_STATUS_NONE;
}
