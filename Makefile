APPLICATION=myblink

BOARD ?= esp32-wroom-32

RIOTBASE ?= $(CURDIR)/../../RIOT
CFLAGS=-DLOG_LEVEL=LOG_DEBUG
DEVELHELP ?= 1
USEMODULE += schedstatistics
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps
USEMODULE +=xtimer

include $(RIOTBASE)/Makefile.include
