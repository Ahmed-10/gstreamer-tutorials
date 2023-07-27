#include "element.h"

GstElement *create_element(const gchar *factory_name, const gchar *name) {
  GstElementFactory * factory = gst_element_factory_find(factory_name);
  if (!factory) {
    g_print("Failed to find factory of type '%s'\n", factory_name);
    return -1;
  }
  GstElement * element = gst_element_factory_create(factory, name);
  if (!element) {
    g_print("Failed to create element, even though its factory exists!\n");
    return -1;
  }
  g_print("element %s has been created.\n", name);
  /* display information */
  g_print ("The '%s' element is a member of the category %s.\n"
           "Description: %s\n",
           gst_plugin_feature_get_name (GST_PLUGIN_FEATURE (factory)),
           gst_element_factory_get_metadata (factory, GST_ELEMENT_METADATA_KLASS),
           gst_element_factory_get_metadata (factory, GST_ELEMENT_METADATA_DESCRIPTION));
  return element;
}

void release_element(GstElement *element) {
  GstElementFactory *factory = gst_element_get_factory(element);
  gchar *name;
  g_object_get (G_OBJECT (element), "name", &name, NULL);
  g_print ("releasing element %s.\n", name);
  g_free (name);
  gst_object_unref(GST_OBJECT(element));
  gst_object_unref(GST_OBJECT(factory));
}

GstElement * create_pipeline(const gchar * pipeline) {
    return gst_pipeline_new(pipeline);
}

void release_pipeline(GstElement *element) {
gchar *name;
  g_object_get (G_OBJECT (element), "name", &name, NULL);
  g_print ("releasing %s.\n", name);
  gst_object_unref(GST_OBJECT(element));
}