#include <iostream>
#include "raylib-cpp.hpp"
#include <cstdlib>

#define POINT_H

void update();
void render();

Vector2 mousePos;
Vector2 screenDimensions = {1000, 1000};
Vector2 pixelDimensions = {250, 250};

Vector2 ratio = {screenDimensions.x / pixelDimensions.x, screenDimensions.y / pixelDimensions.y};

bool debug = false;

int main() {

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    raylib::Window window(screenDimensions.x, screenDimensions.y, "Pixel simulation");

    SetTargetFPS(60);

    while (!window.ShouldClose()) {

        BeginDrawing();

        window.ClearBackground(BLACK);

        update();
        render();

        EndDrawing();
    }

    return 0;
}

void update() {
        mousePos = GetMousePosition();

        if (IsKeyPressed(KEY_P)) {
            debug = !debug;
        }
}

void render() {

    DrawCircle(mousePos.x, mousePos.y, 5, RED);

    if (debug) {
        
        for (int x = 1; x < pixelDimensions.x; x++) {
            DrawLine(x * ratio.x, 0, x * ratio.x, screenDimensions.y, WHITE);
        }
        for (int y = 1; y < pixelDimensions.y; y++) {
            DrawLine(0, y * ratio.y, screenDimensions.x, y * ratio.y, WHITE);
        }
    }

}
