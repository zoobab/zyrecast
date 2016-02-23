#include <zyre.h>
#include <stdlib.h>

int main (void)
{
    zyre_t *zyre = zyre_new (NULL);
    zyre_start (zyre);
    zyre_join (zyre, "SMOOTH");

    while (!zsys_interrupted) {
        zyre_event_t *event = zyre_event_new (zyre);
        if (!event) {
            printf (" interrupted\n");
            break;
        }
        if (zyre_event_type (event) == ZYRE_EVENT_SHOUT) {
            if (streq (zyre_event_group (event), "SMOOTH")) {
                zyre_event_print (event);
		zyre_event_destroy (&event);
		zyre_destroy (&zyre);
		exit(EXIT_SUCCESS);
            }
        }
//        zyre_event_destroy (&event);
    }
//    zyre_destroy (&zyre);
//    return 0;
}
