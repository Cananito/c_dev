_Pragma("clang assume_nonnull begin")

/**
 * Asserts that |condition_result| is true. If it's not, the failure message is
 * printed and the process exits.
 */
extern void assert_true(int condition_result, char *failure_message);

_Pragma("clang assume_nonnull end")
