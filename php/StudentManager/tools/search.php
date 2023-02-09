<?php
if ($_POST["id"] == "" && $_POST["name"] == "" && $_POST["sex"] == "" && $_POST["class"] == "") {
    echo "请至少填写一个！";
    header("Refresh:2;url=../index.php");
} else {
    $db_host = "localhost";
    $db_username = "root";
    $db_password = "root";
    $db_name = "tang";
    $table_name = "user";
    $conn = mysqli_connect($db_host, $db_username, $db_password);
    mysqli_select_db($conn, $db_name);
    $sql = "SELECT * from `" . $table_name . "` WHERE 1";
    if ($_POST["id"] != "") {
        $sql .= " and `id`=" . $_POST["id"];
    }
    if ($_POST["name"] != "") {
        $sql .= " and `name`=\"" . $_POST["name"] . "\"";
    }
    if ($_POST["sex"] != "") {
        $sql .= " and `sex`=\"" . $_POST["sex"] . "\"";
    }
    if ($_POST["class"] != "") {
        $sql .= " and `class`=\"" . $_POST["class"] . "\"";
    }
    $sql .= ";";
    // echo $sql . "<br>";
    $result = mysqli_query($conn, $sql);
    if (!$result) {
        die("ERROR:" . mysqli_error($conn));
    }
    echo "<table border=1>";
    while ($item = mysqli_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td>";
        echo $item["id"];
        echo "</td>";
        echo "<td>";
        echo $item["name"];
        echo "</td>";
        echo "<td>";
        echo $item["sex"];
        echo "</td>";
        echo "<td>";
        echo $item["class"];
        echo "</td>";
        echo "<td>";
        echo "<button> <a href=\"tools/delete.php?id=" . $item["id"] . "\">删除</a></button>";
        echo "<button> <a href=\"tools/modify_ui.php?id=" . $item["id"] . "&&sex=" . $item["sex"] . "&&name=" . $item["name"] . "&&class=" . $item["class"] . "\">修改</a></button>";
        echo "</td>";
        echo "</tr>";
    }
    echo "</table>";
}