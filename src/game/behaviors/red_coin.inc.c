
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
    /* damageOrCoinValue: */ 2,
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


/**
 * Green coin's hitbox details.
 */
static struct ObjectHitbox sGreenCoinHitbox = {
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
void bhv_green_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenGreenCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenGreenCoinStar);
    if (hiddenGreenCoinStar != NULL) {
        o->parentObj = hiddenGreenCoinStar;
    } else {
        o->parentObj = NULL;
    }
    obj_set_hitbox(o, &sGreenCoinHitbox);
}

#define HIDDEN_GREEN_COIN_ACT_INACTIVE 0
#define HIDDEN_GREEN_COIN_ACT_WAITING 1
#define HIDDEN_GREEN_COIN_ACT_ACTIVE 2
#define HIDDEN_GREEN_COIN_ACT_FIRST 3

void bhv_green_coin_loop(void) {

    switch (o->oAction) {
        case HIDDEN_GREEN_COIN_ACT_INACTIVE:
            // Become invisible and intangible
            cur_obj_disable_rendering();
            cur_obj_become_intangible();

            struct Object *hiddenGreenCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenGreenCoinStar);
            if (hiddenGreenCoinStar != NULL) {
                o->parentObj = hiddenGreenCoinStar;
                o->oAction = HIDDEN_GREEN_COIN_ACT_WAITING;
            } else {
                o->parentObj = NULL;
            }

            break;

        case HIDDEN_GREEN_COIN_ACT_WAITING:
            if(o->parentObj->oAction == HIDDEN_STAR_ACT_ACTIVE) {
                obj_mark_for_deletion(o);
                break;
            }
            if(o->parentObj->oHiddenStarTriggerCounter ==  o->oBehParams2ndByte){
                if(o->oBehParams2ndByte == 0) o->oAction = HIDDEN_GREEN_COIN_ACT_FIRST;
                else o->oAction = HIDDEN_GREEN_COIN_ACT_ACTIVE;
            }
            break;

        case HIDDEN_GREEN_COIN_ACT_ACTIVE:
            // Become tangible
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // Delete the coin once collected
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                if(o->oSparkle == 0){
                    gMarioState->numCoins +=3;
                    o->oSparkle++;
                }
                spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                o->oAction = HIDDEN_GREEN_COIN_ACT_INACTIVE;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->parentObj->oHiddenStarTriggerCounter++;
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
                    else if (o->parentObj->oHiddenStarTriggerCounter == 1){}
                    else {
                        spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter-1, 0, 0, 0);
                    }
                }
            }

            // After 200 frames of waiting and 20 2-frame blinks (for 240 frames total),
            // delete the object.
            if (o->oTimer < 150) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                } else {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                }
            if (cur_obj_wait_then_blink(150, 20)) {

                o->oAction = HIDDEN_GREEN_COIN_ACT_INACTIVE;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->parentObj->oHiddenStarTriggerCounter = 0;

            }

            break;
        case HIDDEN_GREEN_COIN_ACT_FIRST:
         // Become tangible
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // Delete the coin once collected
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
                o->oAction = HIDDEN_GREEN_COIN_ACT_INACTIVE;
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->parentObj->oHiddenStarTriggerCounter++;
            }
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}


