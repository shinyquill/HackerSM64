void scroll_jrb_dl_Plane_001_mesh_layer_1_vtx_14() {
	int i = 0;
	int count = 729;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Plane_001_mesh_layer_1_vtx_14);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_No_Collision_009_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 284;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_No_Collision_009_mesh_layer_5_vtx_3);

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
	scroll_jrb_dl_Plane_001_mesh_layer_1_vtx_14();
	scroll_jrb_dl_No_Collision_009_mesh_layer_5_vtx_3();
};
