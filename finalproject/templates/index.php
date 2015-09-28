<?php 
$url = 'http://free.rome2rio.com/api/1.2/json/Search?key=vwiC3pvW&oName={$_POST["From"]}&dName={$_POST["To"]}';
$content = file_get_contents($url);
$json = json_decode($content, true);
?>

<html>
<head>
<style>
section {height:500px; width:1000px; color:red;}
</style>


</head>
<body> 
<section>

<?php

	$iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($json));
foreach($iterator as $key => $value) {
    echo "<p>$key => $value</p>";
}
 ?>
 
</section>
</body>
<
