#include "intialize.h"
#include <gst/gst.h>
#include <stdio.h>

void init_g_streamer(int argc, const char *argv[]) {
  const gchar *nano_str;
  guint major, minor, micro, nano;

  gst_init(&argc, &argv);

  gst_version(&major, &minor, &micro, &nano);

  if (nano == 1)
    nano_str = "(CVS)";
  else if (nano == 2)
    nano_str = "(Prerelease)";
  else
    nano_str = "";

  printf("This program is linked against GStreamer %d.%d.%d %s\n", major, minor,
         micro, nano_str);
}