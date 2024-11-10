#include "arena.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#ifdef DEV_DEBUG
#include <stdio.h>
#else
#endif /* Inlcude printf for debugging. */


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

    arena->size      = 0;
    arena->sizeBytes = sizeof(size_t) * arena->size;
    arena->capacity  = sizeof(size_t) * capacity;
    arena->position  = 0;
    arena->data      = malloc(arena->capacity);
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

    #ifdef DEV_DEBUG
	printf("DEV: Arena data released. \n");
    #endif /* ifdef DEV_DEBUG */

    free(arena);
    allocation_count -= 1;

    #ifdef DEV_DEBUG
	printf("DEV: Arena released. \n");
    #endif /* ifdef DEV_DEBUG */
}

size_t arena_insert(Arena* arena, void* data, size_t size)
{
    /**
	If size is larger than capacity then dont try
	to fit any more data into it.
    **/
    if (arena->sizeBytes >= arena->capacity) {
        #ifdef DEV_DEBUG
            printf("Attempted Insert: %lu Bytes making capacity %lu. Actual Capacity %lu \n", size, size + arena->capacity ,arena->capacity);
            printf("Arena Full. Capacity is %lu bytes\n", arena->capacity);
        #endif /* ifdef DEV_DEBUG */
        return false;
    }

    size_t* tempData = malloc(size);
    *tempData = (size_t)data;

    size_t old_position = arena->size;
    arena->size += size;
    arena->sizeBytes += size;
    arena->position += size;

    printf("--------\n");
    printf("Passed in size %lu\n", size);
    memcpy(arena->data, tempData, size);

    free(tempData);

    #ifdef DEV_DEBUG
        printf("Inserted %lu bytes\n", size);
        printf("Size: %lu. Size Bytes:%lu ,Position: %lu \n\n", arena->size, arena->sizeBytes, arena->position);
    #endif /* ifdef DEV_DEBUG */

    return old_position;
}

/**
 * Get the current count of allocations.
 *
 * @return int
 */
int arena_get_allocation_count()
{
	return allocation_count;
}

