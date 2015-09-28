<div class="nav-justified nav-tabs"> 
  <ul class="nav nav-pills">
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
    <li><a href="change.php"><strong>Change Password</strong></a></li>
</ul>
</div>

<table class="table table-striped table-bordered">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Price</th>
	    <th>Shares</th>
            
        </tr>
    </thead>
    <tbody>   
  <?php foreach ($histories as $history): ?>
    
    <tr>
        <td><?= $history["transactions"] ?></td>
	<td><?= $history["dateandtime"] ?></td>
        <td><?= strtoupper($history["symbol"]) ?></td>
        <td><?= number_format($history["price"], 2) ?></td>
	<td><?= $history["shares"]?></td>
	
    </tr>
    
<?php endforeach ?>
    </tbody>
</table>
	
<div>
    <a href="logout.php">Log Out</a>
</div>
