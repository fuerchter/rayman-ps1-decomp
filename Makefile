#TODO:
#clean rule

EXE             := slus-000.05

ASM_DIRS        := asm asm/data
SRC_DIRS        := src
BUILD_DIR       := build
TOOLS_DIR       := tools

EXE_TARGET      := $(BUILD_DIR)/$(EXE)

PSYQ_DIR        := $(TOOLS_DIR)/psyq3.0
DOSEMURC        := $(TOOLS_DIR)/psyq3.0/dosemurc

PYTHON          := python3
SPLAT           := $(PYTHON) $(TOOLS_DIR)/splat/split.py

CROSS           := mips-linux-gnu-
AS              := $(CROSS)as -EL -mips2 -32 -msoft-float -no-pad-sections -Iinclude
AS_FLAGS        := -Wa,-EL,-march=r3000,-mtune=r3000,-msoft-float,-no-pad-sections,-Iinclude
CC1PSX          := $(PSYQ_DIR)\CC1PSX.EXE
CC1PSX_FLAGS    := -O1

GCC_INCLUDES    := -Iinclude
# GCC             := $(TOOLS_DIR)/gcc2.6.3-mipsel/gcc -c -B$(TOOLS_DIR)/gcc2.6.3-mipsel/ -pipe $(GCC_INCLUDES)
GCC             := $(TOOLS_DIR)/gcc2.7.2-mipsel/gcc -c -B$(TOOLS_DIR)/gcc2.7.2-mipsel/ -pipe $(GCC_INCLUDES)

CC_FLAGS        :=
SDATA_LIMIT     := -G0
OPT_FLAGS       := -O1
AS_SDATA_LIMIT  := -G0

ASPSX           := $(PSYQ_DIR)\ASPSX.EXE
LD              := $(CROSS)ld
LD_FLAGS        := -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(EXE_TARGET).map

ASM_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

default: $(BUILD_DIR)/$(EXE).exe check

dirs:
	$(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

extract: dirs
	$(SPLAT) $(EXE).yaml

clean:
	rm -rf build/ asm/

check:
	sha1sum --check $(EXE).sha1

$(EXE_TARGET).exe: $(EXE_TARGET).elf
	$(CROSS)objcopy -O binary $< $@

$(EXE_TARGET).elf: $(foreach file,$(ASM_FILES) $(SRC_FILES),$(BUILD_DIR)/$(file).o)
	$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) -o $@ $<

$(BUILD_DIR)/%.c.o: %.c
ifeq ($(USE_PSYQ),1)
#see https://github.com/decompme/decomp.me/blob/45e8a9078424154a3177a4db5fa08aa930445295/backend/coreapp/compilers.py#L302
	cpp -P -Iinclude "$<" | unix2dos > object.oc
	(HOME="." dosemu -quiet -dumb -f $(DOSEMURC) -K . -E "$(CC1PSX) -quiet $(CC1PSX_FLAGS) -o object.os object.oc")
	(HOME="." dosemu -quiet -dumb -f $(DOSEMURC) -K . -E "$(ASPSX)  -quiet -o object.oo object.os")
	./tools/psyq-obj-parser -o $@ object.oo
else
	$(GCC) $(CC_FLAGS) $(SDATA_LIMIT) $(OPT_FLAGS) $(AS_FLAGS),$(AS_SDATA_LIMIT) $< -o $@
endif
