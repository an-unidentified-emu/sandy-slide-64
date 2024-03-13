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
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0xc, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bits_geo_000430), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bits_geo_000448), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bits_geo_000460), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bits_geo_000478), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bits_geo_000490), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bits_geo_0004A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bits_geo_0004C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bits_geo_0004D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bits_geo_0004F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bits_geo_000508), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bits_geo_000520), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bits_geo_000538), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bits_geo_000550), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bits_geo_000568), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bits_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bits_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bits_geo_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bits_geo_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SLIDING_PLATFORM, bits_geo_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TWIN_SLIDING_PLATFORMS, bits_geo_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_OCTAGONAL_PLATFORM, bits_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_BLUE_PLATFORM, bits_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_FERRIS_WHEEL_AXLE, bits_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_ARROW_PLATFORM, bits_geo_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SEESAW_PLATFORM, bits_geo_000670), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TILTING_W_PLATFORM, bits_geo_000688), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE, bits_geo_0006A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME1, bits_geo_0006B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME2, bits_geo_0006D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME3, bits_geo_0006E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME4, bits_geo_000700), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, 0, 14252, 19082),
		OBJECT(MODEL_THWOMP, 0, 24, -15978, 0, 0, 0, 0x00000000, bhvThwompKing),
		OBJECT(MODEL_BREAKABLE_BOX, 474, 4784, 7405, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 51, 4784, 7405, 3, 0, 0, (0x04 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -540, 5475, 8377, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -156, 7175, 10834, 3, 0, 0, (0x05 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -583, 7175, 10834, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 212, 9342, 13950, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -218, 9342, 13950, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 586, 8219, 12330, 3, 0, 0, (0x04 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 212, 8219, 12330, 3, 0, 0, (0x01 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -198, 8219, 12330, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -163, 6316, 9603, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 177, 5475, 8377, 3, 0, 0, (0x06 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 572, 10240, 15248, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -594, 9342, 13950, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 220, 10240, 15248, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -167, 10240, 15248, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -449, 4784, 7405, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -196, 5475, 8377, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -511, 6316, 9603, 3, 0, 0, (0x04 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -591, 8219, 12330, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 579, 9342, 13950, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -524, 10240, 15248, 3, 0, 0, 0x00000000, bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 555, 5475, 8377, 3, 0, 0, (0x02 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 162, 6316, 9603, 3, 0, 0, (0x02 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 540, 6316, 9603, 3, 0, 0, (0x01 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 224, 7175, 10834, 3, 0, 0, (0x03 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 584, 7175, 10834, 3, 0, 0, (0x06 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, 512, 3827, 6030, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_BREAKABLE_BOX, -436, 3827, 6030, 3, 0, 0, (0x07 << 16), bhvBreakableBoxSmall),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_NONE, 0, 2276, 3703, -3, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_RED_FLAME, 681, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -276, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -491, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 469, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1108, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 896, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1529, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1317, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 533, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 105, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -111, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 320, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 960, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 152, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 747, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1561, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1169, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1134, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1346, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -708, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -921, 7167, 9468, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -276, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -491, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -60, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 579, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 367, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1367, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 788, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, 1582, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1134, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -328, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -921, 2609, 2946, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1561, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1134, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1346, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -708, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -921, 5144, 6573, 3, 0, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -5, -4221, -7006, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch),
		TERRAIN(bits_area_1_collision),
		ROOMS(bits_area_1_collision_rooms),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
