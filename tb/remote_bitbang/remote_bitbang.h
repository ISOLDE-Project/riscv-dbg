// See LICENSE.Berkeley for license details.

#ifndef REMOTE_BITBANG_H
#define REMOTE_BITBANG_H

#include <stdint.h>
#include <sys/types.h>
#include "svdpi.h"

extern "C" int
jtag_tick(int port, svBit *jtag_TCK, svBit *jtag_TMS, svBit *jtag_TDI,
          svBit *jtag_TRSTn, svBit jtag_TDO);
void
rbs_stop();

#define VERBOSE 0

extern int rbs_err;

extern unsigned char tck;
extern unsigned char tms;
extern unsigned char tdi;
extern unsigned char trstn;
extern unsigned char tdo;
extern unsigned char quit;

extern int socket_fd;
extern int client_fd;



// Create a new server, listening for connections from localhost on the given
// port.
int
rbs_init(uint16_t port);

// Do a bit of work.
void
rbs_tick(svBit *jtag_TCK, svBit *jtag_TMS, svBit *jtag_TDI, svBit *jtag_TRSTn,
         svBit jtag_TDO);

unsigned char
rbs_done();

int
rbs_exit_code();

// Check for a client connecting, and accept if there is one.
void
rbs_accept();
// Execute any commands the client has for us.
// But we only execute 1 because we need time for the
// simulation to run.
void
rbs_execute_command();

void
rbs_reset(); // Assert TRST
void
rbs_set(); // Deassert TRST

void
rbs_set_pins(char _tck, char _tms, char _tdi);

#endif
