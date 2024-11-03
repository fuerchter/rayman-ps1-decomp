TARGET            := slus-000.05
TYPE              := ps-exe

NUG_DIR           := tools/nugget
PSYQ_DIR		  := tools/psyq-3.0-converted
SRC_DIR           := src

CFLAGS            := -Iinclude -I$(PSYQ_DIR)/include -DNUGGET -G0 -fno-builtin -fno-toplevel-reorder
LDFLAGS           += -Xlinker --defsym=TLOAD_ADDR=0x80125000
LDFLAGS           += -L$(PSYQ_DIR)/lib -Wl,--start-group $(PSYQ_DIR)/lib/card.o $(PSYQ_DIR)/lib/pad.o -lapi -lc -lcd -lcard -lsnd -lspu -letc -lgte -lgpu -lpress -Wl,--end-group

SRCS              += $(wildcard $(SRC_DIR)/**.c) $(wildcard $(SRC_DIR)/**/**.c) $(wildcard $(SRC_DIR)/**/**/**.c)
SRCS              += $(NUG_DIR)/common/crt0/crt0.s

default: all

include $(NUG_DIR)/common.mk