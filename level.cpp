#include "HeaderFiles/Level.h"
Level::Level(float px, float py, GolfHole hole, std::vector<Rectangle> Rectangles, std::vector<Vector3> Circles)
{
    this->Rectangles = Rectangles;
    this->Circles = Circles;
    this->px = px;
    this->py = py;
    GolfBall.push_back(Ball(px, py, 0, 0, 0, 0, 7.5, 1, false, 10));
    this->holex = hole.getx();
    this->holey = hole.gety();
    this->holeradius = hole.getRadius();
}

Level::~Level()
{
}

void Level::Draw()
{
    // rectangles
    for (auto rectangle : Rectangles)
    {
        DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, GREEN);
    }

    // green
    for (auto circle : Circles)
    {
        DrawCircle(circle.x, circle.y, circle.z, GREEN);
    }
    // Hole
    DrawCircle(holex, holey, holeradius, BLACK);
    // Draw Ball
}