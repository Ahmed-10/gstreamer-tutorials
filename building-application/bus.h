#if !defined(BUS)
#define BUS

#include <gst/gst.h>

GstBus * get_bus(GstElement* pipeline);
guint add_bus_watcher(GstBus * bus, GstBusFunc func, gpointer user_data);
void release_bus(GstBus * bus);

#endif // BUS
