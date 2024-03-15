#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 0x02, 0x0A, WARP_CHECKPOINT),
		OBJECT(MODEL_NONE, -5313, -3824, -7314, 0, 0, 0, 0xA9010000, bhvWarp),
		OBJECT(MODEL_NONE, -10231, 10318, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, -10231, 10318, 0),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_MENU_FILE_SELECT),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BITS, 0x01, 0x0A, WARP_CHECKPOINT),
		OBJECT(MODEL_GREEN_COIN, -6949, 9371, -9580, 0, 0, 0, (1 << 16), bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, -2407, 9377, -9920, 0, 0, 0, (2 << 16), bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2054, 7174, -3728, 0, 0, 0, (3 << 16), bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 2118, 6244, -1427, 0, 0, 0, (4 << 16), bhvGreenCoin),
		OBJECT(MODEL_GREEN_COIN, 1572, 1551, 6465, 0, 0, 0, (5 << 16), bhvGreenCoin),
		OBJECT(MODEL_1UP, -9351, 9705, -10101, 0, 0, 0, 0x00000000, bhvGreenCoin),
		OBJECT(MODEL_NONE, 7369, -3037, -13530, 0, 0, 0, (6 << 16), bhvHiddenGreenCoinStar),
		OBJECT(MODEL_NONE, 8777, -4125, -13472, 0, 0, 0, (70 << 24) | (2 << 16), bhvWarp),
		OBJECT(MODEL_NEW_THWOMP, -1158, -1472, 8810, 0, 90, 0, 0x00000000, bhvSidewaysThwomp),
		OBJECT(MODEL_NEW_THWOMP, -1581, -1757, 9902, 0, 90, 0, (0x01 << 16), bhvSidewaysThwomp),
		OBJECT(MODEL_NEW_THWOMP, -2114, -1997, 8810, 0, 90, 0, 0x00000000, bhvSidewaysThwomp),
		OBJECT(MODEL_NEW_THWOMP, -2537, -2282, 9902, 0, 90, 0, (0x01 << 16), bhvSidewaysThwomp),
		OBJECT(MODEL_THWIMP, -7136, 9343, -9605, 0, 0, 0, (0x01 << 24) | (0x15 << 16) | (100 << 8), bhvThwimp),
		OBJECT(MODEL_NONE, -10231, 10318, -10035, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x02, 0, -10231, 10318, -10035),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_MENU_FILE_SELECT),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x02, 0, -10231, 10318, -10035),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
