# gstreamer-tutorials

the basic gstreamer tutorial built with Cmake

## tutorials notes

notes about important gstreamer APIs used in the [basic tutorials](https://gstreamer.freedesktop.org/documentation/tutorials/basic/index.html?gi-language=c)

| **tutorial 1: Hello World!** |
| - |

### _Create A Pipeline_
```
GstElement * gst_parse_launch (const gchar * pipeline_description, GError ** error)
```
> Create a new pipeline based on command line syntax and returns a pointer to `GstPipeline` on success, `NULL` on failure. and the returned pipeline should be destroyed at the end of the scope using `gst_object_unref`  

### _get the bus element for the pipeline_
```
GstBus * gst_element_get_bus (GstElement * element)
```
> Returns the bus of the element and should be freed after usage using `gst_object_unref`

### _get a message from the bus_
```
GstMessage * gst_bus_timed_pop_filtered (GstBus * bus, GstClockTime timeout, GstMessageType types)
```
> Returns a `GstMessage`, or NULL. free when done with `gst_message_unref`

### _change element state_
```
GstStateChangeReturn gst_element_set_state (GstElement * element, GstState state)
```
> change element state. return type `GstStateChangeReturn`


| **tutorial 2: GStreamer concepts** |
| - |

### _Create a new element_

```
GstElement * gst_element_factory_make (const gchar * factoryname, const gchar * name)
```
> returns new `GstElement` or `NULL` if unable to create element.

### _Create a Pipeline_
```
GstElement * gst_pipeline_new (const gchar * name)
```
> Create a new pipeline with the given name. and the pipeline created should be destroyed at the end of the score with `gst_object_unref`
### _Add given elements to a bin_
```
gboolean gst_bin_add (GstBin * bin, GstElement * element)
```
> Adds the given element to the bin. this element can only be added to one bin. the function returns `TRUE` if the element could be added, `FALSE` if the bin does not want to accept the element.

```
gst_bin_add_many (GstBin * bin, GstElement * element_1, ... ...)
```
> Adds a NULL-terminated list of elements to a bin. This function is equivalent to calling `gst_bin_add` for each member of the list. The return value of each `gst_bin_add` is ignored

### _link elements_
```
gboolean gst_element_link_many (GstElement * element_1, GstElement * element_2, ... ...)
```
> Chain together a series of elements. make sure you have added your elements to a bin or pipeline with gst_bin_add before trying to link them. the function returns `TRUE` on success, `FALSE` otherwise.

### _set element properties_
```
void g_object_set (GObject* object, const gchar* first_property_name, ...)
```
> documentation found on [docs.gtk.org/gobject/method.Object.set](https://docs.gtk.org/gobject/method.Object.set.html#declaration)
