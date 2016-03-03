dpkg -l | grep beep > /dev/null
ret=$?
if test ${ret} -ne 0
then
    echo 1234 | sudo -S -p "" apt-get install beep > /dev/null
fi

sudo modprobe pcspkr
