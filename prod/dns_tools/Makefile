
include $(TOP_PATH)/targets/$(TARGETS_FILE)/config.mk
include $(TOP_PATH)/targets/$(TARGETS_FILE)/makefile.common

EXEC = dns_tools
OBJS = dns_tools.o

LDFLAGS += $(LDFLAGS_UGW)  
LDFLAGS += -lcommonprod
CFLAGS += -I$(TOP_PATH)/prod/common/inc

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC)  -o $@ $(OBJS) $(LDFLAGS) $(CFLAGS)
	$(CROSS_STRIP) $(EXEC)
	# cp $(EXEC) $(ROMFS_PATH)/bin

clean:
	-rm -f $(EXEC)  *.o
	-rm -f $(ROMFS_PATH)/bin/$(EXEC)
