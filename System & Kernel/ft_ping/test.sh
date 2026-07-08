#!/bin/bash

DESTINATION_ADDRESS_REQUIRED="ft_ping: usage error: Destination address required"
INVALID_OPTION="ft_ping: invalid option --"
INVALID_ARGUMENT_COUNT="ft_ping: usage error: Invalid argument count"
HELP="
Usage
  ping [options] <destination>

Options:
  <destination>      dns name or ip address
  -v                 verbose output"

test() {
	local command="$1"
	local expected="$2"
	local output

	output=$(eval "$command" 2>&1)
	if [[ "$output" == "$expected" ]]; then
		result="OK"
	else
		result="FAIL"
	fi
	printf "%-30s %s\n" "$command" "$result"
}

test "./ft_ping" "$DESTINATION_ADDRESS_REQUIRED"
test "./ft_ping -v" "$DESTINATION_ADDRESS_REQUIRED"
test "./ft_ping -?" "$HELP"
test "./ft_ping -?v" "$HELP"
test "./ft_ping -v?" "$HELP"
test "./ft_ping -v -?" "$HELP"
test "./ft_ping -? -v" "$HELP"
test "./ft_ping -x" "$INVALID_OPTION 'x'"$'\n'"$HELP"
# test "./ft_ping google.com" "$"
test "./ft_ping google.com 42.rio" "$INVALID_ARGUMENT_COUNT"
# test "./ft_ping -v google.com" "$"
# test "./ft_ping google.com -v" "$"
test "./ft_ping -?v google.com" "$HELP"
test "./ft_ping google.com -?v" "$HELP"