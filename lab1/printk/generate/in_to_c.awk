BEGIN {
    print "#include <stdio.h>";
    print "int main() {";
}

{
    printf "\tputs(\"--------%d--------\");\n", FNR
    printf "\tprintf(%s);\n", $0
    printf "\tputs(\"\\n--------%d--------\");\n", FNR
}

END {
    print "}"
}