#!/usr/bin/env bash

if [ -z "$1" ]; then
    >&2 echo "Usage: \`./install.sh <program_name>\`"
    exit 1
fi

if [ ! -d ~/.local ]; then
	echo >&2 "ERROR: Unable to create symlink in" ~/.local/bin
	exit 1
fi

[ ! -d ~/.local/bin ] && mkdir ~/.local/bin

[ -L ~/.local/bin/"$1" ] && rm -f ~/.local/bin/"$1"

ln -s "$(pwd)/emulate" ~/.local/bin/"$1"

echo "Created symlink to \`$1\`."
