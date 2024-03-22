// breakable_box.inc.c

struct ObjectHitbox sBreakableBoxSmallHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 3,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 250,
    /* hurtboxRadius:     */ 250,
    /* hurtboxHeight:     */ 150,
};

void bhv_breakable_box_small_init(void) {
    o->oGravity = 4.0f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 0.0f;
    //cur_obj_scale(1.0f);
    obj_set_hitbox(o, &sBreakableBoxSmallHitbox);
    //o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    //o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void small_breakable_box_spawn_dust(void) {
    struct Object *smokeObj = spawn_object(o, MODEL_SMOKE, bhvSmoke);
    smokeObj->oPosX += (s32)(random_float() * 80.0f) - 40;
    smokeObj->oPosZ += (s32)(random_float() * 80.0f) - 40;
}

void small_breakable_box_act_move(void) {
    struct Object *Thwomp = cur_obj_nearest_object_with_behavior(bhvThwompKing);
    s8 mask;
    if(Thwomp == NULL) {
        obj_mark_for_deletion(o);
        return;
    }
    switch(Thwomp->oThwompKingCycle) { //for objects in more than one section, bparam2 is checked for its binary value and each bit represents a phase 011 would mean be active in the first 2 phases
        case 0: mask = 0x01; break;
        case 1: mask = 0x02; break;
        case 2: mask = 0x04; break;
    }
    if(gMarioCurrentRoom == 1 && ((o->oBehParams2ndByte & mask) != 0)){
        cur_obj_unhide();
        cur_obj_become_tangible();
    } else {
        cur_obj_hide();
        cur_obj_become_intangible();
    }

    if(o->oThwompKingCycle != gMarioCurrentRoom){
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY+50;
        o->oPosZ = o->oHomeZ;
    }
    o->oThwompKingCycle = gMarioCurrentRoom;
    o->oForwardVel = 40;
    o->oPosZ -= 31;
    if(o->oTimer%2 == 1) o->oPosY -= 22;
    else if(o->oTimer%9 == 1) o->oPosY -= 23;
    else o->oPosY -= 21;
    /*s16 collisionFlags = object_step();

    obj_attack_collided_from_other_object(o);

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        if (o->oForwardVel > 20.0f && gMarioCurrentRoom == 1) {
            cur_obj_play_sound_2(SOUND_ENV_SLIDING);
            //small_breakable_box_spawn_dust();
        }
    }


    obj_check_floor_death(collisionFlags, sObjFloor);*/
}

void breakable_box_small_released_loop(void) {
    o->oBreakableBoxSmallFramesSinceReleased++;

    // Begin flashing
    if (o->oBreakableBoxSmallFramesSinceReleased > 810) {
        COND_BIT((o->oBreakableBoxSmallFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
    }

    // Despawn, and create a corkbox respawner
    if (o->oBreakableBoxSmallFramesSinceReleased > 900) {
        create_respawner(MODEL_BREAKABLE_BOX, bhvBreakableBoxSmall, 3000);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void breakable_box_small_idle_loop(void) {
    switch (o->oAction) {
        case BREAKABLE_BOX_SMALL_ACT_MOVE:
            small_breakable_box_act_move();
            break;

        case OBJ_ACT_LAVA_DEATH:
            obj_lava_death();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            create_respawner(MODEL_BREAKABLE_BOX, bhvBreakableBoxSmall, 3000);
            break;
    }

}

void breakable_box_small_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oBreakableBoxSmallReleased = TRUE;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
}

void breakable_box_small_get_thrown(void) {
    cur_obj_become_tangible();

    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
    o->oForwardVel = 40.0f;
    o->oVelY = 20.0f;
    o->oBreakableBoxSmallReleased = TRUE;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
    o->activeFlags &= ~ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_breakable_box_small_loop(void) {
    small_breakable_box_act_move();

    s32 shake = 10 - o->oSpindelMoveTimer;

    if (shake < 0) {
        shake *= -1;
    }

    shake -= 6;
    if (shake < 0) {
        shake = 0;
    }

    if (o->oTimer == shake + 8) {
        o->oTimer = 0;
        o->oSpindelMoveTimer++;  
    }

    o->oAngleVelPitch = -1024;

    o->oPosZ += o->oVelZ;
    o->oMoveAnglePitch += o->oAngleVelPitch;
    
}
