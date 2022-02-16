#include "GameMath.h"
#include <cmath>

Vector2f NormalizeVector(Vector2f vec)
{
    Vector2f normalized;

    float d = hypot(vec.x, vec.y);
    normalized.x = vec.x / d;
    normalized.y = vec.y / d;

    return normalized;
}
float Distance(Vector2f from, Vector2f to)
{
    Vector2f dist = from - to;

    return hypot(dist.x, dist.y);
}

Vector2f Direction(Vector2f pointFrom, Vector2f pointTo)
{
    Vector2f dir = pointTo - pointFrom;

    return dir;
}

void DrawDebugLine(Vector2f pointFrom, Vector2f pointTo, RenderWindow* rw)
{
    sf::Vertex debugLine[2];

    debugLine[0] = pointFrom;
    debugLine[1] = pointTo;
    rw->draw(debugLine, 2, sf::Lines);
}

float GetCursorAngle(Vector2f objectPos, Vector2f cursorPos)
{
    float dX = cursorPos.x - objectPos.x;
    float dY = cursorPos.y - objectPos.y;
    float rotation = (atan2(dY, dX)) * 180 / 3.14159265;

    return rotation;
}

float GetRangomAngle(float range)
{
    float degrAngle = float(rand() % int(range * 2 + 1) - range);

    return degrAngle * 3.141 / 180;
}



