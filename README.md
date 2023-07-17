# gstreamer-tutorials

the basic gstreamer tutorial built with Cmake

## tutorials notes

Important APIs

- tutorial 1: hello world

    - create pipeline
        |||
        |-|-|
        |`gst_parse_launch`| -> Create a new pipeline based on command line syntax |
        || -> Returns a pointer to `GstPipeline` on success, `NULL` on failure. which should be  |
        || -> the returned pipeline should be destroyed at the end of the scope using `gst_object_unref`  |
        |||

    - get the bus element for the pipeline
        |||
        |-|-|
        |`gst_element_get_bus`| -> Returns the bus of the element and should be freed after usage using `gst_object_unref`
        |||

    - get a message from the bus
        |||
        |-|-|
        |`gst_bus_timed_pop_filtered`| -> Returns a `GstMessage`, or NULL. free when done with `gst_message_unref`
        |||
    
    - change element state
        |||
        |-|-|
        |`gst_element_set_state`| -> change element state. return type `GstStateChangeReturn` 
