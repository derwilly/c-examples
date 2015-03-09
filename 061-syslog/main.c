/* Ferdinand Saufler <mail@saufler.de>
 * 01.03.2015
 * syslog exmaple
 * "man 2 syslog" and/or "man 3 openlog" */

#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    /* from "man 3 openlog":
     * LOG_CONS:
     * Write directly to system console if there is an error while sending
     * to system logger.
     *
     * LOG_PID:
     * Include PID with each message.
     *
     * LOG_NDELAY:
     * Open  the connection immediately (normally, the connection is opened
     * when the first message is logged).
     *
     * LOG_USER:
     * we log to facility LOG_USER (default).
     * for a custom logfile like /var/log/mylog/mylog use  LOG_LOCAL0
     * through LOG_LOCAL7. The targets can be configured in /etc/syslog.conf.
     * f.e.:
     * local0.*         /var/log/mylog
     */
    openlog ("syslog-example", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);
    syslog (LOG_INFO, "syslog-example started by user: %d", getuid ());
    syslog (LOG_ERR, "an error occured!");
    closelog ();

    return 0;
}
