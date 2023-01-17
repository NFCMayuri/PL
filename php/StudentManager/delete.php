<?php
$db_host = "localhost";
$db_username = "root";
$db_password = "root";
$db_name = "tang";
$table_name = "user";
$conn = mysqli_connect($db_host, $db_username, $db_password);
mysqli_select_db($conn, $db_name);
$sql = "DELETE from " . $table_name . " WHERE id = " . $_GET["id"] . ";";
$result = mysqli_query($conn, $sql);
if (!$result) {
    echo "ERROR:" . mysqli_error($conn);
} else {
    echo "删除成功";

}
header("Refresh:2;url=index.php");

?>