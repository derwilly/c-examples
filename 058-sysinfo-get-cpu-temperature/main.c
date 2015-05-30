/* Ferdinand Saufler <mail@saufler.de>
 * 30.05.2015
 * sysinfo - get cpu temperature
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *t_file;
    double temperature;
    t_file = fopen("/sys/class/thermal/thermal_zone0/temp","r");
    if(t_file == NULL)
    {
        printf("cant get file-descriptor form fopen()");
    }

    /* parse the temperature */
    fscanf(t_file,"%lf",&temperature);
    temperature /= 1000;

    /* print temperature */
    printf("The cpu-temperature is %4.1f °C\n",temperature);

    /* close the file descriptor */
    fclose(t_file);

	return 0;
}
