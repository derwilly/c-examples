/*_Static_assert()
 * compile this and it will fail until you set i greater than 3. */

int main()
{
    const int i = 3;
    _Static_assert (i > 3, "i needs to be greater than 3!");

	return 0;
}
