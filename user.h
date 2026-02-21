#pragma once
#ifndef USER_H
#define USER_H

typedef struct {
    char username[11];   // 10 characters + null terminator
    int level;           // 1 to 60
    char faction[6];     // red, blue, green
} User;

#endif