<?
    /*
     * get.php
     *
     * Grabs all the pokemon with names that match the starting string.
     */
	header("content-type: text/plain");

    require("common.php");
    
    /* make sure type was provided */
    if (!isset($_GET["q"]))
        die("some parameter was not set");
    
    /* must escape user input */
    $fragment = htmlspecialchars(mysql_real_escape_string($_GET['q']));
    
    /* query to fetch all the pokemon with the certain type */  
    $select_query = "SELECT * FROM pokemon WHERE name REGEXP '^$fragment' LIMIT 0,10";
    $result = mysql_query($select_query);
    
    /* make sure our query is successful */
    if (!$result)
        die("SELECT query failed");
    
    /* $row is an associative array with the database field names */
    $pokemon = array();
    while ($row = mysql_fetch_assoc($result)) {
        $pokemon[] = $row;
    }
	echo(json_encode($pokemon));
?>