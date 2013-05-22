<?php

    //
    //	add_book.php
    //
    //  Adds a book to the DB given POST parameters of
    //      - author
    //      - title
	//		- image_url
    //

	// this is where we store our database login information
	// and establish a connection to the database 
	require("common.php");

	//check for presence of input parameters
	if(!isset($_POST['author']) || !isset($_POST['title']) || !isset($_POST['image_url']))
	{
		die("some parameter was not set");
	}

	//clean the input data
	$author = htmlspecialchars(mysql_real_escape_string($_POST['author']));
	$title = htmlspecialchars(mysql_real_escape_string($_POST['title']));
	$image_url = htmlspecialchars(mysql_real_escape_string($_POST['image_url']));

	//make sure data is reasonable
	if(strlen($author) > 128 || strlen($author) == 0)
	{
		die("author not 0-128 chars");
	}
	if(strlen($title) > 128 || strlen($title) == 0)
	{
		die("title not 0-128 chars");
	}
	if(strlen($image_url) > 512)
	{
		die("image_url not less than 512 chars");
	}

	//create and run a mysql query
	$query = sprintf("INSERT INTO `books` (`author`, `title`, `image_url`) VALUES ('%s','%s','%s')", $author, $title, $image_url );
	mysql_query($query);
	
	//return the book_uid
	$query = "SELECT `uid` FROM `books` WHERE `author` = '$author' AND `title` = '$title' AND `image_url` = '$image_url' ORDER BY `uid` DESC LIMIT 0,1";
	$result = mysql_query($query);
	if($result)
    {
        $book_uids = array();
        while($row = mysql_fetch_assoc($result))
        {
            $book = array();
            $book['uid'] = $row['uid'];
            $book_uids[] = $book;
        }
        echo(json_encode($book_uids));  
    }

?>