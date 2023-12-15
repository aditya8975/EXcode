<html>
<head>
<title>Electricity Bill</title>
</head>
<?php
$result_str = $result = '';
if (isset($_POST['submit'])) {
$units = $_POST['units'];
if (!empty($units)) {
$result = calculate_bill($units);
$result_str = 'Total amount of ' . $units . ' - ' . $result;
}
}
function calculate_bill($units) {
$first = 3.50;
$second = 4.00;
$third = 5.20;
$fourth = 6.50;
if($units <= 50) {
$bill = $units * $first;
}
else if($units > 50 && $units <= 100) {
$temp = 50 * $first;
$remaining_units = $units - 50;
$bill = $temp + ($remaining_units * $second);
}
else if($units > 100 && $units <= 200) {
$temp = (50 * 3.5) + (100 * $second);
$remaining_units = $units - 150;
$bill = $temp + ($remaining_units * $third);
}

else {
$temp = (50 * 3.5) + (100 * $second) + (100 * $third);
$remaining_units = $units - 250;
$bill = $temp + ($remaining_units * $fourth);
}
return number_format((float)$bill, 2, '.', '');
}
?>
<body>
<div >
<h1>Php - Calculate Electricity Bill</h1>
<form action="" method="post" >
<input type="number" name="units" id="units"

placeholder="Enter no of Units" />

<input type="submit" name="submit" id="submit"

value="Calculate" />
</form>
<div>
<?php echo '<br />' . $result_str; ?>
</div>
</div>
</body>
</html>