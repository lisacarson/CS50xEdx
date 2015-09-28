<?php
require("../includes/config.php"); 
if ($_SERVER["REQUEST_METHOD"] == "GET")
{
$from = urlencode($_GET["oName"]);
$to = urlencode($_GET["dName"]);
$new = "http://www.rome2rio.com/s/{$from}/{$to}";
header('Location: '.$new);

}
?>
