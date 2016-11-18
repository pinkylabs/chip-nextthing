# http://stackoverflow.com/questions/3231804/in-bash-how-to-add-are-you-sure-y-n-to-any-command-or-alias

confirm () {
    # call with a prompt string or use a default
    read -r -p "${1:-Are you sure?} [Y/n] " response
    [[ $response =~ ^(yes|y)$ ]]
}

schrootBeginSession() {
    found=$(schroot -la | grep "session:$SESSION_NAME")
    if [ -z $found ]; then
        schroot --session-name $SESSION_NAME --begin-session --chroot $SCHROOT_SUITE-$SCHROOT_ARCH$SCHROOT_SUFFIX || exit $?
#    else
#	schroot --run-session --chroot $SESSION_NAME || exit $?
    fi
}

schrootCloseSession () {
    schroot -e -c $SESSION_NAME
}
