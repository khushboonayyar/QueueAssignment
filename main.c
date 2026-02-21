
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: program numberOfUsers\n");
        return 1;
    }

    int numberOfUsers = atoi(argv[1]);

    if (numberOfUsers <= 0)
    {
        printf("Invalid number of users\n");
        return 1;
    }

    srand(time(NULL));

    Queue q;
    initQueue(&q);

    if (enqueueRandomUsers(&q, numberOfUsers) != 0)
    {
        printf("Error adding users\n");
        return 1;
    }

    User removed;

    while (!isEmpty(&q))
    {
        dequeue(&q, &removed);

        printf("Username: %s\n", removed.username);
        printf("Level: %d\n", removed.level);
        printf("Faction: %s\n", removed.faction);
        printf("-------------------------\n");
    }

    return 0;
}