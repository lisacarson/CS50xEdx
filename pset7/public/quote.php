<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via POST
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	$stock = lookup($_POST["symbol"]);
        // else render
        render("quote.php", ["title" => "QUOTE", "stock" => $stock]);
    }

    else
    {
	render("quote_form.php", ["title" => "Quote"]);
    }
	

   

?>
