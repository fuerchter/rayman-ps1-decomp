#TODO:
#structs: ActiveObjects next
#forgot to add diff_settings.py
#ask about cd_cw, cd_read case issue
#rename duplicate memcpy, set_alarm in ghidra

EXE         := slus-000.05

ASM_DIR     := asm
BUILD_DIR   := build
EXP_DIR     := expected
SRC_DIR     := src
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

ASM_FILES   := $(wildcard $(ASM_DIR)/**.s) $(wildcard $(ASM_DIR)/**/**.s)
SRC_FILES   := $(wildcard $(SRC_DIR)/**.c) $(wildcard $(SRC_DIR)/**/**.c)

default: $(BUILD_EXE) check

extract: splat dirs

splat: 
	mkdir -p $(ASM_DIR)
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(EXE).yaml

#also creates nonmatchings directory that is not needed
dirs:
	$(foreach dir,$(shell find $(ASM_DIR) -type d) $(shell find $(SRC_DIR) -type d),$(shell mkdir -p $(BUILD_DIR)/$(dir)))
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
	rm -rf $(ASM_DIR) $(BUILD_DIR) $(EXE).ld undefined_funcs_auto.txt undefined_syms_auto.txt