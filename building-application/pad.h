#if !defined(PAD)
#define PAD

#include <gst/gst.h>

gboolean link_elements_pads(GstElement * src, const gchar * src_pad_name, GstElement * dest, const gchar * dest_pad_name);
GstPad * request_pad(GstElement* element, const gchar *name);
void release_pad(GstPad * pad);
GstPadLinkReturn link_pads(GstPad *src_pad, GstPad *sink_pad);
void link_pad_to_element(GstPad * to_link_pad, GstElement * element);
void print_pad_props(GstCaps *caps);
gboolean link_elements_with_caps_filter(GstElement *element1,
                                        GstElement *element2, GstCaps *caps);

#endif // PAD
