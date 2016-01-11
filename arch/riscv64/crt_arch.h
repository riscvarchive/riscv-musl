__asm__(
".text\n"
".global " START "\n"
".type " START ",%function\n"
START ":\n\t"
"addi sp, sp, -16\n\t"
"jal " START "_c"
);

/* TODO: _DYNAMIC */
