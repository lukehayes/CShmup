#ifndef GM_ARENA_H
#define GM_ARENA_H

#include <stddef.h>

typedef struct Arena {
    size_t size;
    size_t capacity;
    size_t position;
    void* data;
} Arena;


/**
 * Initialize an arena.
 *
 * Allocated memory for the arena AND the for memory that it holds.
 *
 * @param size_t capacity    The amount of memory to allocate - in bytes.
 *
 * @return Arena*
 */
Arena* arena_init(size_t capacity);

/**
 * Free all memory related to this Arena.
 *
 * @param Arena* arena
 */
void arena_release(Arena* arena);

/**
 * Get the current count of allocations.
 *
 * @return int
 */
int arena_get_allocation_count();


#endif // DEBUG

