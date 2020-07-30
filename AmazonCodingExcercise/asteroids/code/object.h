#pragma once

class Object
{
    public:
        struct Vector2Int
        {
            int x;
            int y;
        };

        // Position starts from top-left to bottom-right.
        Vector2Int position;
        Vector2Int size;
        float rotation;
};