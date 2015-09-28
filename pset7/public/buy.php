<?php

    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	
	if (empty($_POST["shares"]) || empty($_POST["symbol"]))
	{
		apologize("Form requires shares and symbol");
	}

	if (preg_match("/^\d+$/", $_POST["shares"]=== true))
	{ 
		apologize("Positive numbers only, please!");
	}
	$_POST["symbol"] = strtoupper($_POST["symbol"]);
	if (lookup($_POST["symbol"]) === false)
	{
		apologize("Symbol does not exist");
	}
	$cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];			
	$price = lookup($_POST["symbol"])["price"];
	$stockprice = $_POST["shares"] * $price;
	
	if ($cash - $stockprice > 0)
	{
		query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"],$_POST["symbol"], $_POST["shares"], $_POST["shares"]);
	
		query("UPDATE users SET cash = cash - ? WHERE id = ?", $stockprice, $_SESSION["id"]);

		query("INSERT INTO history (id, transactions, dateandtime, symbol, price, shares) VALUES(?, 'BUY', NOW(), ?, ?, ?)", $_SESSION["id"],$_POST["symbol"], $price, $_POST["shares"]);
		
		redirect("/");
	}

	else
	{
		apologize("Not enough cash!");
	}
    }
    
    else
    {
	render("buy_form.php", ["title" => "Sell"]);
    }

?>
