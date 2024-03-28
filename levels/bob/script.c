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
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
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
		WARP_NODE(0xFF, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC1, LEVEL_BOB, 0x01, 0xC1, WARP_CHECKPOINT),
		OBJECT(MODEL_FLYING_BOOST, 10978, 8606, 313, 0, 0, 0, 0x02010000, bhvFlyingBoost),
		OBJECT(MODEL_NONE, 11116, 7480, -3776, 0, 180, 0, 0x00C10000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 7023, -6262, 12275, 0, 0, 0, 0x00000000, bhvJetStream),
		OBJECT(MODEL_MUSHROOM_TOP, 10978, 7192, 313, 0, 0, 0, 0x02010000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 6288, 1418, 14693, 25, -112, 0, 0x02020100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 4549, 418, 13274, 25, 44, 0, 0x02010100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 921, -130, 2376, 25, 15, 0, 0x02020100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 11944, 4976, -12447, 25, 135, 0, 0x02010100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 14302, 5243, -14714, 25, -95, 0, 0x02010100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 11033, 5461, -14726, 0, 0, 0, 0x02000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 1643, 1470, 6018, 25, -123, 0, 0x01020100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, -1245, 2670, 4612, 25, 141, 0, 0x02020100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 13031, 5301, -10965, 0, 0, 0, 0x01000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 12855, -1763, -8749, 0, 0, 0, 0x01000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 13797, -2871, -1023, 0, 0, 0, 0x01000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 12187, -3473, 5985, 25, 28, 0, 0x01000100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 13312, -3882, 7740, 25, -56, 0, 0x01010100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 11443, -3993, 8886, 25, -21, 0, 0x01000100, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 8124, -4660, 12108, 0, 0, 0, 0x01000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 13027, -1964, -7450, 0, 0, 0, 0x01000000, bhvMushroomTop),
		OBJECT(MODEL_MUSHROOM_TOP, 11213, -3993, 8415, 25, -148, 0, 0x000100, bhvMushroomTop),
		OBJECT(MODEL_FLYING_BOOST, 12277, 8606, -7116, 0, 0, 0, 0x02010000, bhvFlyingBoost),
		OBJECT(MODEL_TRUNK, 1146, 2678, -4761, -10, 0, 0, 0x00000000, bhvRotatingTrunk),
		OBJECT(MODEL_NONE, 11447, 10780, 15349, 0, 180, 0, 0x000A0000, bhvInstantActiveWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_JUNGLE),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
