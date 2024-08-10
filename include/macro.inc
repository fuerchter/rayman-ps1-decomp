# Assembly Macros

.macro glabel label
    .global \label
    .balign 2
    \label:
.endm

.macro jlabel label
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

/* https://github.com/Xeeynamo/sotn-decomp/blob/e1391f8858c52b344534a047383127c1c5c17410/include/macro.inc#L13 */
.macro li reg, num
.if \num < 0x8000 && \num > 0
  ori \reg, $0, \num & 0xFFFF
.elseif \num > 0xFFFF
  lui \reg, %hi(\num)
  .if \num & 0xFFFF
    ori \reg, \reg, \num & 0xFFFF
  .endif
.elseif \num > 0
  ori \reg, $0, \num & 0xFFFF
.elseif \num == -0x8000
  addiu \reg, $0, \num & 0xFFFF
.elseif \num > -0x8000
  addiu \reg, $0, \num
.else
  lui \reg, (\num>>16) & 0xFFFF
  .if \num & 0xFFFF
    ori \reg, \reg, \num & 0xFFFF
  .endif
.endif
.endm

.macro move a, b
    addu \a, \b, $zero
.endm

.include "gte.inc"
