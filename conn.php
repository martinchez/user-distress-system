<!DOCTYPE html>
<html>

<head>
	<title>Insert Page page</title>
</head>

<body>
	<center>
		<?php

		// servername => localhost
		// username => root
		// password => empty
		// database name => staff
    $conn = mysqli_connect('localhost', 'root', '','uds');
		
		// Check connection
		if($conn === false){
			die("ERROR: Could not connect. "
				. mysqli_connect_error());
		}
		
		// Taking all 5 values from the form data(input)
    $txtSerial = $_REQUEST['serial_no'];
    $txtName = $_REQUEST['name'];
    $txtAge = $_REQUEST['age'];
    $txtGender = $_REQUEST['gender'];
    $txtAddress =$_REQUEST['address'];
    $txtPhone = $_REQUEST['phone'];
    
		
		// Performing insert query execution
		// here our table name is college
		$sql = "INSERT INTO `registration` (`id`, `serialno`, `name`, `age`, `gender`, `address`, `phone`) VALUES ('0', '$txtSerial', '$txtName', '$txtAge', '$txtGender', '$txtAddress', '$txtPhone')";

		if(mysqli_query($conn, $sql)){
			echo "<h3>dEVICE SUCCESSFULY REGISTERED GO BACK TO REGISTER ANOTHER DEVICE</h3>";

			echo nl2br("\n$txtSerial\n $txtName\n "
				. "$txtAge\n $txtGender\n $txtAddress\n $txtPhone");
		} else{
			echo "ERROR: Hush! Sorry $sql. "
				. mysqli_error($conn);
		}
		
		// Close connection
		mysqli_close($conn);
		?>
	</center>
</body>

</html>
