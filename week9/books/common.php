<?php

	//let's define constants here

	/*	
	define("DB_USER","cs179");
	define("DB_PASS","cs179hw6");
	define("DB_HOST","mysql.cs179.org");
	define("DB_NAME","cs179hw6");
	*/	

	
	define("DB_USER","cs179");
	define("DB_PASS","student");
	define("DB_HOST","localhost");
	define("DB_NAME","cs179");
	

	//create a DB connection

	$link = mysql_connect(DB_HOST, DB_USER, DB_PASS) or die('Could not connect to mysql server.');
	mysql_select_db(DB_NAME);

	//create books table
	$query = 
	"CREATE TABLE IF NOT EXISTS `cs179`.`books` (
	`uid` INT( 16 ) NOT NULL AUTO_INCREMENT ,
	`author` VARCHAR( 128 ) NOT NULL ,
	`title` VARCHAR( 128 ) NOT NULL ,
	`image_url` VARCHAR( 512 ) NOT NULL ,
	PRIMARY KEY (  `uid` ) ,
	UNIQUE (
	`uid`
	)
	)";
	mysql_query($query);
	
	//create comments table
	$query = 
	"CREATE TABLE IF NOT EXISTS `cs179`.`comments` (
	`uid` INT( 16 ) NOT NULL AUTO_INCREMENT ,
	`book_uid` INT( 16 ) NOT NULL ,
	`comment` VARCHAR( 512 ) NOT NULL ,
	PRIMARY KEY (  `uid` ) ,
	UNIQUE (
	`uid`
	)
	)";
	mysql_query($query);

?>