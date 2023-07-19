# gstreamer-tutorials

the basic gstreamer tutorial built with Cmake

## tutorials notes

notes about important gstreamer APIs used in the [basic tutorials](https://gstreamer.freedesktop.org/documentation/tutorials/basic/index.html?gi-language=c)


---
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

---
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

---
| **tutorial 3: Dynamic pipelines** |
| - |
### _link a source pad with sink element_
```
#define g_signal_connect (instance, detailed_signal, c_handler, data)
```
> Connects a `GCallback` function to a signal for a particular object. find more in documentation [docs.gtk.org/gobject/func.signal_connect](https://docs.gtk.org/gobject/func.signal_connect.html#declaration)

### _get a pointer to an existing element pad_
```
GstPad * gst_element_get_static_pad (GstElement * element, const gchar * name)
```
> Retrieves a pad from element by name. This version only retrieves already-existing 'static' pads. and returns the requested `GstPad` if found, otherwise `NULL`. unref after usage with `gst_object_unref`.

### _check if pad is linked to another_
```
gboolean gst_pad_is_linked (GstPad * pad)
```
>  Returns `TRUE` if the pad is linked, `FALSE` otherwise
### _get pad current capabilities_
```
GstCaps * gst_pad_get_current_caps (GstPad * pad)
```
> Gets the capabilities currently configured on pad. Returns the current caps of the pad <u>with incremented ref-count</u> or `NULL` when pad has no caps. Unref after usage with `gst_caps_unref`.

### _get the caps structure_

```
GstStructure * gst_caps_get_structure (const GstCaps * caps, guint index)
```
> Finds the structure in caps at index, and returns it.
### _get the string structure_
```
const gchar * gst_structure_get_name (const GstStructure * structure)
```
> returns the name of structure as a string.
### _link source pad to sink pad_
```
GstPadLinkReturn gst_pad_link (GstPad * srcpad, GstPad * sinkpad)
```
> Links the source pad and the sink pad.
### _unref element caps_
```
gst_caps_unref (GstCaps * caps)
```
> Unrefs a `GstCaps` and frees all its structures and the structures' values when the refcount reaches 0.

---
| **tutorial 4: Time management** |
| - |

### _get stream position_
```
gboolean gst_element_query_position (GstElement * element, GstFormat format, gint64 * cur)
```
> Queries an element for the stream position in nanoseconds. This will be a value between 0 and the stream duration <br/>
> _**Parameters**_: <br/> 
> **element**: a GstElement to invoke the position query on. <br/>
> **format**: the GstFormat requested <br/>
> **cur**: a location in which to store the current position, or `NULL`. <br/> 
> _**Returns**_ `TRUE` if the query could be performed. <br/> 


### _get stream duration_
```
gboolean gst_element_query_duration (GstElement * element, GstFormat format, gint64 * duration)
```
> Queries an element for the total stream duration in nanoseconds. If the duration changes for some reason, you will get a `DURATION_CHANGED` message on the pipeline bus, in which case you should re-query the duration using this function. <br/>
> _**Parameters**_: <br/> 
> **element**: a GstElement to invoke the position query on. <br/>
> **format**: the GstFormat requested <br/>
> **duration**: a location in which to store the current position, or `NULL`. <br/> 
> _**Returns**_ `TRUE` if the query could be performed. <br/> 


### _seek stream to position_
```
gboolean gst_element_seek_simple (GstElement * element, GstFormat format, GstSeekFlags seek_flags, gint64 seek_pos)
```
> perform a seek on the given element to the given position relative to the start of the stream.

### _get error and debug string from message_
```
gst_message_parse_error (GstMessage * message, GError ** gerror, gchar ** debug)
```
> Extracts the `GError` and debug string from the `GstMessage`. The values returned in the output arguments are copies; <u>the caller must free them when done</u>.

### _get states from message_
```
gst_message_parse_state_changed (GstMessage * message, GstState * oldstate, GstState * newstate, GstState * pending)
```
> Extracts the old and new states from the `GstMessage`.

### _get state string from state_
```
const gchar * gst_element_state_get_name (GstState state)
```
> Gets a string representing the given state.

### _Create query object_
```
GstQuery * gst_query_new_seeking (GstFormat format)
```
> Constructs a new query object for querying seeking properties of the stream. the output `GstQuery` object should be destroyed with `gst_query_unref`

### _pass query to an element_
```
gboolean gst_element_query (GstElement * element, GstQuery * query)
```
> return `TRUE` if the query could be performed. 

### _parse GstQuery type seeking_
```
gst_query_parse_seeking (GstQuery * query, GstFormat * format, gboolean * seekable, gint64 * segment_start, gint64 * segment_end)
```
> Parse a seeking query, writing the results into the passed parameters. <br/>
> _**Parameters**_: <br/> 
> **query**: a `GST_QUERY_SEEKING` type query `GstQuery` <br/>
> **format**: [out] the format to set for the `segment_start` and `segment_end` values, or `NULL` <br/>
> **seekable**: [out] the seekable flag to set, or `NULL`. <br/> 
> **segment_start**: [out] the segment_start to set, or `NULL`. <br/> 
> **segment_end**: [out] the segment_end to set, or `NULL`. <br/> 

### _destroy query object_
```
gst_query_unref (GstQuery * q)
```
> Decreases the refcount of the query. If the refcount reaches 0, the query will be freed.

---
| **tutorial 5: GUI toolkit integration** |
| - |

### _install Gtk 3.0_
```bash
sudo apt-get install libgtk-3-dev
```
### _display video output to a specific window_
```
gst_video_overlay_set_window_handle (GstVideoOverlay * overlay, guintptr handle)
```
> This will call the video overlay's set_window_handle method. You should use this method to tell to an overlay to display video output to a specific window 

---
| **tutorial 6: Media formats and Pad Capabilities** |
| - |

### _get an element by name_
```
GstElementFactory * gst_element_factory_find (const gchar * name)
```
> Search for an element factory of the given name. Refs the returned element factory; caller is responsible for unreffing usung `gst_object_unref`.

### _get element pad template_
```
const GList * gst_element_factory_get_static_pad_templates (GstElementFactory * factory)
```
> Gets the GList of GstStaticPadTemplate for this factory.

### _convert static caps to element caps_
```
GstCaps * gst_static_caps_get (GstStaticCaps * static_caps)
```
> Converts a `GstStaticCaps` to a `GstCaps`. should be freed after usage with `gst_caps_unref`

### _caps media format check_
```
gboolean gst_caps_is_any (const GstCaps * caps)
```
> Determines if caps represents any media format.

### _caps no media format check_
```
gboolean gst_caps_is_empty (const GstCaps * caps)
```
> Determines if caps represents no media formats.

### _numbrer of structures in caps_
```
guint gst_caps_get_size (const GstCaps * caps)
```
> Gets the number of structures contained in caps.

### _apply function to a structure fields_
```
gboolean gst_structure_foreach (const GstStructure * structure, GstStructureForeachFunc func, gpointer user_data)
```
> Calls the provided function once for each field in the `GstStructure`. The function must not modify the fields. returns `True` if the supplied function returns `TRUE` For each of the fields, `FALSE` otherwise.


### _query pad capabilities_
```
GstCaps * gst_pad_query_caps (GstPad * pad, GstCaps * filter)
```
> Gets the capabilities this pad can produce or consume. Returns the caps of the pad with incremented ref-count. needs to be unref using `gst_caps_unref`
