<?php
if ($_POST["id"] == "" || $_POST["name"] == "" || ($_POST["sex"] != "male" && $_POST["sex"] != "female") || $_POST["class"] == "") {
    echo "请正确填写完整！";
    header("Refresh:2;url=index.php");
} else {
    $db_host = "localhost";
    $db_username = "root";
    $db_password = "root";
    $db_name = "tang";
    $table_name = "user";
    $conn = mysqli_connect($db_host, $db_username, $db_password);
    mysqli_select_db($conn, $db_name);
    $sql = "UPDATE `" . $table_name . "` SET `name`=\"" . addslashes($_POST["name"]) . "\", `sex`=\"" . $_POST["sex"] . "\", `class`=\"" . $_POST["class"] . "\" WHERE `id`=" . $_POST["id"] . ";";
    // echo $sql . "<br>";
    $result = mysqli_multi_query($conn, $sql);
    if (!$result) {
        echo "ERROR:" . mysqli_error($conn);
    } else {
        echo "修改成功";

    }
}
header("Refresh:2;url=index.php");

?>