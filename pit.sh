#!/bin/bash

# Constants
readonly PIT_CONFIG_PATH=$(dirname "${BASH_SOURCE[0]}")
readonly PIT_COMMANDS_PATH=${PIT_CONFIG_PATH}/commands
readonly PIT_USER_DIRECTORY=~/.pit

# Include init scripts
source ${PIT_CONFIG_PATH}/init

function pit() {
    # Parse input
    local command=$1
    shift

    case $command in
        path)
            _pit-path $@
        ;;

        *)
            echo "The pit command improves commands"
            echo
            echo "Usage: pit <command> [<options>...]"
            echo
            echo "<command>"
            echo "      path    Define paths for use inside pit"
    esac

    return 0
}
