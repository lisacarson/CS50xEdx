<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via POST
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	$stock = lookup($_POST["symbol"]);
	if (empty($stock))
	{
		apologize("You do not own that stock!");
	}
	
	else
	{
    
	$sharestemp = query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
	
	if(isset($sharestemp))
	{
		$shares = query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]) [0]['shares'];
		

	$stockprice = lookup($_POST["symbol"])["price"];
	$totalprice = $stockprice*$shares;
       	query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $totalprice, $_SESSION["id"]);
	

	
	query("INSERT INTO history (id, transactions, dateandtime, symbol, price, shares) VALUES(?, 'SELL', NOW(), ?, ?, ?)", $_SESSION["id"],$_POST["symbol"], $stockprice, $shares);
	
	redirect("/");
        }
        else
	{
		apologize("There are no shares to sell!");
	}
    	}
	}
    else
    {
	render("sell_form.php", ["title" => "Sell"]);
    }
	

   

?>