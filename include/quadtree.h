#ifndef GM_QUADTREE_H
#define GM_QUADTREE_H

#include "raylib.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "math.h"

typedef struct  QuadTree
{
    Rectangle* points[4];
    Rectangle boundary;
    size_t    capacity;
    size_t    size;
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
QuadTree* quadtree_create(Rectangle boundary);


/** ---------------------------------------------------------------------------
* Insert a new point into the QuadTree. 
*
* @param QuadTree* qt       The Quadtree.
* @param Rectangle point    The point to insert.
*
* @return void.
*/
void quadtree_insert(QuadTree* qt, Rectangle point);

/** ---------------------------------------------------------------------------
* Subdivide the Quadtree.
*
* @param QuadTree* qt       The Quadtree.
*
* @return void.
*/
void quadtree_subdivide(QuadTree* qt);


/** ---------------------------------------------------------------------------
* Free all of the Quadtree from memory.
*
* @param QuadTree* tree
*/
void quadtree_destroy(QuadTree* qt);



#endif // GM_QUADTREE_H
