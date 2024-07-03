#ifndef GM_ARRAY_H
#define GM_ARRAY_H

#include <stdbool.h>
#include "entity.h"

#define ARRAY_SIZE(a) (sizeof((a)) / sizeof((a)[0]))

/** -------------------------------------------------
* 
#define cbrt(X) _Generic((X), \
              long double: cbrtl, \
                  default: cbrt,  \
                    float: cbrtf  \
              )(X)
* 
 ------------------------------------------------- **/
 

size_t array_full_entity(Entity* ents, size_t size);



#endif // !GM_ARRAY_H
