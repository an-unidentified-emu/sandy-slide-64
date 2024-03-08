enum THWOMP_KING_ACTIONS{
    WAIT_FOR_MARIO,
    MARIO_ON_UPPER_SLOPE,
    MARIO_ON_LOWER_SLOPE,
    HIT
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
        o->oThwompKingCycle++;
        o->oTimer = 0;
    }
    else if (o->oTimer > 30) gCamera->cutscene = CUTSCENE_SNOW_HILL;
}

void mario_on_lower_slope(void){
    if (o->oTimer < 60) o->oPosY -= 200;
    else if (o->oTimer < 120) o->oPosY += 200;
    if(o->oTimer >= 60 && o->oTimer <= 120) {
        //set_camera_shake_from_point(SHAKE_POS_MASSIVE, gMarioObject->oPosX+(random_sign()*50), gMarioObject->oPosY+(random_sign()*50), gMarioObject->oPosZ+50);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
    }
    if (o->oTimer > 180) o->oTimer = 0;
}

void hit(void){
    if (o->oTimer < 60) o->oPosY -= 200;
    else if (o->oTimer < 80) o->oPosY += 600;
    if(o->oTimer >= 60) {
        //set_camera_shake_from_point(SHAKE_POS_MASSIVE, gMarioObject->oPosX+(random_sign()*50), gMarioObject->oPosY+(random_sign()*50), gMarioObject->oPosZ+50);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
    }
    if(gMarioCurrentRoom == 1) o->oAction = MARIO_ON_UPPER_SLOPE;
}

void bhv_thwomp_king_loop(void){
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
        case HIT:
            hit();
            break;
    }
    o->oDistanceToMario = 0;
}