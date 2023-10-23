#TODO:
#check out -psx patched old-gcc to possibly clean up DO_WORLD_MAP, DETER_WORLD_AND_LEVEL world_index assign
#skipTestArgs, readTestArgs share issues
#og psyq 3.0 cc1psx.exe seems to fix nop/divu swap: DISPLAY_CONTINUE_SPR (others in display_ui?), doMoskitoHit

#can you just write / 2 instead of >> 1? (yes, sometimes removing s16 cast is needed)
#style: move assignment in if into second if. convert do/whiles into whiles
#order splat yaml settings by wiki
#more enums, defines...
#use a bool type?
#what does this macro do? https://github.com/Xeeynamo/sotn-decomp/blob/e1391f8858c52b344534a047383127c1c5c17410/include/macro.inc#L13 https://discord.com/channels/1079389589950705684/1079395108501331990/1156337589465387128
#missing structs: PS1/Display, PS1/DRENVAndTile, PS1/FileInfo, psyq/DIRENTRY, psyq/EvDesc, psyq/EvMode, psyq/EvSpec
#ask about cd_cw, cd_read case issue
#rename duplicate memcpy, set_alarm in ghidra
#how to decompile ghidra_psx_ldr generated obj labels/functions in psyq?
#.data like DemoRecord might need incbin preprocessor stuff, see https://github.com/YohannDR/mzm/blob/e0f6976efb9d4be4b653d1c71ee803a8ef0599b3/tools/preproc/c_file.cpp#L326 ?
#.bss ? https://github.com/HighwayFrogs/frogger-psx/tree/main/vlo https://github.com/ethteck/splat/wiki/Segments#bss

EXE               := slus-000.05

ASM_DIR           := asm
BUILD_DIR         := build
EXP_DIR           := expected
SRC_DIR           := src
TOOLS_DIR         := tools

BUILD_EXE         := $(BUILD_DIR)/$(EXE)

PYTHON            := python3

CROSS             := mips-linux-gnu-
AS                := $(CROSS)as
AS_FLAGS          := -EL -mips2 -msoft-float -no-pad-sections -Iinclude
GCC   		      := $(TOOLS_DIR)/gcc-2.5.7/gcc
GCC_FLAGS	      := -c -mgas -msoft-float -B$(TOOLS_DIR)/gcc-2.5.7/ -pipe -Iinclude -fshort-enums -fno-builtin
GCC_AS_FLAGS      := -Wa,-EL,-mips2,-msoft-float,-no-pad-sections,-Iinclude
LD                := $(CROSS)ld
LD_FLAGS          := -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(BUILD_EXE).map

ASM_FILES         := $(wildcard $(ASM_DIR)/**.s) $(wildcard $(ASM_DIR)/**/**.s)
SRC_FILES_O2      := $(wildcard $(SRC_DIR)/**.c) $(wildcard $(SRC_DIR)/**/**.c)
SRC_FILES_O1      := 
SRC_FILES_SCRATCH := 
SRC_FILES_O2 	  := $(filter-out $(SRC_FILES_O1) $(SRC_FILES_SCRATCH), $(SRC_FILES_O2))

O_ASM             := $(foreach file,$(ASM_FILES),$(BUILD_DIR)/$(file).o)
O_SRC_O2          := $(foreach file,$(SRC_FILES_O2),$(BUILD_DIR)/$(file).o)
O_SRC_O1          := $(foreach file,$(SRC_FILES_O1),$(BUILD_DIR)/$(file).o)
O_SRC_SCRATCH     := $(foreach file,$(SRC_FILES_SCRATCH),$(BUILD_DIR)/$(file).o)

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

$(BUILD_EXE).elf: $(O_ASM) $(O_SRC_O2) $(O_SRC_O1) $(O_SRC_SCRATCH)
	$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

#see https://github.com/decompme/decomp.me/blob/45e8a9078424154a3177a4db5fa08aa930445295/backend/coreapp/compilers.py#L352
#-v for verbose output
$(O_SRC_O2) : $(BUILD_DIR)/%.o : %
	$(GCC) $(GCC_FLAGS) -G0 -O2 $(GCC_AS_FLAGS) -o $@ $<

$(O_SRC_O1) : $(BUILD_DIR)/%.o : %
	$(GCC) $(GCC_FLAGS) -G0 -O1 $(GCC_AS_FLAGS) -o $@ $<

GCC_SCR := $(TOOLS_DIR)/gcc-2.5.7/
$(O_SRC_SCRATCH) : $(BUILD_DIR)/%.o : %
	$(GCC_SCR)gcc -c -mgas -msoft-float -B$(GCC_SCR) -pipe -Iinclude -fshort-enums -G0 -O2 -Wa,-EL,-mips2,-msoft-float,-no-pad-sections,-Iinclude -o $@ $<

check:
	sha1sum --check $(EXE).sha1

clean:
	rm -rf $(ASM_DIR) $(BUILD_DIR) $(EXE).ld undefined_funcs_auto.txt undefined_syms_auto.txt