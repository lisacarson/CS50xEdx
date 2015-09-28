<?php

	if ($stock == true)
	{
		print("Price: " . number_format($stock["price"], 3));
	}	
	else
	{
		print("Not a valid stock symbol!");
	} 




?>
<div>
    <a href="index.php">Back</a> to portfolio.
</div>
