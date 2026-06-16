#!/usr/bin/env bash

if [ -z "$1" ]; then
    >&2 echo "Usage: \`./install.sh <program_name>\`"
    exit 1
fi

ln -s "$(dirname "${BASH_SOURCE[0]}")/emulate" ~/.local/bin/"$1"

echo "Created symlink to \`$1\`."
