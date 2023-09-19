EXE			:= slus-000.05

ASM_DIRS	:= asm asm/data
BUILD_DIR	:= build
TOOLS_DIR	:= tools

PYTHON		:= python3
SPLAT		:= $(PYTHON) $(TOOLS_DIR)/splat/split.py

CROSS		:= mips-linux-gnu-
AS			:= $(CROSS)as
AS_FLAGS	:= -EL -mips2 -msoft-float -no-pad-sections -Iinclude
LD			:= $(CROSS)ld
LD_FLAGS	:= -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(EXE).map

ASM_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))

default: $(EXE).exe

dirs:
	$(foreach dir,$(ASM_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

extract:
	$(SPLAT) $(EXE).yaml

#clean:
#	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(EXE).elf: $(foreach file,$(ASM_FILES),$(BUILD_DIR)/$(file).o)
	$(LD) $(LD_FLAGS) -o $@

$(EXE).exe: $(EXE).elf
	$(CROSS)objcopy -O binary $(EXE).elf $@