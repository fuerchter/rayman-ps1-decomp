EXE         := slus-000.05

ASM_DIRS    := asm asm/data
BUILD_DIR   := build
EXP_DIR     := expected
SRC_DIRS    := src
TOOLS_DIR   := tools

BUILD_EXE   := $(BUILD_DIR)/$(EXE)

PYTHON      := python3

CROSS       := mips-linux-gnu-
AS          := $(CROSS)as
AS_FLAGS    := -EL -mips2 -msoft-float -no-pad-sections -Iinclude
CC1         := $(TOOLS_DIR)/gcc-2.5.7/cc1
CC1_FLAGS   := -mgas -msoft-float -O1
LD          := $(CROSS)ld
LD_FLAGS    := -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(BUILD_EXE).map

ASM_FILES   := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
SRC_FILES   := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

default: $(BUILD_EXE) check

extract: dirs
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(EXE).yaml

dirs:
	$(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))
	mkdir -p $(EXP_DIR)

$(BUILD_EXE): $(BUILD_EXE).elf
	$(CROSS)objcopy -O binary $< $@

$(BUILD_EXE).elf: $(foreach file,$(ASM_FILES) $(SRC_FILES),$(BUILD_DIR)/$(file).o)
	$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

#see https://github.com/decompme/decomp.me/blob/45e8a9078424154a3177a4db5fa08aa930445295/backend/coreapp/compilers.py#L352
$(BUILD_DIR)/%.c.o: %.c
	cpp -P -Iinclude "$<" > $@.i
	$(CC1) -quiet $(CC1_FLAGS) -o $@1.s $@.i
	$(PYTHON) $(TOOLS_DIR)/maspsx/maspsx.py $@1.s > $@2.s
	$(AS) $(AS_FLAGS) -o $@ $@2.s

check:
	sha1sum --check $(EXE).sha1

clean:
	rm -rf build/ asm/ $(EXE).ld undefined_funcs_auto.txt undefined_syms_auto.txt