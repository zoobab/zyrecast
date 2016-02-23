//  Reads lines from stdin and sends to SMOOTH

#include <zyre.h>

int main (void)
{
    zyre_t *myself = zyre_new (NULL);
    zyre_start (myself);
    zyre_join (myself, "CHAT");

    while (true) {
        char buffer [1024];
        if (!fgets (buffer, 1024, stdin))
            break;
        buffer [strlen (buffer) - 1] = 0;
        zyre_shouts (myself, "CHAT", "%s", buffer);
    }
    zyre_destroy (&myself);
}
