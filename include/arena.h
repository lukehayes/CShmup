#ifndef GM_ARENA_H
#define GM_ARENA_H

#include <stddef.h>

typedef struct Arena {
    size_t size;
    size_t sizeBytes;
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
 * Insert some data into the memory arena
 *
 * @param Arena*  arena    A pointer to a memory arena.
 * @param void*   data     The data to insert.
 * @param size_t  size     The size of the data.
 *
 * @return size_t  size    Returns 0 if failiure, 1 otherwise.
 */
size_t arena_insert(Arena* arena, void* data, size_t size);

/**
 * Get the current count of allocations.
 *
 * @return int
 */
int arena_get_allocation_count();


#endif // DEBUG

