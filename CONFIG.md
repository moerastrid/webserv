
# config file

To configure webserv, use a configuration file. The file will be read once, at the start of the program. No changes can be configured after starting the program.

By default the name is webserv.conf, another file can be specified as a parameter when starting the webserv program.

---

## format 

The servers, error_pages and locations are defined in blocks, for example:

```
server {
	/* context */
}
```


Inside the server block, the context can be defined in random order, on a single line ending with a semilocom or in a block (locations & error_pages). Multiple values are seperated by a comma. The following options are available, if not set they will use their default values:

```
server {
	listen					localhost:80;
	server_names			default.org, www.default.org;
	index					index.html;
	client_max_body_size	1m;
	error_page {
		400 				error400.html;
		404 				error404.html;

	}
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
