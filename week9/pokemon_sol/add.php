<?
    /*
     * add.php
     *
     * Adds the pokemon with the provided fields into the database.
     */

    require("common.php");

    /* fail if some parameters are not set */
    // TODO
    if (!isset($_POST['name']) || !isset($_POST['type']) || !isset($_POST['level']))
        die("some parameters not set");

    /* escape MySQL queries and avoid XSS attacks */
    $name = htmlspecialchars(mysql_real_escape_string($_POST['name']));
    $type = htmlspecialchars(mysql_real_escape_string($_POST['type']));
    $level = intval(htmlspecialchars(mysql_real_escape_string($_POST['level'])));

    /* query to insert pokemon */
    // TODO
    $insert_query = sprintf("INSERT INTO pokemon (`name`,`type`,`level`)
                                VALUES ('%s', '%s', %d)", $name, $type, $level);
    $result = mysql_query($insert_query);

    /* make sure our query is successful */
    if (!$result)
        die("SELECT query failed");

    /* change the redirect header for your localhost!! */
    header("Location: http://localhost:8890/index.php");

?>