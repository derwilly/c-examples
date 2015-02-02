typedef struct Address
{
    char *fname;
    char *lname;
    char *email;
    int age;
} Address;

Address *createAdress(char *fname, char *lname, char *email, int age);
void destroyAddress(Address *adr);
void printAddress(Address *adr);
