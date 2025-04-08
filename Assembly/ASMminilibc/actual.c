/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** actual
*/

int main(void)
{
       const char *test_string = "Hello, World!";
    printf("strlen result: %d\n", strlen(test_string));

    const char *strchr_result = strchr(test_string, 'o');
    printf("strchr result: %s\n", strchr_result ? strchr_result : "NULL");

    const char *strrchr_result = strrchr(test_string, 'o');
    printf("strrchr result: %s\n", strrchr_result ? strrchr_result : "NULL");

    const char *string1 = "apple";
    const char *string2 = "banana";
    printf("strcmp result: %d\n", strcmp(string1, string2));

    const char *substring1 = "apples";
    const char *substring2 = "apple";
    printf("strncmp result: %d\n", strncmp(substring1, substring2, 5));

    const char *string3 = "Hello";
    const char *string4 = "hello";
    printf("strcasecmp result: %d\n", strcasecmp(string3, string4));

    const char *haystack = "This is a simple example.";
    const char *needle = "simple";
    printf("strstr result: %s\n", strstr(haystack, needle));

    const char *string5 = "abcdefgh";
    const char *set1 = "xyz";
    printf("strpbrk result: %s\n", strpbrk(string5, set1));

    const char *string6 = "abcde";
    const char *set2 = "xyz";
    printf("strcspn result: %zu\n", strcspn(string6, set2));
    return (0);
}