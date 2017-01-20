HOST_GCC=g++
TARGET_GCC=avr-g++
PLUGIN_SOURCE_FILES = avr-flash-vtbl.c
GCCPLUGINS_DIR:= $(shell $(TARGET_GCC) -print-file-name=plugin)
CXXFLAGS+= -I$(GCCPLUGINS_DIR)/include -fPIC -fno-rtti -O2

avr-flash-vtbl.so: $(PLUGIN_SOURCE_FILES)
	$(HOST_GCC) -shared $(CXXFLAGS) $^ -o $@
