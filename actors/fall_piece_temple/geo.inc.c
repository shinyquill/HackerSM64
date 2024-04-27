#include "src/game/envfx_snow.h"

const GeoLayout fall_piece_temple_FallPiece_2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fall_piece_temple_000_switch_001_displaylist_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fall_piece_temple_FallPiece_3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fall_piece_temple_000_switch_002_displaylist_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fall_piece_temple_FallPiece_4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fall_piece_temple_000_switch_003_displaylist_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fall_piece_temple_FallPiece_5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fall_piece_temple_000_switch_004_displaylist_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fall_piece_temple_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_CULLING_RADIUS(500),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(5, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, fall_piece_temple_000_displaylist_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, fall_piece_temple_FallPiece_2),
				GEO_BRANCH(1, fall_piece_temple_FallPiece_3),
				GEO_BRANCH(1, fall_piece_temple_FallPiece_4),
				GEO_BRANCH(1, fall_piece_temple_FallPiece_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
