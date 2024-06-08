#include "quadtree.h"

#include "raylib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "math.h"

QuadTree* quadtree_create(Rectangle boundary)
{
    QuadTree* tree = malloc(sizeof(QuadTree));

    tree->boundary = boundary;
    tree->capacity = 4;
    tree->size     = 0;
    tree->divided  = false;

    for(int i = 0; i<= tree->capacity - 1; i++)
    {
        tree->points[i] = NULL;
    }

    tree->nw = NULL;
    tree->ne = NULL;
    tree->sw = NULL;
    tree->se = NULL;

    return tree;
}

void quadtree_insert(QuadTree* qt, Rectangle point)
{
    if(!rect_inside(point, qt->boundary))
    {
        return;
    }

    if(qt->size < qt->capacity)
    {
        qt->points[qt->size] = &point;
        qt->size += 1;
    }

    if (!qt->divided) 
    {
        quadtree_subdivide(qt);
        qt->divided = true;
    }

    quadtree_insert(qt->ne, point);
    quadtree_insert(qt->nw, point);
    quadtree_insert(qt->se, point);
    quadtree_insert(qt->sw, point);
}

void quadtree_subdivide(QuadTree* qt)
{
    float newXP     = qt->boundary.x;
    float newYP     = qt->boundary.y;
    float newWidth  = qt->boundary.width / 2;
    float newHeight = qt->boundary.height / 2;

    Rectangle nw = {.x = newXP, .y = newYP, .width = newWidth, .height = newHeight };
    Rectangle ne = {.x = newXP + newWidth, .y = newYP, .width = newWidth, .height = newHeight};
    Rectangle sw = {.x = newXP,  .y = newYP + newHeight, .width = newWidth, .height = newHeight};
    Rectangle se = {.x = newXP + newWidth, .y = newYP + newHeight, .width = newWidth, .height = newHeight};

    qt->ne = quadtree_create(ne);
    qt->nw = quadtree_create(nw);
    qt->se = quadtree_create(se);
    qt->sw = quadtree_create(sw);
}

void quadtree_destroy(QuadTree* qt)
{
    if (qt->nw) 
    {
        free(qt->nw);
        qt->nw = NULL;
    }

    if (qt->ne) 
    {
        free(qt->ne);
        qt->ne = NULL;
    }

    if (qt->sw) 
    {
        free(qt->sw);
        qt->sw = NULL;
    }

    if (qt->se) 
    {
        free(qt->se);
        qt->se = NULL;
    }

    free(qt);
    qt = NULL;
}
