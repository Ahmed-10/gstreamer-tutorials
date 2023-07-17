# gstreamer-tutorials

the basic gstreamer tutorial built with Cmake

## tutorials notes

notes about important gstreamer APIs used in the [basic tutorials](https://gstreamer.freedesktop.org/documentation/tutorials/basic/index.html?gi-language=c)

| **tutorial 1: hello world** |
| - |

### _Create A Pipeline_
```
GstElement* gst_parse_launch (const gchar * pipeline_description, GError ** error)
```
- Create a new pipeline based on command line syntax
- Returns a pointer to `GstPipeline` on success, `NULL` on failure. which should be  
- the returned pipeline should be destroyed at the end of the scope using `gst_object_unref`  

### _get the bus element for the pipeline_
```
GstBus* gst_element_get_bus (GstElement * element)
```
- Returns the bus of the element and should be freed after usage using `gst_object_unref`

### _get a message from the bus_
```
GstMessage* gst_bus_timed_pop_filtered (GstBus * bus, GstClockTime timeout, GstMessageType types)
```
- Returns a `GstMessage`, or NULL. free when done with `gst_message_unref`

### _change element state_
```
GstStateChangeReturn gst_element_set_state (GstElement * element, GstState state)
```
- change element state. return type `GstStateChangeReturn`
