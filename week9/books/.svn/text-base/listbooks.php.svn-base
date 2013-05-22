<?php
	//
	//	listbooks.php
	//	
	//	Lists all of the books in the DB
	//	    - takes no parameters

	// this is where we store our database login information
	// and establish a connection to the database 
	require("common.php");

	// find all of the tasks
	$query = "SELECT * FROM `books` ORDER BY `uid`";
	$result = mysql_query($query);

    // if we've gotten a result, build up an array of 
    if($result)
    {
        $books = array();
        
        while($row = mysql_fetch_assoc($result))
        {
            //add an object for each task
            $book = array();
            $book['author'] = stripcslashes($row['author']);
            $book['title'] = stripcslashes($row['title']);
			$book['image_url'] = stripcslashes($row['image_url']);
			$book['uid'] = $row['uid'];
            
            //add this to the list of each task
            $books[] = $book;
        }
        
        // print out this JSON list of tasks, so our
        // javascript can see it and load it as data
        echo(json_encode($books));
        
    }

?>