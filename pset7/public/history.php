<?php

 // configuration
    require("../includes/config.php");
 
$histories = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);








render("history.php", ["histories" => $histories, "title" => "History"]);
?>