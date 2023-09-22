#TODO:
#clean rule
#can psyq cc1psx and maspsx be run together somehow?

EXE			:= slus-000.05

ASM_DIRS	:= asm asm/data
SRC_DIRS	:= src
BUILD_DIR	:= build
TOOLS_DIR	:= tools
PSYQ_DIR	:= $(TOOLS_DIR)\psyq3.0
DOSEMURC	:= $(TOOLS_DIR)/psyq3.0/dosemurc

BUILD_EXE	:= $(BUILD_DIR)/$(EXE)

PYTHON		:= python3
SPLAT		:= $(PYTHON) $(TOOLS_DIR)/splat/split.py

CROSS		:= mips-linux-gnu-
AS			:= $(CROSS)as
AS_FLAGS	:= -EL -mips2 -msoft-float -no-pad-sections -Iinclude
CC1PSX		:= $(PSYQ_DIR)\CC1PSX.EXE
CC1PSX_FLAGS:= -O1
ASPSX		:= $(PSYQ_DIR)\ASPSX.EXE
LD			:= $(CROSS)ld
LD_FLAGS	:= -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(BUILD_EXE).map

ASM_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

default: $(BUILD_EXE) check

extract: dirs
	$(SPLAT) $(EXE).yaml

dirs:
	$(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

$(BUILD_EXE): $(BUILD_EXE).elf
	$(CROSS)objcopy -O binary $< $@

$(BUILD_EXE).elf: $(foreach file,$(ASM_FILES) $(SRC_FILES),$(BUILD_DIR)/$(file).o)
	$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

#see https://github.com/decompme/decomp.me/blob/45e8a9078424154a3177a4db5fa08aa930445295/backend/coreapp/compilers.py#L302
$(BUILD_DIR)/%.c.o: %.c
	cpp -P -Iinclude "$<" | unix2dos > object.oc
	(HOME="." dosemu -quiet -dumb -f $(DOSEMURC) -K . -E "$(CC1PSX) -quiet $(CC1PSX_FLAGS) -o object.os object.oc")
	#$(PYTHON) $(TOOLS_DIR)/maspsx/maspsx.py object.os > object.os_
	#$(AS) $(AS_FLAGS) -o $@ object.os_
	(HOME="." dosemu -quiet -dumb -f $(DOSEMURC) -K . -E "$(ASPSX) -quiet -o object.oo object.os")
	./tools/psyq-obj-parser -o $@ object.oo

check:
	sha1sum --check $(EXE).sha1