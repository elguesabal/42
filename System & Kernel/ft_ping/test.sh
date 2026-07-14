# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/09 18:12:19 by joseanto          #+#    #+#              #
#    Updated: 2026/07/09 19:51:33 by joseanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"
HELP="
Usage
  ping [options] <destination>

Options:
  <destination>      dns name or ip address
  -v                 verbose output"
CURRENT_USER=${SUDO_USER:-$USER}

test() {
	local command="$1"
	local expected="$2"
	local output

	output=$(eval "$command" 2>&1)
	if [[ "$output" == "$expected" ]]; then
		result="${GREEN}OK${RESET}"
	else
		result="${RED}FAIL${RESET}"
	fi
	printf "%-50s %b\n" "$command" "$result"
}

test "./ft_ping" "ft_ping: usage error: Destination address required"
test "./ft_ping -v" "ft_ping: usage error: Destination address required"
test "./ft_ping -?" "$HELP"
test "./ft_ping -?v" "$HELP"
test "./ft_ping -v?" "$HELP"
test "./ft_ping -v -?" "$HELP"
test "./ft_ping -? -v" "$HELP"
test "./ft_ping -x" "ft_ping: invalid option -- 'x'"$'\n'"$HELP"
# test "./ft_ping google.com" ""
# test "./ft_ping -v google.com" ""
# test "./ft_ping google.com -v" ""
test "./ft_ping -? google.com" "$HELP"
test "./ft_ping google.com -?" "$HELP"
test "./ft_ping -?v google.com" "$HELP"
test "./ft_ping -v? google.com" "$HELP"
test "./ft_ping google.com -?v" "$HELP"
test "./ft_ping google.com -v?" "$HELP"
test "./ft_ping -? -v google.com" "$HELP"
test "./ft_ping -v -? google.com" "$HELP"
test "./ft_ping google.com -? -v" "$HELP"
test "./ft_ping google.com -v -?" "$HELP"
test "./ft_ping google.com 42.rio" "ft_ping: usage error: Invalid argument count"
test "./ft_ping vampeta.br" "ft_ping: vampeta.br: Name or service not known"
test "./ft_ping vampeta.42" "ft_ping: vampeta.42: Temporary failure in name resolution"
test "sudo -u $CURRENT_USER ./ft_ping google.com" "ft_ping: socket: Operation not permitted"