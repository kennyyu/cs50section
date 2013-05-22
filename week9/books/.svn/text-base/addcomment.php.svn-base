<?php

    //
    //	addcomment.php
    //
    //  Adds a comment to the DB given POST parameters of
    //      - book_uid
    //      - comment
    //

	// this is where we store our database login information
	// and establish a connection to the database 
	require("common.php");

	//check for presence of input parameters
	if(!isset($_POST['book_uid']) || !isset($_POST['comment']))
	{
		die("some parameter was not set");
	}

	//clean the input data
	$book_uid = htmlspecialchars(mysql_real_escape_string($_POST['book_uid']));
	$comment = htmlspecialchars(mysql_real_escape_string($_POST['comment']));

	//make sure data is reasonable
	if($book_uid > 65535 || $book_uid < 0)
	{
		die("book_uid is not between 0 - 2^16");
	}
	if(strlen($comment) > 512 || strlen($comment) == 0)
	{
		die("comment not 0-512 chars");
	}

	//create and run a mysql query
	$query = sprintf("INSERT INTO `comments` (`book_uid`, `comment`) VALUES (%d,'%s')", $book_uid, $comment);
	mysql_query($query);
	
	//return the uid of comment
	$query = "SELECT uid FROM `comments` WHERE `book_uid` = $book_uid AND `comment` = '$comment' ORDER BY `uid` DESC LIMIT 0,1";
	$result = mysql_query($query);
	if($result)
    {
        $comment_uids = array();
        while($row = mysql_fetch_assoc($result))
        {
            $comment = array();
            $comment['uid'] = $row['uid'];
            $comment_uids[] = $comment;
        }
        echo(json_encode($comment_uids));  
    }

?>