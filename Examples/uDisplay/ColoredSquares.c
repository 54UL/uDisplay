void draw_cube(uDisplay* display, uint8_t x, uint8_t y, uint32_t color) {
  struct uDBufferDescriptor cube = {
    .x = x,
    .y = y,
    .w = CUBE_SIZE,
    .h = CUBE_SIZE,
    .length = CUBE_SIZE * CUBE_SIZE * 2 // 2 bytes per pixel
  };

  uint8_t data[CUBE_SIZE * CUBE_SIZE * 2];
  for (int i = 0; i < CUBE_SIZE * CUBE_SIZE * 2; i += 2) {
    data[i] = (color >> 8) & 0xFF;
    data[i + 1] = color & 0xFF;
  }

  display->StartDrawCall(cube);
  display->DrawBuffer(cube);
  display->CommitDrawCall(cube);
}

void draw_random_cubes(uDisplay* display) {
  for (int i = 0; i < 10; i++) {
    uint8_t x = rand() % (SCREEN_WIDTH - CUBE_SIZE);
    uint8_t y = rand() % (SCREEN_HEIGHT - CUBE_SIZE);
    uint32_t color = rand() % 0xFFFFFF; // 24-bit color
    draw_cube(display, x, y, color);
  }
}

int main() {
  // initialize underlying protocol and driver
  struct uDisplayUnderlyingProtocol protocol = {...};
  struct uDisplayDriver driver = {...};
  driver.Init(&protocol);

  // initialize display
  struct uDRenderConfig config = {
    .protocol = &protocol,
    .driver = &driver
  };
  uDisplay display = {...};
  display.Initialize(&config);

  // draw random colored cubes
  draw_random_cubes(&display);

  // clean up
  display.Dispose();
  driver.Dispose();

  return 0;
}