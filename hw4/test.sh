nasm -f elf64 -g -F dwarf perimeter.asm -o perimeter.o;
nasm -f elf64 -g -F dwarf sort.asm -o sort.o;
g++ -g -o task main.cpp sort.o container.cpp shape.cpp rectangle.cpp triangle.cpp circle.cpp perimeter.o -no-pie;
./task -f tests/test1/tests_1 tests/test1/testrun_out1 tests/test1/testrun_out2;
./task -f tests/test2/tests_2 tests/test2/testrun_out1 tests/test2/testrun_out2;
./task -f tests/test3/tests_3 tests/test3/testrun_out1 tests/test3/testrun_out2;
./task -f tests/test4/tests_4 tests/test4/testrun_out1 tests/test4/testrun_out2;
./task -f tests/test5/tests_5 tests/test5/testrun_out1 tests/test5/testrun_out2;