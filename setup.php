<?php

	$package=$_POST['mac'];
	$timeout =1;

	$socket  = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
	socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, array('sec' => $timeout, 'usec' => 0));
	socket_connect($socket, $host, $port);
	$ts = microtime(true);
	socket_send($socket, $package, strLen($package), 0);
	socket_close($socket);
	}




?>