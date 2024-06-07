#ifndef GM_QUADTREE_H
#define GM_QUADTREE_H

#include "raylib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    Rectangle* points[4];
    Rectangle boundary;
    size_t    capacity;
    bool      divided;

    struct QuadTree* nw;
    struct QuadTree* ne;
    struct QuadTree* sw;
    struct QuadTree* se;

} QuadTree;

/** ---------------------------------------------------------------------------
* Create a new QuadTree.
*
* @param Rectangle boundary    The boundary area for this Quadtree.
*
* @return QuadTree*
*/
QuadTree* quadtree_create(Rectangle boundary)
{
    QuadTree* tree = malloc(sizeof(QuadTree));

    tree->boundary = boundary;
    tree->capacity = 4;
    tree->divided  = false;

    tree->nw = NULL;
    tree->ne = NULL;
    tree->sw = NULL;
    tree->se = NULL;

    return tree;
}

/** ---------------------------------------------------------------------------
* Insert a new point into the QuadTree.
*
* @param QuadTree* qt       The Quadtree.
* @param Rectangle point    The point to insert.
*
* @return void.
*/
void quadtree_insert(QuadTree* qt, Rectangle point)
{

}


/** ---------------------------------------------------------------------------
* Free all of the Quadtree from memory.
*
* @param QuadTree* tree
*/
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



#endif // GM_QUADTREE_H
