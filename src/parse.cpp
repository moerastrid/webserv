#include "webserv.hpp"

static int	validate_configfile_name(std::string name, Config &config) {
	std::string suffix = ".conf";
	if ((name.length() <= suffix.length()) || 
		(name.compare(name.length() - suffix.length(), suffix.length(), suffix) != 0))
	{
		errorMessage("invalid configuration file name");
		return (1);
	}
	config.config_file = name;
	return (0);
}

static int	get_configfile(int argc, char **argv, Config &config) {
	switch (argc)
	{
		case 1:
			warningMessage("default .conf file");
			return (0);
		case 2:
			return (validate_configfile_name(argv[1], config));
	}
	errorMessage("ERROR - too many arguments");
	return (1);
}

int	parse(int argc, char **argv, Config &config) {
	if (get_configfile(argc, argv, config))
		return (1);
	ofstream configfile;
	return (0);
};
