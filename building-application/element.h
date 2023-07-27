#if !defined(ELEMENT)
#define ELEMENT

#include <gst/gst.h>

GstElement * create_element(const gchar * factory_name, const gchar* name);
void release_element(GstElement * element);
GstElement * create_pipeline(const gchar * pipeline);
void release_pipeline(GstElement *element);

#endif // ELEMENT
