<?
    /*
     * common.php
     *
     * Common code for all php files. This establishes a connection with the database.
     */

    /* change these to be your credentials for your appliance/cloud account */
    /* need to also change the redirect at the bottom of add.php */
    define("DB_USER","cs50");
    define("DB_PASS","cs50");
    define("DB_HOST","localhost");
    define("DB_NAME","cs50");
    
    /* create link to MySQL server using the provided credentials */
    $dblink = mysql_connect(DB_HOST, DB_USER, DB_PASS) 
        or die("Could not connect to MySQL server.");
    mysql_select_db(DB_NAME);
    
    /* create the pokemon table if it does not already exist */
    $create_table_query = "CREATE TABLE IF NOT EXISTS `{DB_NAME}`.`pokemon` (
                            `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
                            `name` VARCHAR( 255 ) NOT NULL ,
                            `type` VARCHAR( 255 ) NOT NULL ,
                            `level` INT( 255 ) NOT NULL
                            )";
    mysql_query($create_table_query);

?>