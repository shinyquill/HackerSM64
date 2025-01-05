// flame.inc.c

void bhv_moving_flame_loop(void) {
    if (GET_BPARAM2(o->oBehParams) == MOVING_FLAME_BP_1FRAME) {
        if (o->oTimer > 0) {
            obj_mark_for_deletion(o);
        } else {
            f32 rnd = random_float() - 0.5f;

            o->header.gfx.scale[1] = o->header.gfx.scale[2] * (1.0f + 0.7f * rnd);
            o->header.gfx.scale[0] = o->header.gfx.scale[2] * (0.9f - 0.5f * rnd);

            o->oAnimState = random_u16();
        }
    } else {
        cur_obj_update_floor_and_walls();

        if (approach_f32_ptr(&o->oSmallPiranhaFlameStartSpeed, o->oSmallPiranhaFlameEndSpeed, 0.6f)) {
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);
        }

        obj_compute_vel_from_move_pitch(o->oSmallPiranhaFlameStartSpeed);
        cur_obj_move_standard(-78);
        spawn_object_with_scale(o, o->oSmallPiranhaFlameModel, bhvMovingFlame,
                                0.4f * o->header.gfx.scale[0]);

        if (o->oTimer > o->oSmallPiranhaFlameNextFlameTimer) {
            spawn_object_relative_with_scale(1, 0, o->oGraphYOffset, 0, o->header.gfx.scale[0], o,
                                             o->oSmallPiranhaFlameModel, bhvMovingFlameEmber);
            o->oSmallPiranhaFlameNextFlameTimer = random_linear_offset(8, 15);
            o->oTimer = 0;
        }

        obj_check_attacks(&sPiranhaPlantFireHitbox, o->oAction);
        o->oSmallPiranhaFlameSpeed += o->oSmallPiranhaFlameStartSpeed;

        if (o->oSmallPiranhaFlameSpeed > 1500.0f
            || (o->oMoveFlags & (OBJ_MOVE_HIT_WALL | OBJ_MOVE_MASK_IN_WATER))) {
            obj_die_if_health_non_positive();
        }
    }

    o->oGraphYOffset = 15.0f * o->header.gfx.scale[1];
}

void bhv_moving_flame_particle_loop(void) {
    cur_obj_move_using_fvel_and_gravity();

    if (approach_f32_ptr(&o->header.gfx.scale[0], 0.0f, 0.6f)) {
        obj_mark_for_deletion(o);
    }

    cur_obj_scale(o->header.gfx.scale[0]);
}

void spawn_flame(s32 behavior) {
    Vec3i pos = { 0, 0, 0 };
    spawn_object_relative(behavior, pos[0], pos[1], pos[2], o,
                            MODEL_RED_FLAME, bhvFlameSpawned);
}

void bhv_flame_loop(void) {
    osSyncPrintf("------------- bhv_flame_loop oAction %d-------------", o->oAction);
    osSyncPrintf("------------- bhv_flame_loop oDistanceToMario %d-------------", o->oDistanceToMario);
    osSyncPrintf("------------- bhv_flame_loop oDistanceToMario < COIN_FORMATION_DISTANCE %d-------------", o->oDistanceToMario < COIN_FORMATION_DISTANCE);
    switch (o->oAction) {
        case COIN_FORMATION_ACT_INACTIVE:
            if (o->oDistanceToMario < COIN_FORMATION_DISTANCE) {
                        spawn_flame(o->oBehParams2ndByte);
                o->oAction = COIN_FORMATION_ACT_ACTIVE;
            }
            break;
        case COIN_FORMATION_ACT_ACTIVE:
            if (o->oDistanceToMario > (COIN_FORMATION_DISTANCE + 100.0f)) {
                o->oAction = COIN_FORMATION_ACT_DEACTIVATE;
            }
            break;
        case COIN_FORMATION_ACT_DEACTIVATE:
            o->oAction = COIN_FORMATION_ACT_INACTIVE;
            break;
    }
}

void bhv_spawned_flame_loop(void) {
    if (o->parentObj->oAction == COIN_FORMATION_ACT_DEACTIVATE) {
        obj_mark_for_deletion(o);
    }
}