TARGETS = sctp_client sctp_server sctp_bind sctp_bindx sctp_connectx sctp_set_params sctp_set_peer_addr sctp_set_pri_addr sctp_asconf_params_client sctp_asconf_params_server sctp_peeloff_server

DEPS = sctp_common.c sctp_common.h
CFLAGS ?= -Wall

LDLIBS += -lselinux -lsctp

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

$(TARGETS): $(DEPS)
