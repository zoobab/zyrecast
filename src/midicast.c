//  Reads lines from stdin and sends to SMOOTH

#include <zyre.h>

int main (void)
{
    zyre_t *myself = zyre_new (NULL);
    zyre_start (myself);
    zyre_join (myself, "SMOOTH");

    while (true) {
        char buffer [1024];
        if (!fgets (buffer, 1024, stdin))
            break;
        zyre_shouts (myself, "SMOOTH", "%s", buffer);
    }
    zyre_destroy (&myself);
}
