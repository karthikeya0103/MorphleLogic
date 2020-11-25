# Tests

Each circuit in this directory is a top level simulation-only device which tests the components found in the ../verilog directory.

The way to execute them is

    iverilog testNNNdescription.v
    ./a.out

Normally some output is printed or a .vcd file is generated which can then be examined with gtkwave.

### test001ycfsm.v

This puts the asynchronous finite state machine inside the basic Morphle Logic cell through its paces and prints out values from the tester and several internal signals of the fsm module. The use of internal signals helped debug the initial design, but might break this test if that design is changed in the future.

Many signals are two bit busses and can have the values 0 (indicating "empty"), 1 (indicating a logical 0) or 2 (indicating a logica 1). Some internal signals can be temporarily 3 but that normally shouldn't appear.

### test002ycfsm.v

This is the finite state machine being tested by this and the previous test. The expected output value is indicated by the color inside each circle representing the states. The input values are indicated by the color of the arrows, which can be hard to see due to the red stripes.

![Finite State Machine for basic Morphle Logic cell](ycfsmnum.png)

A separate file, "test002.tv", has the actual test vectors with one 7 bit vector per line. The reset signal is a single bit but all others are pairs with 00 indicating "empty", 01 indicating a logical 0 and 10 a logical 1. The last two bits are the expected value for the output and an error is printed if that is not what comes out of the actual circuit.

Since no internal signals are used, this test should work even if the circuit is changed as long as it still implements the fsm indicated above. In order to check that all transitions (arrows) are tested they were numbered and the test vector file has comments indicating where each transitions is tested for the first time. In order to get to a transition that hasn't yet been tested it is often necessary to go through many that have already been seen. That is the big problem with black box testing and why it is a good idea to include BIST (built-in self test circuits) in a design.