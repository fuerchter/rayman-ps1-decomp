#TODO:
#DISPLAY_UI HAS TO BE BUILT WITH .DATA ON NONMATCHING BUILD

#check out -psx patched old-gcc to possibly clean up DO_WORLD_MAP, DETER_WORLD_AND_LEVEL world_index assign
#skipTestArgs, readTestArgs share issues
#og psyq 3.0 cc1psx.exe seems to fix div_nop_swap:
#DISPLAY_TEXT_FEE (this has an actual swap, some have a missing_nop?)
#display_time, DISPLAY_SAVE_SPRITES, DISPLAY_CONTINUE_SPR, doMoskitoHit, setBossReachingSpeeds, DO_COMMANDE_PAD
#missing_nop INIT_PASTILLES_SAUVE, Fin_BB_Attaque

#missing_addiu: fake structs don't work for horloge (https://decomp.me/scratch/3YQbc) or cptr_tab (array/structs themselves), or rodata switch/case
#cc1psx.exe seems to fix these only for arrays/structs, not standard types
#arrays/structs involved in missing_addiu: horloge, block_flags, t_world_info, cptr_tab, D_801C7D20, PS1_AlwaysObjects, text_to_display, atak, SerieDatak
#standard type involved in missing_addiu: PS1_Setting_StereoEnabled

#apply MAX/MIN macros to code from before then
#for u8 < 2 or >= 2 conditions look at RAY_RESPOND_TO_DOWN e.g.
#PS1_star_spr adding "__attribute__((aligned(2)))" changed memcpy lw/sw into lwl/lwr etc. the address of it in the exe (or its data) did not change. check this for other data and functions that use it (INIT_LEVEL_STAGE_NAME, CHANGE_STAGE_NAMES)
#display_etoile memcpy changed when .data was added, will this happen for others? (INIT_LEVEL_STAGE_NAME e.g.)
#is there a way to inline EOA() (i couldn't find any yet), otherwise use macro? for example check MAIN_NO_MORE_CONTINUE_PRG
#when would someone actually have written do{}while(0); ? if(1) i can understand https://github.com/zeldaret/oot/pull/946 https://github.com/simonlindholm/decomp-permuter/issues/2 https://stackoverflow.com/questions/257418/do-while-0-what-is-it-good-for
#split some boss objs again?
#block_flags accesses could be cleaned up
#deal with WorldInfo.state
#can you just write / 2 instead of >> 1? (yes, sometimes removing s16 cast is needed)
#style: move assignment in if into second if. convert do/whiles into whiles where possible
#order splat yaml settings by wiki
#more enums, defines...
#use a bool type?
#what does this macro do? https://github.com/Xeeynamo/sotn-decomp/blob/e1391f8858c52b344534a047383127c1c5c17410/include/macro.inc#L13 https://discord.com/channels/1079389589950705684/1079395108501331990/1156337589465387128
#missing structs: PS1/Display, PS1/DRENVAndTile, PS1/FileInfo, psyq/DIRENTRY, psyq/EvDesc, psyq/EvMode, psyq/EvSpec
#ask about cd_cw, cd_read case issue
#rename duplicate memcpy, set_alarm in ghidra
#how to decompile ghidra_psx_ldr generated obj labels/functions in psyq?
#.data like DemoRecord might need incbin preprocessor stuff, see https://github.com/YohannDR/mzm/blob/e0f6976efb9d4be4b653d1c71ee803a8ef0599b3/tools/preproc/c_file.cpp#L326 ?
#.bss ? https://github.com/HighwayFrogs/frogger-psx/tree/main/vlo https://github.com/ethteck/splat/wiki/Segments#bss https://github.com/FoxdieTeam/mgs_reversing/tree/df66887a738d28581438b9cb5e77cd762223762d/src/data

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
GCC               := $(TOOLS_DIR)/gcc-2.5.7/gcc
GCC_FLAGS         := -c -mgas -msoft-float -B$(TOOLS_DIR)/gcc-2.5.7/ -pipe -Iinclude -fshort-enums -fno-builtin -gcoff
GCC_AS_FLAGS      := -Wa,-EL,-mips2,-msoft-float,-no-pad-sections,-Iinclude
LD                := $(CROSS)ld
LD_FLAGS          := -EL -T $(EXE).ld -T undefined_syms_auto.txt -T jtbl.txt -Map $(BUILD_EXE).map

ASM_FILES         := $(wildcard $(ASM_DIR)/**.s) $(wildcard $(ASM_DIR)/**/**.s)
SRC_FILES_O2      := $(wildcard $(SRC_DIR)/**.c) $(wildcard $(SRC_DIR)/**/**.c) $(wildcard $(SRC_DIR)/**/**/**.c)
SRC_FILES_O1      := 
SRC_FILES_SCRATCH := 
SRC_FILES_O2      := $(filter-out $(SRC_FILES_O1) $(SRC_FILES_SCRATCH), $(SRC_FILES_O2))

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
	$(GCC_SCR)gcc -c -mgas -msoft-float -B$(GCC_SCR) -pipe -Iinclude -fshort-enums -fno-builtin -gcoff -G0 -O2 -Wa,-EL,-mips2,-msoft-float,-no-pad-sections,-Iinclude -o $@ $<

check:
	sha1sum --check $(EXE).sha1

clean:
	rm -rf $(ASM_DIR) $(BUILD_DIR) $(EXE).ld undefined_funcs_auto.txt undefined_syms_auto.txt