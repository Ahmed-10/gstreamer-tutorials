#include "pad.h"

gboolean link_elements_pads(GstElement *src, const gchar *src_pad_name,
                            GstElement *dest, const gchar *dest_pad_name) {
  return gst_element_link_pads(src, src_pad_name, dest, dest_pad_name);
}

GstPad *request_pad(GstElement *element, const gchar *name) {
  GstPad *pad = gst_element_get_request_pad(element, name);
  gchar *pad_name = gst_pad_get_name(pad);
  g_print("A new pad %s was created\n", pad_name);
  g_free(pad_name);
}

void release_pad(GstPad *pad) {
  /* free our reference */
  gst_object_unref(GST_OBJECT(pad));
}

GstPadLinkReturn link_pads(GstPad *src_pad, GstPad *sink_pad) {
  return gst_pad_link(src_pad, sink_pad);
}

void link_pad_to_element(GstPad *to_link_pad, GstElement *element) {
  gchar *src_name, *sink_name;

  src_name = gst_pad_get_name(to_link_pad);
  GstPad *pad = gst_element_get_compatible_pad(element, to_link_pad, NULL);
  gst_pad_link(to_link_pad, pad);
  sink_name = gst_pad_get_name(pad);
  gst_object_unref(GST_OBJECT(pad));

  g_print("A new pad %s was created and linked to %s\n", sink_name, src_name);
  g_free(sink_name);
  g_free(src_name);
}

void print_pad_props(GstCaps *caps) {
  gint width, height;
  const GstStructure *str;

  g_return_if_fail(gst_caps_is_fixed(caps));

  str = gst_caps_get_structure(caps, 0);
  if (!gst_structure_get_int(str, "width", &width) ||
      !gst_structure_get_int(str, "height", &height)) {
    g_print("No width/height available\n");
    return;
  }

  g_print("The video size of this set of capabilities is %dx%d\n", width,
          height);
}

gboolean link_elements_with_caps_filter(GstElement *element1,
                                        GstElement *element2, GstCaps *caps) {
  gboolean link_ok = gst_element_link_filtered(element1, element2, caps);
  gst_caps_unref(caps);

  if (!link_ok) {
    g_warning("Failed to link element1 and element2!");
  }

  return link_ok;
}
