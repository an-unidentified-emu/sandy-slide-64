void scroll_bits_dl_Cone_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 40;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cone_mesh_layer_1_vtx_0);

	deltaY = (int)(-4.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 121;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_mesh_layer_1_vtx_0);

	deltaY = (int)(-4.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 28;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_001_mesh_layer_1_vtx_0);

	deltaY = (int)(-4.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 100;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_003_mesh_layer_1_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits() {
	scroll_bits_dl_Cone_mesh_layer_1_vtx_0();
	scroll_bits_dl_Cube_mesh_layer_1_vtx_0();
	scroll_bits_dl_Cube_001_mesh_layer_1_vtx_0();
	scroll_bits_dl_Cube_003_mesh_layer_1_vtx_0();
};
