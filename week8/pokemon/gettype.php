<?
    /*
     * gettype.php
     *
     * Grabs all the pokemon of the given type and spits them out.
     */

    require("common.php");
    
    /* make sure type was provided */
    // TODO
    
    /* must escape user input */
    $type = htmlspecialchars(mysql_real_escape_string($_GET['type']));
    
    /* query to fetch all the pokemon with the certain type */  
    // TODO
    $select_query = "";
    $result = mysql_query($select_query);
    
    /* make sure our query is successful */
    if (!$result)
        die("SELECT query failed");
    
    /* $row is an associative array with the database field names */
    $pokemon = array();
    while ($row = mysql_fetch_assoc($result)) {
        $pokemon[] = $row;
    }

?>

<!DOCTYPE html>

<html>
    <head>
        <title>Pokemon: Gotta catch 'em all!</title>
        <link rel="stylesheet" type="text/css" href="styles.css">
    </head>
    <body>
        <div class="section">
            <h1>My Pokedex</h1>
        </div>
        <div class="section">
            <h2>Pokemon I've Seen:</h2>
            <table id="list">
                <thead>
                    <tr>
                        <th>id</th>
                        <th>name</th>
                        <th>type</th>
                        <th>level</th>
                    </tr>
                </thead>
                <tbody>
                    <? 
                        foreach($pokemon as $individual) {
                            // TODO print out the information into the table
                        }
                    ?>
                </tbody>
            </table>
        </div>
    </body>
</html>