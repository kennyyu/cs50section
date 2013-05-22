<?
    /*
     * index.php
     *
     * Grabs all the pokemon and spits them out in a table
     */

    require("common.php");
    
    /* query to fetch all the pokemon */
    // TODO
    $get_all_query = "SELECT * FROM pokemon";
    $result = mysql_query($get_all_query);
    
    /* make sure our query is successful */
    if (!$result)
        die("SELECT query failed");
    
    /* $row is an associative array with the database fiel names */
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
            <form action="add.php" method="post">
                <h2>Add Pokemon!</h2>
                <table>
                    <tbody>
                        <tr>
                            <td>Name:</td>
                            <td><input type="text" name="name"></td>
                        </tr>
                        <tr>
                            <td>Type:</td>
                            <td>
                                <input type="radio" name="type" value="leaf">leaf<br>
                                <input type="radio" name="type" value="water">water<br>
                                <input type="radio" name="type" value="fire">fire<br>
                                <input type="radio" name="type" value="thunder">thunder                                                                                             
                            </td>
                        </tr>
                        <tr>
                            <td>Level:</td>
                            <td>
                                <select name="level">
                                    <option value="10">10</option>
                                    <option value="20">20</option>
                                    <option value="30">30</option>
                                    <option value="40">40</option>
                                    <option value="50">50</option>
                                    <option value="60">60</option>
                                    <option value="70">70</option>
                                    <option value="80">80</option>
                                    <option value="90">90</option>
                                    <option value="100">100</option>                                                                                                                                                                                                                                                                                                                                    
                                </select>
                            </td>
                        </tr>
                        <tr>
                            <td colspan="2">
                                <input type="submit" value="Add pokemon!">
                            </td>
                        </tr>
                    </tbody>
                </table>
            </form>
        </div>
        <div class="section">
            <h2>Filter by Type:</h2>
            <a href="gettype.php?type=leaf">leaf</a>, 
            <a href="gettype.php?type=fire">fire</a>, 
            <a href="gettype.php?type=water">water</a>, 
            <a href="gettype.php?type=thunder">thunder</a>                                  
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
                            // TODO : print out the the information into the table
                            echo "<tr>";
                            echo "<td>" . $individual["id"] . "</td>";
                            echo "<td>" . $individual["name"] . "</td>";
                            echo "<td>" . $individual["type"] . "</td>";
                            echo "<td>" . $individual["level"] . "</td>";                                                       
                            echo "</tr>";
                        }
                    ?>
                </tbody>
            </table>
        </div>
    </body>
</html>