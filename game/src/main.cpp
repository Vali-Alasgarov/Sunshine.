#include "rlImGui.h"
#include "Physics.h"
#include "Collision.h"
#include "raylib.h"

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Sunshine");
    rlImGuiSetup(true);

    Vector2 circlePos1 = { 200, 200 };  // Position for the stationary circle
    float radius1 = 50.0f;  

    Vector2 circlePos2 = { 0, 0 };  // Position for the circle controlled by mouse
    float radius2 = 30.0f;  

    // Color variables for circles
    Color color1 = RED;
    Color color2 = BLUE;

    SetTargetFPS(60);   // Set the application to run at 60 frames per second

   // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        circlePos2 = GetMousePosition();  // Update the position of the mouse-controlled circle

        // Check collision between the two circles
        if (CheckCollisionCircles(circlePos1, radius1, circlePos2, radius2))
        {
            color1 = GREEN;  // Change color of the circles when they overlap
            color2 = GREEN;
        }
        else
        {
            color1 = RED;  // Default color when not overlapping
            color2 = BLUE;
        }
      
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(circlePos1, radius1, color1);  // Draw the stationary circle
        DrawCircleV(circlePos2, radius2, color2);  // Draw the mouse-controlled circle

        EndDrawing();
        
    }

    
    CloseWindow();       
    

    return 0;
}

