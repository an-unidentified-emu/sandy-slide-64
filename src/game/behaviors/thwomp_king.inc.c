enum THWOMP_KING_ACTIONS{
    WAIT_FOR_MARIO,
    MARIO_ON_UPPER_SLOPE,
    MARIO_ON_LOWER_SLOPE,
    HIT_INITIATE,
    HIT,
    DEFEATED,
    SPAWN_STAR
};
void bhv_thwomp_king_init(void){}

void wait_for_mario(void){
    o->oThwompKingCycle = 0;
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, 
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_114)) {
            o->oAction = MARIO_ON_UPPER_SLOPE;
            }
}
  
void mario_on_upper_slope(void){
    if(gMarioCurrentRoom == 2) {
        o->oAction = MARIO_ON_LOWER_SLOPE;
        gCamera->cutscene = CUTSCENE_NONE;
        gCamera->mode = CAMERA_MODE_SLIDE_HOOT;
        o->oTimer = 0;
    }
    else if (o->oTimer > 0) gCamera->cutscene = CUTSCENE_SNOW_HILL;
}

void mario_on_lower_slope(void){
    if (o->oTimer < 60) o->oPosY -= 200;
    else if (o->oTimer < 120) o->oPosY += 200;
    if(o->oTimer >= 60 && o->oTimer <= 80) {
        set_camera_shake_from_point(SHAKE_POS_LARGE, gMarioObject->oPosX+(random_sign()*50), gMarioObject->oPosY+(random_sign()*50), gMarioObject->oPosZ+50);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
    }
    if (o->oTimer > 180) o->oTimer = 0;
}

void hit_initiate(void){
    if (o->oPosY < o->oHomeY) o->oPosY += 200;
    else {o->oAction = HIT;
        gMarioState->action = ACT_IDLE;
        o->oThwompKingCycle++;
        if(o->oThwompKingCycle >= 3) o->oAction = DEFEATED;
        //gCamera->cutscene = CUTSCENE_NONE;
        //gCamera->mode = CAMERA_MODE_SLIDE_HOOT;
    }
}
void hit(void){
    if (o->oTimer < 60) o->oPosY -= 200;
    else if (o->oTimer < 80) o->oPosY += 600;
    if(o->oTimer == 59) gPlayer1Controller->buttonPressed |= D_CBUTTONS;
    if(o->oTimer >= 60) {
        set_camera_shake_from_point(SHAKE_POS_MASSIVE, gMarioObject->oPosX+(random_sign()*50), gMarioObject->oPosY+(random_sign()*50), gMarioObject->oPosZ+50);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        gCamera->cutscene = CUTSCENE_SLIDING_DOORS_OPEN;
    }
    if(gMarioCurrentRoom == 1) {
        o->oAction = MARIO_ON_UPPER_SLOPE;
    }
}

void defeated(void){
    gCamera->cutscene = CUTSCENE_FACING;
    if (cur_obj_update_dialog(MARIO_DIALOG_LOOK_UP,
            (DIALOG_FLAG_TEXT_DEFAULT | DIALOG_FLAG_TIME_STOP_ENABLED), DIALOG_115, 0)) {
        cur_obj_hide();
        o->oAction = SPAWN_STAR;
            } else o->oTimer = 0;

}

void spawn_star_defeat(void) {
    if(o->oTimer == 0) spawn_object_relative_with_scale(0, 0, 2000, 0, 10000, o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
    if(o->oTimer <=60) set_camera_shake_from_point(SHAKE_POS_LARGE, 25, -2000, -10000);
    else {
        spawn_default_star(0.0f, -4029.0f, -7239.0f);
        cur_obj_play_sound_2(SOUND_OBJ_KING_WHOMP_DEATH);
        gCamera->cutscene = CUTSCENE_NONE;
        gCamera->mode = CAMERA_MODE_SLIDE_HOOT;
        gMarioState->action = ACT_IDLE;
        obj_mark_for_deletion(o);

    }
}

void bhv_thwomp_king_loop(void){
    if (gMarioState->health <= 0x0FF){
        o->oAction = WAIT_FOR_MARIO;
        gMarioCurrentRoom = 0;
    }
    switch (o->oAction) {
        case WAIT_FOR_MARIO: 
            wait_for_mario();
            break;
        case MARIO_ON_UPPER_SLOPE:
            mario_on_upper_slope();
            break;
        case MARIO_ON_LOWER_SLOPE:
            mario_on_lower_slope();
            break;
        case HIT_INITIATE:
            hit_initiate();
            break;
        case HIT:
            hit();
            break;
        case DEFEATED:
            defeated();
            break;
        case SPAWN_STAR:
            spawn_star_defeat();
    }
    o->oDistanceToMario = 0;
}