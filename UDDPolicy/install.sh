#!/bin/bash
make && semodule -i ./udd.pp
restorecon /usr/sbin/UDDaemon /usr/sbin/UDDBus
 
