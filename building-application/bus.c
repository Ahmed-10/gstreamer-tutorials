#include "bus.h"

GstBus * get_bus(GstElement* pipeline) {
  return gst_pipeline_get_bus (GST_PIPELINE (pipeline));
}

guint add_bus_watcher(GstBus * bus, GstBusFunc func, gpointer user_data) {
  return gst_bus_add_watch (bus, func, user_data);
}

void release_bus(GstBus * bus) {
  gst_object_unref (bus);
}