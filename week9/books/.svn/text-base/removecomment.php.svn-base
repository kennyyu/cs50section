<?php
	//
	//	removecomment.php
	//	
	//	Removes a comment from the DB given POST parameters of 
	//		- uid
	//	

	// this is where we store our database login information
	// and establish a connection to the database 
	require("common.php");

	//clean the input data
	$uid = htmlspecialchars(mysql_real_escape_string($_POST['comment_uid']));

	//check for presence of input parameters
	if($uid > 65535 || $uid < 0)
	{
		die("uid not between 0 and 2^16 - 1 chars");
	}

	//create and run a mysql query
	$query = sprintf("DELETE FROM `comments` WHERE `uid` = %d", $uid);
	mysql_query($query);

?>