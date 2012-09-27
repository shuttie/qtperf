qtperf
======

A port of [gtkperf](http://gtkperf.sourceforge.net/) tool to Qt.

qtperf is an application to test Qt graphics performance. It's idea is to draw a huge amount of predefined widgets on screen as fast as possible while measuring time. Actually, qtperf tries to mimic gtkperf's benchmarks, so their results should be comparable.

Qtperf can be used to test performance of:
* different Qt graphics engines (raster, native and opengl);
* Qt themes;
* QtGui library itself (to compare perfomance of different Qt versions);
* Xorg and it's video driver.