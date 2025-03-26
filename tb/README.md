Debug Unit plus RI5CY Testbench
=====================

This testbench tests RI5CY together with a v0.13.1 compliant [debug
unit](https://www.github.com/pulp-platform/riscv-dbg). There are several tests
that can be run, but for now it is just `riscv test_compliance` of
[riscv-openocd](https://www.github.com/riscv/riscv-openocd) (see in
`pulpissimo.cfg`) and a not yet scripted run of gdb connecting to openocd,
loading and running a hello world program (see `prog/test.c`).

You need `openocd`, it can be downloaded from [https://github.com/xpack-dev-tools/openocd-xpack/](https://github.com/xpack-dev-tools/openocd-xpack/).


Running the testbench with [verilator](https://www.veripool.org/wiki/verilator)
----------------------
Point you environment variable `LLVM_TOOLCHAIN` to your RISC-V toolchain. Call `make
veri-run`. Use `VERI_FLAGS` to configure verilator e.g. `make firmware-veri-run
VERI_FLAGS="+firmware=path_to_firmware +vcd"` to use a custom firmware and dump
to a vcd file.


Options
----------------------
A few plusarg options are supported.
* `+verbose` to show all memory read and writes and other miscellaneous information.

* `+vcd` to produce a vcd file called `riscy_tb.vcd`. Verilator always produces
  a vcd file called `verilator_tb.vcd`.

* `+firmware=path_to_firmware` to load a specific firmware. It is a bit tricky to
build and link your own program. Look into the `prog` folder for an example.

Example Run
-----------------------
In each terminal from bellow, make sure you run `. ./eth.sh`  
1. `make veri-run`
2. (in new terminal) `openocd -f dm_compliance_test.cfg`
3. (in new terminal)  `riscv32-unknown-elf-gdb prog/test.elf`  
  3.1 (in gdb terminal) `target extended-remote localhost:3333`