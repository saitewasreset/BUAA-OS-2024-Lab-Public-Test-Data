BEGIN {
    print "#include <stdio.h>";
    print "extern void printk(const char *fmt, ...);";
    print "int main() {";
}

{
    printf "\tputs(\"--------%d--------\");\n", FNR
    printf "\tprintk(%s);\n", $0
    printf "\tputs(\"\\n--------%d--------\");\n", FNR
}

END {
    print "}"
}