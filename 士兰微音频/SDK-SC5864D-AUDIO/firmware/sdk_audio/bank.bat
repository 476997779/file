::..\..\3-Tools\file_linker.exe -m1 obj\m0.bin 0x0 ..\..\4-Firmware\dspfw-ap1508.bin 0x10000 obj\prj_outfile.bin
::..\..\3-Tools\file_linker.exe -m1 obj\m0.bin 0x0 obj\prj_outfile.bin
fromelf --text -a -c --output=obj\m0.asm obj\m0.axf
