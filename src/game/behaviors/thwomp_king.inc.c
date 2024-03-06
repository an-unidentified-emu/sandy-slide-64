enum THWOMP_KING_ACTIONS{
    WAIT_FOR_MARIO,
    MARIO_ON_UPPER_SLOPE
};
void bhv_thwomp_king_init(void){}

void wait_for_mario(void){
    if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP, 
            DIALOG_FLAG_TURN_TO_MARIO, CUTSCENE_DIALOG, DIALOG_114)) {
            o->oAction = MARIO_ON_UPPER_SLOPE;
            }
}
  
void mario_on_upper_slope(void){
    if(o->oTimer > 500) gInstantWarpsOff = TRUE;
    gCamera->cutscene = CUTSCENE_SNOW_HILL;
}
void bhv_thwomp_king_loop(void){
    switch (o->oAction) {
        case WAIT_FOR_MARIO: 
            wait_for_mario();
            break;
        case MARIO_ON_UPPER_SLOPE:
            mario_on_upper_slope();
            break;
    }
    o->oDistanceToMario = 0;
}