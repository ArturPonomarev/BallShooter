#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;


Vector2f NormalizeVector(Vector2f vec);
float Distance(Vector2f from, Vector2f to);
Vector2f Direction(Vector2f pointFrom, Vector2f pointTo);
void DrawDebugLine(Vector2f pointFrom, Vector2f pointTo, RenderWindow* rw);
float GetCursorAngle(Vector2f objectPos, Vector2f cursorPos);

float GetRangomAngle(float range); //ѕолучить угол в радианах от -range до range (range в градусах)