
# configuration

To configure webserv, you can use a configuration file. The file will be read once, at the start of the program. No changes can be passed to the server after starting the program.

By default the name of the configuration file is webserv.conf. If needed, another file can be specified as a parameter when starting the webserv program. The file `webserv.conf` is found in the `/config` folder. Config files can be found inside this folder or while using the absolute path as a parameter. The file has to have a name followed by the extention `.conf`.

---

## format 

The servers and locations are defined in blocks, for example:

```
server {
	/* context */
}
```

Inside the server block, the context can be defined in random order, on a single line ending with a semilocom or in a block (locations). Multiple values are seperated by a comma. The following options are available, if not set they will use their default values:

```
server {
	listen					localhost:80;
	server_names			default.org, www.default.org;
	index					index.html;
	client_max_body_size	1m;
	error_page	400			error400.html;
	error_page	404 		error404.html;
	location	/	{
		root				/;
		index				index.html;
		accept_files		off;
		cgi					.php;
		directry_listening	on;
		allowed_methods		GET, POST, DELETE;
		storage				storage;
		return				400 error400.html;
	}
}
```

The keywords `server`, `listen`, `server_name`, `cgi` and `allowed_methods` can be used multiple times inside one block and the multiple contexts will apply. On the contrary, if `index`, `client_max_body_size`, `error_page [n]`, `location [/]`, `accept_files`, `directry_listening`, `storage` or `return` are used multiple times, a warning is logged and only the last instance will be used.