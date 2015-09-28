<?php

    // configuration
    require("../includes/config.php");

    
       
    

    // else if user reached page via POST (as by submitting a form via POST)
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
	if (empty($_POST["password"]) || empty($_POST["confirmation"]) || $_POST["password"] !== $_POST["confirmation"])
        {
		apologize("You must enter a valid password");
        }
	 
	else
	{        
		query("UPDATE users SET hash = ? WHERE id = ?",crypt($_POST["password"]), $_SESSION["id"]);      			    			redirect("/");	
	}
    }

    else
    {	
 	// else render form
        render("change_form.php", ["title" => "Register"]);
    }

?>
