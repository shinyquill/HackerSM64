#include "src/game/envfx_snow.h"

const GeoLayout castle_inside_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, castle_inside_dl_1_Main_geo),
			GEO_BRANCH(1, castle_inside_dl_2_Replay_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11103, 0, -3459),
		GEO_ASM(  0, geo_painting_update),
     	GEO_ASM(PAINTING_ID(0, 1), geo_painting_draw),
    	GEO_ASM(PAINTING_ID(2, 1), geo_painting_draw),
    	GEO_ASM(PAINTING_ID(3, 1), geo_painting_draw),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_inside_dl_1_Main_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11103, 0, -3459),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11103, 0, 3459, castle_inside_dl_No_Collision_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, castle_inside_dl_No_Collision_mesh_layer_5),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11103, 0, 3459, castle_inside_dl_Plane_016_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_inside_dl_2_Replay_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -11103, 0, -3459),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11103, 0, 3459, castle_inside_dl_No_Collision_012_mesh_layer_1),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11103, 0, 3459, castle_inside_dl_Plane_014_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_inside_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_inside_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
