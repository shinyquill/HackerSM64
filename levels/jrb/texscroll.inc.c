void scroll_jrb_dl_No_Collision_009_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 284;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_No_Collision_009_mesh_layer_5_vtx_2);

	deltaY = (int)(-2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb() {
	scroll_jrb_dl_No_Collision_009_mesh_layer_5_vtx_2();
};
