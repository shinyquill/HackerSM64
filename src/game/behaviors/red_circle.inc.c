void bhv_red_circle_init(void) {
        cur_obj_enable_rendering();
        cur_obj_become_tangible();
}

void bhv_red_circle_loop(void) {
    o->oFaceAngleRoll += 0x100;
    switch (o->oAction) {
        case 0:
            // If Mario is on the switch and has ground-pounded,
            // recede and get ready to start ticking.
            if (obj_check_if_collided_with_object(o, gMarioObject)) {
                    cur_obj_disable_rendering();
                    cur_obj_become_intangible();
                    o->oAction = 1;
                    play_sound(SOUND_GENERAL_CUSTOM_RED_CIRCLE, gGlobalSoundSource);
                }
            break;

        case 1:
            // Tick faster when the blue coins start blinking
            if (o->oTimer < 300) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }
            // Delete the switch (which stops the sound) after the last coin is collected,
            // or after the coins unload after the 240-frame timer expires.
            if ((o->oTimer > 340)) {
                o->oAction = 0;
                cur_obj_enable_rendering();
                cur_obj_become_tangible();
            }
            if ((cur_obj_nearest_object_with_behavior(bhvHiddenRedCoin) == NULL)){
                obj_mark_for_deletion(o);
            }
            break;
    }
}