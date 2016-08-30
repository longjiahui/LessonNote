
#include <stdio.h>
#include <pwd.h>


struct passwd *find_uid(int uid);
int main(int argc, char *argv[])
{
	int uid;
	struct passwd *pwd;

	if (argc < 2)
	{
		printf("usage: ./a.out uid \n");
		return 1;
	}

	uid = atoi(argv[1]);

	pwd = find_uid(uid);
	pwd = find_uid(uid);
	if (pwd)
		printf("%d : %s\n", pwd->pw_uid, pwd->pw_name);
	else
		printf("not found\n");

	return 0;
}

struct passwd *find_uid(int uid)
{
	struct passwd *pwd;

	setpwent();
	while ((pwd = getpwent()) != NULL)
	{
		if (pwd->pw_uid == uid)
			return pwd;
	}

	return NULL;
}
