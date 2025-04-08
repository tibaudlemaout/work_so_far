/*
** EPITECH PROJECT, 2024
** Semester_3
** File description:
** main
*/
#include<dlfcn.h>

// int main(void)
// {
//     void *handle;
//     void (*funcptr)(char *);

//     handle = dlopen("/home/tmaout/EPITECH/Semester_3/Assembly/B-ASM-400-NAN-4-1-asmminilibc-tibaud.le-maout/libmini.so\0", RTLD_LAZY);
//     if (handle) {
//         funcptr = dlsym(handle, "strlen");
//         (*funcptr)("hello world\n");
//         dlclose(handle);
//     }
//     // putstr("hello world\n");
//     return (0);
// }

#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void* handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    size_t (*strlen)(const char *);
    char* (*strchr)(const char *, int);
    char* (*strrchr)(const char *, int);
    int (*strcmp)(const char *, const char *);
    int (*strncmp)(const char *, const char *, size_t);
    int (*strcasecmp)(const char *, const char *);
    char* (*strstr)(const char *, const char *);
    //char* (*strpbrk)(const char *, const char *);
    //size_t (*strcspn)(const char *, const char *);

    strlen = dlsym(handle, "strlen");
    strchr = dlsym(handle, "strchr");
    strrchr = dlsym(handle, "strrchr");
    strcmp = dlsym(handle, "strcmp");
    strncmp = dlsym(handle, "strncmp");
    strcasecmp = dlsym(handle, "strcasecmp");
    strstr = dlsym(handle, "strstr");
    // strpbrk = dlsym(handle, "strpbrk");
    // strcspn = dlsym(handle, "strcspn");

    if (!strlen || !strchr || !strrchr || !strcmp || !strncmp ||
        !strcasecmp || !strstr) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // Test the functions
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

    // const char *string5 = "abcdefgh";
    // const char *set1 = "xyz";
    // printf("strpbrk result: %s\n", strpbrk(string5, set1));

    // const char *string6 = "abcde";
    // const char *set2 = "xyz";
    // printf("strcspn result: %zu\n", strcspn(string6, set2));

    dlclose(handle);

    return 0;
}
