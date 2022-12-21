#include <stdbool.h>

/**
 * Asserts that |condition_result| is true. If it's not, the failure message is
 * printed and the process exits.
 */
extern void assert_true(bool condition_result, char* failure_message);
