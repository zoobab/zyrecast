//  Waits for a single text message in the CHAT group
//  prints to stdout; if there was no message then 
//  prints an empty line.

#include <zyre.h>

int main (void)
{
    zyre_t *zyre = zyre_new (NULL);
    zyre_start (zyre);
    zyre_join (zyre, "CHAT");

    zyre_event_t *event = NULL;
    while (!zsys_interrupted) {
        event = zyre_event_new (zyre);
        if (!event)
            break;
        if (zyre_event_type (event) == ZYRE_EVENT_SHOUT
        &&  streq (zyre_event_group (event), "CHAT"))
            break;
    }
    if (event) {
        zmsg_t *msg = zyre_event_msg (event);
        assert (msg);
        char *string = zmsg_popstr (msg);
        puts (string);
        free (string);
        zyre_event_destroy (&event);
    }
    else
        puts ("");
        
    zyre_destroy (&zyre);
    return 0;
}
