#ifndef ENUM_H
#define ENUM_H

typedef char *Enum; ///< full enum definition body as a string

/**
 * @brief Define a regular enumeration plus a string to allow translation.
 * @see STRENUM()
 */
#define ENUM(NAME, ...)    \
    enum NAME __VA_ARGS__; \
    Enum strenum_##NAME = #__VA_ARGS__

/** 
 * @brief Allow the call to strenum() using the NAME declared with the ENUM() macro.
 * 
 */
#define STRENUM(NAME, num) strenum(strenum_##NAME, num)

/**
 * @brief Translate a number to the equivalent string in a given enum.
 * 
 * @param[in] e Enumeration full body as a string
 * @param[in] num Number to be translated
 * 
 * @return String translation
 */
extern char *strenum(const Enum e, int num);

#endif /* ENUM_H */