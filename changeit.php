<?php$host = '192.168.1.12';$port = 23;echo "You have submitted something";$timeout =1;if ($_POST["status"] == "on"){$package = "1";}else{$package = "0";}$socket  = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, array('sec' => $timeout, 'usec' => 0));socket_connect($socket, $host, 23);$ts = microtime(true);socket_send($socket, $package, strLen($package), 0);socket_close($socket);/*if ($socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP) === false) {    echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";} else {    echo "OK.\n";}$on=204;$off=204;if ($_POST["status"] == "on")	{	socket_connect($socket, $host, $port);	socket_write($socket, $on);	socket_close($socket);	}	else 	{	socket_connect($socket, $host, $port);	socket_write($socket, $off);	socket_close($socket);	}*/		?>