/* == Macros ==================================================================
*
* Helpers macros are defined in this file.
*
*/
#define POLYMORPHIC(e, var_name, cls) ((e)* (var_name) = ((e)*) &cls;)
