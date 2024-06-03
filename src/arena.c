#include "arena.h"
#include <stdlib.h>
#include <stddef.h>

// Used for tracking. If 0 at end of program, all memory has been relased.
// If the number is above 0 then there is a memory leak.
static int allocation_count = 0;

/**
 * Initialize an arena.
 *
 * Allocated memory for the arena AND the for memory that it holds.
 *
 * @param size_t capacity    The amount of memory to allocate - in bytes.
 *
 * @return Arena*
 */
Arena* arena_init(size_t capacity)
{
    Arena* arena    = malloc(sizeof(Arena));
    allocation_count += 1;

    arena->size     = 0;
    arena->capacity = capacity;
    arena->position = 0;
    arena->data     = malloc(sizeof(size_t) * capacity);
	allocation_count += 1;

    return arena;
}

/**
 * Free all memory related to this Arena.
 *
 * @param Arena* arena
 */
void arena_release(Arena* arena)
{
    free(arena->data);
	allocation_count -= 1;

    free(arena);
	allocation_count -= 1;
}

/**
 * Get the current count of allocations.
 *
 * @return int
 */
int get_allocation_count()
{
	return allocation_count;
}
