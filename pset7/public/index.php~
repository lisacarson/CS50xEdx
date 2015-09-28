<?php

    // configuration
    require("../includes/config.php"); 
$positions = [];
$rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
$cash = number_format(query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"], 2);
foreach ($rows as $row)
{
    $stock = lookup($row["symbol"]);
    if ($stock !== false)
    {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"]
        ];
    }
}
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => $cash]);
   

?>
